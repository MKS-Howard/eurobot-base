#include <include/generated/autoconf.h>
#ifdef CONFIG_LIBCOCOBOT_LOADER

#include <cocobot.h>
#ifdef CONFIG_OS_USE_FREERTOS
# include <FreeRTOS.h>
# include <task.h>
#else
# include <malloc_wrapper.h>
#endif
#include <mcual.h>
#include <platform.h>
#include "../com/dsdl/uavcan/protocol/GetNodeInfo.h"
#include "../com/dsdl/uavcan/protocol/file/BeginFirmwareUpdate.h"
#include "../com/dsdl/uavcan/protocol/file/Read.h"


typedef enum {
  LOADER_MODE_IDLE,
  LOADER_MODE_PRELOADING,
  LOADER_MODE_LOADING,
} loader_mode_t;

static loader_mode_t _mode;
static uint8_t _request_id;
static uint8_t  _src_node_id;
static uint64_t _offset;
static uint8_t _read_transfer_id;
static uint64_t _timestamp_us;
static uint64_t _last_activity_us;

static void cocobot_loader_read(void)
{
  //fill the struct
  uavcan_protocol_file_ReadRequest rr;
  rr.offset = _offset;
  rr.path.path.len = 0;
  rr.path.path.data = NULL;

  //request flash memory if we have enough RAM
  void * buf = pvPortMalloc(UAVCAN_PROTOCOL_FILE_READ_REQUEST_MAX_SIZE); 
  if(buf != NULL) {
    const int size = uavcan_protocol_file_ReadRequest_encode(&rr, buf);
    cocobot_com_request_or_respond(_src_node_id,
                                   UAVCAN_PROTOCOL_FILE_READ_SIGNATURE,
                                   UAVCAN_PROTOCOL_FILE_READ_ID,
                                   &_read_transfer_id,
                                   CANARD_TRANSFER_PRIORITY_MEDIUM,
                                   CanardRequest,
                                   buf,
                                   (uint16_t)size);
    vPortFree(buf);
  }
}

uint8_t cocobot_loader_should_accept_transfer(uint64_t* out_data_type_signature,
                                              uint16_t data_type_id,
                                              CanardTransferType transfer_type,
                                              uint8_t source_node_id)
{
  (void)out_data_type_signature;
  (void)data_type_id;
  (void)transfer_type;
  (void)source_node_id;
  
  //Always accept Begin Firmware Update
  if ((transfer_type == CanardTransferTypeRequest) &&
      (data_type_id == UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_ID))
  {
    *out_data_type_signature = UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_SIGNATURE;
    return true;
  }

  //Accept Read file in loading mode only
  if ((transfer_type == CanardTransferTypeResponse) &&
      (data_type_id == UAVCAN_PROTOCOL_FILE_READ_ID) &&
      (_mode == LOADER_MODE_LOADING))
  {
    *out_data_type_signature = UAVCAN_PROTOCOL_FILE_READ_SIGNATURE;
    return true;
  }

  return false;
}

uint8_t cocobot_loader_on_transfer_received(CanardRxTransfer* transfer)
{
  if ((transfer->transfer_type == CanardTransferTypeRequest) &&
      (transfer->data_type_id == UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_ID))
  {
    uavcan_protocol_file_BeginFirmwareUpdateResponse bfu; 
    void * dynbuf = NULL;

    bfu.optional_error_message.len = 0;
    bfu.optional_error_message.data = NULL;

    if(_mode == LOADER_MODE_IDLE)
    {
      _mode = LOADER_MODE_PRELOADING;
      bfu.error = UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_OK;
    }
    else
    {
      //bootloader already in progress. Abort begin request
      bfu.error = UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_IN_PROGRESS;
    }

    //release rx memory before tx
    cocobot_com_release_rx_transfer_payload(transfer);

    //send response if we have enough free memory 
    void * buf = pvPortMalloc(UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_MAX_SIZE); 
    if(buf != NULL) 
    {
      const uint32_t size = uavcan_protocol_file_BeginFirmwareUpdateResponse_encode(&bfu, buf);
      cocobot_com_request_or_respond(transfer->source_node_id,
                                     UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_SIGNATURE,
                                     UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_ID,
                                     &transfer->transfer_id,
                                     transfer->priority,
                                     CanardResponse,
                                     buf,
                                     (uint16_t)size);
      vPortFree(buf);

    }

    if(_mode == LOADER_MODE_PRELOADING)
    {
      //We are ready ! Time to announce it to everybody
      _mode = LOADER_MODE_LOADING;
      _last_activity_us = _timestamp_us;
      cocobot_com_set_mode(UAVCAN_PROTOCOL_NODESTATUS_MODE_SOFTWARE_UPDATE);
      cocobot_com_flush();
      _offset = 0;
      _src_node_id = transfer->source_node_id;

      mcual_loader_erase_pgm();
 
      //start reading
      cocobot_loader_read();
    }

    //free memory
    if(dynbuf != NULL)
    {
       vPortFree(dynbuf);
    }

    return 1;
  }

  if ((transfer->transfer_type == CanardTransferTypeResponse) &&
      (transfer->data_type_id == UAVCAN_PROTOCOL_FILE_READ_ID) &&
      (_mode == LOADER_MODE_LOADING))
  {
    uavcan_protocol_file_ReadResponse read; 
    void * dynbuf = NULL;

    //get file bytes
    dynbuf = pvPortMalloc(UAVCAN_PROTOCOL_FILE_READ_RESPONSE_MAX_SIZE);
    if(dynbuf != NULL)
    {
      uint8_t * pdynbuf = dynbuf;
      if(uavcan_protocol_file_ReadResponse_decode(transfer, transfer->payload_len, &read, &pdynbuf) >= 0)
      {
        //release rx memory before tx
        cocobot_com_release_rx_transfer_payload(transfer);

        if(read.error.value == 0)
        {
          mcual_loader_flash_pgm(_offset, read.data.data, read.data.len);

          if(read.data.len < UAVCAN_PROTOCOL_FILE_READ_RESPONSE_DATA_MAX_LENGTH)
          {
            //ended !
            mcual_loader_boot();
          }
          else
          {
            //read next bytes
            _offset += UAVCAN_PROTOCOL_FILE_READ_RESPONSE_DATA_MAX_LENGTH;
            cocobot_loader_read();
            _last_activity_us = _timestamp_us;
          }
        }
        else
        {
          //File error. Abort
          _mode = LOADER_MODE_IDLE;
          cocobot_com_set_mode(UAVCAN_PROTOCOL_NODESTATUS_MODE_MAINTENANCE);
        }
      }
    }

    //free memory
    if(dynbuf != NULL)
    {
      vPortFree(dynbuf);
    }

    return 1;
  }

  return 0;
}

void cocobot_loader_init(void)
{
  //init static memory
  _mode = LOADER_MODE_IDLE;
  _request_id = 0;
  _offset = 0;
  _src_node_id = 0;
  _last_activity_us = 0;

  //set node status as MAINTENANCE (bootloader running but reflash is not in progress)
  cocobot_com_set_mode(UAVCAN_PROTOCOL_NODESTATUS_MODE_MAINTENANCE);

#ifdef CONFIG_OS_USE_FREERTOS
#else
  for(;;)
  {
    _timestamp_us = cocobot_com_process_event();

    if(_mode != LOADER_MODE_IDLE)
    {
      if(_timestamp_us - _last_activity_us > 1000000UL)
      {
          _last_activity_us = _timestamp_us;
          cocobot_loader_read();
      }
    }
    else
    {
      //2s and no request -> start pgm
      if(_timestamp_us > 2000000)
      {
        mcual_loader_boot();
      }
    }
  }
#endif
}

#endif

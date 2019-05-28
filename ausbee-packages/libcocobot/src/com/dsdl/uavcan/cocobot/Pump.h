/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/206.Pump.uavcan
 */

#ifndef __UAVCAN_COCOBOT_PUMP
#define __UAVCAN_COCOBOT_PUMP

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
uint8 pump_id
uint8 action

---
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.Pump
saturated uint8 pump_id
saturated uint8 action
---
******************************************************************************/

#define UAVCAN_COCOBOT_PUMP_ID                             206
#define UAVCAN_COCOBOT_PUMP_NAME                           "uavcan.cocobot.Pump"
#define UAVCAN_COCOBOT_PUMP_SIGNATURE                      (0x24DFD40F63AE7616ULL)

#define UAVCAN_COCOBOT_PUMP_REQUEST_MAX_SIZE               ((16 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    pump_id;                       // bit len 8
    uint8_t    action;                        // bit len 8

} uavcan_cocobot_PumpRequest;

extern
uint32_t uavcan_cocobot_PumpRequest_encode(uavcan_cocobot_PumpRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_PumpRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_PumpRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_PumpRequest_encode_internal(uavcan_cocobot_PumpRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_PumpRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_PumpRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_PUMP_RESPONSE_MAX_SIZE              ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_cocobot_PumpResponse;

extern
uint32_t uavcan_cocobot_PumpResponse_encode(uavcan_cocobot_PumpResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_PumpResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_PumpResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_PumpResponse_encode_internal(uavcan_cocobot_PumpResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_PumpResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_PumpResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_PUMP
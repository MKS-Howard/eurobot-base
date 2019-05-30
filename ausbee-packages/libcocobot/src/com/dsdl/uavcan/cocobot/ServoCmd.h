/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/205.ServoCmd.uavcan
 */

#ifndef __UAVCAN_COCOBOT_SERVOCMD
#define __UAVCAN_COCOBOT_SERVOCMD

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
uint8 mode
uint8 servo_id
int16 value

---
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.ServoCmd
saturated uint8 mode
saturated uint8 servo_id
saturated int16 value
---
******************************************************************************/

#define UAVCAN_COCOBOT_SERVOCMD_ID                         205
#define UAVCAN_COCOBOT_SERVOCMD_NAME                       "uavcan.cocobot.ServoCmd"
#define UAVCAN_COCOBOT_SERVOCMD_SIGNATURE                  (0x434E067A57A687A9ULL)

#define UAVCAN_COCOBOT_SERVOCMD_REQUEST_MAX_SIZE           ((32 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    mode;                          // bit len 8
    uint8_t    servo_id;                      // bit len 8
    int16_t    value;                         // bit len 16

} uavcan_cocobot_ServoCmdRequest;

extern
uint32_t uavcan_cocobot_ServoCmdRequest_encode(uavcan_cocobot_ServoCmdRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_ServoCmdRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_ServoCmdRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_ServoCmdRequest_encode_internal(uavcan_cocobot_ServoCmdRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_ServoCmdRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_ServoCmdRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_SERVOCMD_RESPONSE_MAX_SIZE          ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_cocobot_ServoCmdResponse;

extern
uint32_t uavcan_cocobot_ServoCmdResponse_encode(uavcan_cocobot_ServoCmdResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_ServoCmdResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_ServoCmdResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_ServoCmdResponse_encode_internal(uavcan_cocobot_ServoCmdResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_ServoCmdResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_ServoCmdResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_SERVOCMD
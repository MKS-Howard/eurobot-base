/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/202.SetMotorSpeed.uavcan
 */

#ifndef __UAVCAN_COCOBOT_SETMOTORSPEED
#define __UAVCAN_COCOBOT_SETMOTORSPEED

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
bool enable
float32 rpm
---
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.SetMotorSpeed
saturated bool enable
saturated float32 rpm
---
******************************************************************************/

#define UAVCAN_COCOBOT_SETMOTORSPEED_ID                    202
#define UAVCAN_COCOBOT_SETMOTORSPEED_NAME                  "uavcan.cocobot.SetMotorSpeed"
#define UAVCAN_COCOBOT_SETMOTORSPEED_SIGNATURE             (0x8AC3FA85A1E8D9B2ULL)

#define UAVCAN_COCOBOT_SETMOTORSPEED_REQUEST_MAX_SIZE      ((33 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    bool       enable;                        // bit len 1
    float      rpm;                           // float32 Saturate

} uavcan_cocobot_SetMotorSpeedRequest;

extern
uint32_t uavcan_cocobot_SetMotorSpeedRequest_encode(uavcan_cocobot_SetMotorSpeedRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_SetMotorSpeedRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_SetMotorSpeedRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_SetMotorSpeedRequest_encode_internal(uavcan_cocobot_SetMotorSpeedRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_SetMotorSpeedRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_SetMotorSpeedRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_SETMOTORSPEED_RESPONSE_MAX_SIZE     ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_cocobot_SetMotorSpeedResponse;

extern
uint32_t uavcan_cocobot_SetMotorSpeedResponse_encode(uavcan_cocobot_SetMotorSpeedResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_SetMotorSpeedResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_SetMotorSpeedResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_SetMotorSpeedResponse_encode_internal(uavcan_cocobot_SetMotorSpeedResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_SetMotorSpeedResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_SetMotorSpeedResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_SETMOTORSPEED
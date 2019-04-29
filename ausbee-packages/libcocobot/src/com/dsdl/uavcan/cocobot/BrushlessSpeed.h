/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/201.BrushlessSpeed.uavcan
 */

#ifndef __UAVCAN_COCOBOT_BRUSHLESSSPEED
#define __UAVCAN_COCOBOT_BRUSHLESSSPEED

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
---

float32 rpm
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.BrushlessSpeed
---
saturated float32 rpm
******************************************************************************/

#define UAVCAN_COCOBOT_BRUSHLESSSPEED_ID                   201
#define UAVCAN_COCOBOT_BRUSHLESSSPEED_NAME                 "uavcan.cocobot.BrushlessSpeed"
#define UAVCAN_COCOBOT_BRUSHLESSSPEED_SIGNATURE            (0x899E3A6A27481686ULL)

#define UAVCAN_COCOBOT_BRUSHLESSSPEED_REQUEST_MAX_SIZE     ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_cocobot_BrushlessSpeedRequest;

extern
uint32_t uavcan_cocobot_BrushlessSpeedRequest_encode(uavcan_cocobot_BrushlessSpeedRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_BrushlessSpeedRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessSpeedRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_BrushlessSpeedRequest_encode_internal(uavcan_cocobot_BrushlessSpeedRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_BrushlessSpeedRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessSpeedRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_BRUSHLESSSPEED_RESPONSE_MAX_SIZE    ((32 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      rpm;                           // float32 Saturate

} uavcan_cocobot_BrushlessSpeedResponse;

extern
uint32_t uavcan_cocobot_BrushlessSpeedResponse_encode(uavcan_cocobot_BrushlessSpeedResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_BrushlessSpeedResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessSpeedResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_BrushlessSpeedResponse_encode_internal(uavcan_cocobot_BrushlessSpeedResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_BrushlessSpeedResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessSpeedResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_BRUSHLESSSPEED
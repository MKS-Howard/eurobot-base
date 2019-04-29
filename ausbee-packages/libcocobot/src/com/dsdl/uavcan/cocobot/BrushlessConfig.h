/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/200.BrushlessConfig.uavcan
 */

#ifndef __UAVCAN_COCOBOT_BRUSHLESSCONFIG
#define __UAVCAN_COCOBOT_BRUSHLESSCONFIG

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
---

float32 kp
float32 ki
float32 imax
float32 max_speed_rpm
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.BrushlessConfig
---
saturated float32 kp
saturated float32 ki
saturated float32 imax
saturated float32 max_speed_rpm
******************************************************************************/

#define UAVCAN_COCOBOT_BRUSHLESSCONFIG_ID                  200
#define UAVCAN_COCOBOT_BRUSHLESSCONFIG_NAME                "uavcan.cocobot.BrushlessConfig"
#define UAVCAN_COCOBOT_BRUSHLESSCONFIG_SIGNATURE           (0xAB683D4592946F14ULL)

#define UAVCAN_COCOBOT_BRUSHLESSCONFIG_REQUEST_MAX_SIZE    ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_cocobot_BrushlessConfigRequest;

extern
uint32_t uavcan_cocobot_BrushlessConfigRequest_encode(uavcan_cocobot_BrushlessConfigRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_BrushlessConfigRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessConfigRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_BrushlessConfigRequest_encode_internal(uavcan_cocobot_BrushlessConfigRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_BrushlessConfigRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessConfigRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_BRUSHLESSCONFIG_RESPONSE_MAX_SIZE   ((128 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      kp;                            // float32 Saturate
    float      ki;                            // float32 Saturate
    float      imax;                          // float32 Saturate
    float      max_speed_rpm;                 // float32 Saturate

} uavcan_cocobot_BrushlessConfigResponse;

extern
uint32_t uavcan_cocobot_BrushlessConfigResponse_encode(uavcan_cocobot_BrushlessConfigResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_BrushlessConfigResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessConfigResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_BrushlessConfigResponse_encode_internal(uavcan_cocobot_BrushlessConfigResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_BrushlessConfigResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_BrushlessConfigResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_BRUSHLESSCONFIG
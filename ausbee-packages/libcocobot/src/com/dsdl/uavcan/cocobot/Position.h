/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/20000.Position.uavcan
 */

#ifndef __UAVCAN_COCOBOT_POSITION
#define __UAVCAN_COCOBOT_POSITION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
float32 x
float32 y
float32 a
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.Position
saturated float32 x
saturated float32 y
saturated float32 a
******************************************************************************/

#define UAVCAN_COCOBOT_POSITION_ID                         20000
#define UAVCAN_COCOBOT_POSITION_NAME                       "uavcan.cocobot.Position"
#define UAVCAN_COCOBOT_POSITION_SIGNATURE                  (0x219A579968238A2FULL)

#define UAVCAN_COCOBOT_POSITION_MAX_SIZE                   ((96 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      x;                             // float32 Saturate
    float      y;                             // float32 Saturate
    float      a;                             // float32 Saturate

} uavcan_cocobot_Position;

extern
uint32_t uavcan_cocobot_Position_encode(uavcan_cocobot_Position* source, void* msg_buf);

extern
int32_t uavcan_cocobot_Position_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_Position* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_Position_encode_internal(uavcan_cocobot_Position* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_Position_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_Position* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_POSITION
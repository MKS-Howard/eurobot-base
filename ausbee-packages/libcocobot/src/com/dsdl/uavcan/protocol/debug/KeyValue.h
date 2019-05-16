/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/protocol/debug/16370.KeyValue.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DEBUG_KEYVALUE
#define __UAVCAN_PROTOCOL_DEBUG_KEYVALUE

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Generic named parameter (key/value pair).
#

#
# Integers are exactly representable in the range (-2^24, 2^24) which is (-16'777'216, 16'777'216).
#
float32 value

#
# Tail array optimization is enabled, so if key length does not exceed 3 characters, the whole
# message can fit into one CAN frame. The message always fits into one CAN FD frame.
#
uint8[<=58] key
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.debug.KeyValue
saturated float32 value
saturated uint8[<=58] key
******************************************************************************/

#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID                  16370
#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_NAME                "uavcan.protocol.debug.KeyValue"
#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_SIGNATURE           (0xE02F25D6E0C98AE0ULL)

#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_MAX_SIZE            ((502 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_KEY_MAX_LENGTH                                    58

typedef struct
{
    // FieldTypes
    float      value;                         // float32 Saturate
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[58] max items
    } key;

} uavcan_protocol_debug_KeyValue;

extern
uint32_t uavcan_protocol_debug_KeyValue_encode(uavcan_protocol_debug_KeyValue* source, void* msg_buf);

extern
int32_t uavcan_protocol_debug_KeyValue_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_KeyValue* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_debug_KeyValue_encode_internal(uavcan_protocol_debug_KeyValue* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_debug_KeyValue_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_KeyValue* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DEBUG_KEYVALUE
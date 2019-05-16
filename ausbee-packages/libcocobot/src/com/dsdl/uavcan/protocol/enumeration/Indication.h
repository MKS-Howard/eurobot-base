/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/protocol/enumeration/380.Indication.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_ENUMERATION_INDICATION
#define __UAVCAN_PROTOCOL_ENUMERATION_INDICATION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/param/NumericValue.h>

/******************************* Source text **********************************
#
# This message will be broadcasted when the node receives user input in the process of enumeration.
#

void6

#
# This field is unused; keep it empty
#
uavcan.protocol.param.NumericValue value

#
# Name of the enumerated parameter.
# This field must always be populated by the enumeratee.
# If multiple parameters were enumerated at once (e.g. ESC index and the direction of rotation),
# the field should contain the name of the most important parameter.
#
uint8[<=92] parameter_name
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.enumeration.Indication
void6
uavcan.protocol.param.NumericValue value
saturated uint8[<=92] parameter_name
******************************************************************************/

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_ID          380
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_NAME        "uavcan.protocol.enumeration.Indication"
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_SIGNATURE   (0x884CB63050A84F35ULL)

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_MAX_SIZE    ((815 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_PARAMETER_NAME_MAX_LENGTH                 92

typedef struct
{
    // FieldTypes
    // void6
    uavcan_protocol_param_NumericValue value;                         //
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[92] max items
    } parameter_name;

} uavcan_protocol_enumeration_Indication;

extern
uint32_t uavcan_protocol_enumeration_Indication_encode(uavcan_protocol_enumeration_Indication* source, void* msg_buf);

extern
int32_t uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_Indication* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_enumeration_Indication_encode_internal(uavcan_protocol_enumeration_Indication* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_enumeration_Indication_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_Indication* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_ENUMERATION_INDICATION
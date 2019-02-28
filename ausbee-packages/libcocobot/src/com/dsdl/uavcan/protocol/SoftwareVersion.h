/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/rcocobot/ausbee-packages/libcocobot/dsdl/uavcan/protocol/SoftwareVersion.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_SOFTWAREVERSION
#define __UAVCAN_PROTOCOL_SOFTWAREVERSION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Nested type.
# Generic software version information.
#

#
# Primary version numbers.
# If both fields are set to zero, the version is considered unknown.
#
uint8 major
uint8 minor

#
# This mask indicates which optional fields (see below) are set.
#
uint8 OPTIONAL_FIELD_FLAG_VCS_COMMIT = 1
uint8 OPTIONAL_FIELD_FLAG_IMAGE_CRC  = 2
uint8 optional_field_flags

#
# VCS commit hash or revision number, e.g. git short commit hash. Optional.
#
uint32 vcs_commit

#
# The value of an arbitrary hash function applied to the firmware image.
# This field is used to detect whether the firmware running on the node is EXACTLY THE SAME
# as a certain specific revision. This field provides the absolute identity guarantee, unlike
# the version fields above, which can be the same for different builds of the firmware.
#
# The exact hash function and the methods of its application are implementation defined.
# However, implementations are recommended to adhere to the following guidelines,
# fully or partially:
#
#   - The hash function should be CRC-64-WE, the same that is used for computing DSDL signatures.
#
#   - The hash function should be applied to the entire application image padded to 8 bytes.
#
#   - If the computed image CRC is stored within the firmware image itself, the value of
#     the hash function becomes ill-defined, because it becomes recursively dependent on itself.
#     In order to circumvent this issue, while computing or checking the CRC, its value stored
#     within the image should be zeroed out.
#
uint64 image_crc
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.SoftwareVersion
saturated uint8 major
saturated uint8 minor
saturated uint8 optional_field_flags
saturated uint32 vcs_commit
saturated uint64 image_crc
******************************************************************************/

#define UAVCAN_PROTOCOL_SOFTWAREVERSION_NAME               "uavcan.protocol.SoftwareVersion"
#define UAVCAN_PROTOCOL_SOFTWAREVERSION_SIGNATURE          (0xDD46FD376527FEA1ULL)

#define UAVCAN_PROTOCOL_SOFTWAREVERSION_MAX_SIZE           ((120 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_SOFTWAREVERSION_OPTIONAL_FIELD_FLAG_VCS_COMMIT          1 // 1
#define UAVCAN_PROTOCOL_SOFTWAREVERSION_OPTIONAL_FIELD_FLAG_IMAGE_CRC          2 // 2

typedef struct
{
    // FieldTypes
    uint8_t    major;                         // bit len 8
    uint8_t    minor;                         // bit len 8
    uint8_t    optional_field_flags;          // bit len 8
    uint32_t   vcs_commit;                    // bit len 32
    uint64_t   image_crc;                     // bit len 64

} uavcan_protocol_SoftwareVersion;

extern
uint32_t uavcan_protocol_SoftwareVersion_encode(uavcan_protocol_SoftwareVersion* source, void* msg_buf);

extern
int32_t uavcan_protocol_SoftwareVersion_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_SoftwareVersion* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_SoftwareVersion_encode_internal(uavcan_protocol_SoftwareVersion* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_SoftwareVersion_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_SoftwareVersion* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_SOFTWAREVERSION
/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/protocol/4.GetTransportStats.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_GETTRANSPORTSTATS
#define __UAVCAN_PROTOCOL_GETTRANSPORTSTATS

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/CANIfaceStats.h>

/******************************* Source text **********************************
#
# Get transport statistics.
#

---

#
# UAVCAN transport layer statistics.
#
uint48 transfers_tx             # Number of transmitted transfers.
uint48 transfers_rx             # Number of received transfers.
uint48 transfer_errors          # Number of errors detected in the UAVCAN transport layer.

#
# CAN bus statistics, for each interface independently.
#
CANIfaceStats[<=3] can_iface_stats
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.GetTransportStats
---
saturated uint48 transfers_tx
saturated uint48 transfers_rx
saturated uint48 transfer_errors
uavcan.protocol.CANIfaceStats[<=3] can_iface_stats
******************************************************************************/

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_ID               4
#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_NAME             "uavcan.protocol.GetTransportStats"
#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_SIGNATURE        (0xBE6F76A7EC312B04ULL)

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_REQUEST_MAX_SIZE ((0 + 7)/8)

typedef struct
{
    uint8_t empty;
} uavcan_protocol_GetTransportStatsRequest;

extern
uint32_t uavcan_protocol_GetTransportStatsRequest_encode(uavcan_protocol_GetTransportStatsRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_GetTransportStatsRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GetTransportStatsRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_GetTransportStatsRequest_encode_internal(uavcan_protocol_GetTransportStatsRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_GetTransportStatsRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GetTransportStatsRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_RESPONSE_MAX_SIZE ((578 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_RESPONSE_CAN_IFACE_STATS_MAX_LENGTH            3

typedef struct
{
    // FieldTypes
    uint64_t   transfers_tx;                  // bit len 48
    uint64_t   transfers_rx;                  // bit len 48
    uint64_t   transfer_errors;               // bit len 48
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uavcan_protocol_CANIfaceStats* data;                      // Dynamic Array 144bit[3] max items
    } can_iface_stats;

} uavcan_protocol_GetTransportStatsResponse;

extern
uint32_t uavcan_protocol_GetTransportStatsResponse_encode(uavcan_protocol_GetTransportStatsResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_GetTransportStatsResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GetTransportStatsResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_GetTransportStatsResponse_encode_internal(uavcan_protocol_GetTransportStatsResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_GetTransportStatsResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GetTransportStatsResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_GETTRANSPORTSTATS
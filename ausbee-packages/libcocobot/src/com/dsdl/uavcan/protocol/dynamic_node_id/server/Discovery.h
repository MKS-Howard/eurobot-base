/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/protocol/dynamic_node_id/server/390.Discovery.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY
#define __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# THIS DEFINITION IS SUBJECT TO CHANGE.
#
# This message is used by allocation servers to find each other's node ID.
# Please refer to the specification for details.
#
# A server should stop publishing this message as soon as it has discovered all other nodes in the cluster.
#
# An exception applies: when a server receives a Discovery message from another server where the list
# of known nodes is incomplete (i.e. len(known_nodes) < configured_cluster_size), the server must
# publish a discovery message once. This condition allows other servers to quickly re-discover the cluster
# after restart.
#

#
# This message should be broadcasted by the server at this interval until all other servers are discovered.
#
uint16 BROADCASTING_PERIOD_MS = 1000

#
# Number of servers in the cluster as configured on the sender.
#
uint8 configured_cluster_size

#
# Node ID of servers that are known to the publishing server, including the publishing server itself.
# Capacity of this array defines maximum size of the server cluster.
#
uint8[<=5] known_nodes
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.dynamic_node_id.server.Discovery
saturated uint8 configured_cluster_size
saturated uint8[<=5] known_nodes
******************************************************************************/

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_ID 390
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_NAME "uavcan.protocol.dynamic_node_id.server.Discovery"
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_SIGNATURE (0x821AE2F525F69F21ULL)

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_MAX_SIZE ((51 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_BROADCASTING_PERIOD_MS       1000 // 1000

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY_KNOWN_NODES_MAX_LENGTH          5

typedef struct
{
    // FieldTypes
    uint8_t    configured_cluster_size;       // bit len 8
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[5] max items
    } known_nodes;

} uavcan_protocol_dynamic_node_id_server_Discovery;

extern
uint32_t uavcan_protocol_dynamic_node_id_server_Discovery_encode(uavcan_protocol_dynamic_node_id_server_Discovery* source, void* msg_buf);

extern
int32_t uavcan_protocol_dynamic_node_id_server_Discovery_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_Discovery* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_dynamic_node_id_server_Discovery_encode_internal(uavcan_protocol_dynamic_node_id_server_Discovery* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_dynamic_node_id_server_Discovery_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_Discovery* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_DISCOVERY
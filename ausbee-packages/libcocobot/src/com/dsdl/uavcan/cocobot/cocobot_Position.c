/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/20000.Position.uavcan
 */
#include "uavcan/cocobot/Position.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#ifndef CANARD_INTERNAL_SATURATE_UNSIGNED
#define CANARD_INTERNAL_SATURATE_UNSIGNED(x, max) ( ((x) >= max) ? max : (x) );
#endif

#if defined(__GNUC__)
# define CANARD_MAYBE_UNUSED(x) x __attribute__((unused))
#else
# define CANARD_MAYBE_UNUSED(x) x
#endif

/**
  * @brief uavcan_cocobot_Position_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_cocobot_Position_encode_internal(uavcan_cocobot_Position* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->x); // 2147483647
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->y); // 2147483647
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->a); // 2147483647
    offset += 32;

    return offset;
}

/**
  * @brief uavcan_cocobot_Position_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_cocobot_Position_encode(uavcan_cocobot_Position* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_cocobot_Position_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_cocobot_Position_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_cocobot_Position dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_cocobot_Position_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_cocobot_Position* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->x);
    if (ret != 32)
    {
        goto uavcan_cocobot_Position_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->y);
    if (ret != 32)
    {
        goto uavcan_cocobot_Position_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->a);
    if (ret != 32)
    {
        goto uavcan_cocobot_Position_error_exit;
    }
    offset += 32;
    return offset;

uavcan_cocobot_Position_error_exit:
    if (ret < 0)
    {
        return ret;
    }
    else
    {
        return -CANARD_ERROR_INTERNAL;
    }
}

/**
  * @brief uavcan_cocobot_Position_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_cocobot_Position dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_cocobot_Position_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_cocobot_Position* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_cocobot_Position); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_cocobot_Position_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

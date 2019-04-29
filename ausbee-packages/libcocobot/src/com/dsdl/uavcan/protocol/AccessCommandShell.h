/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/protocol/6.AccessCommandShell.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL
#define __UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL

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
# This service allows to execute arbitrary commands on the remote node's internal system shell.
#
# Essentially, this service mimics a typical terminal emulator, with one text input (stdin) and two text
# outputs (stdout and stderr). When there's no process running, the input is directed into the terminal
# handler itself, which interpretes it. If there's a process running, the input will be directed into
# stdin of the running process. It is possible to forcefully return the terminal into a known state by
# means of setting the reset flag (see below), in which case the terminal will kill all of the child
# processes, if any, and return into the initial idle state.
#
# The server is assumed to allocate one independent terminal instance per client, so that different clients
# can execute commands without interfering with each other.
#

#
# Input and output should use this newline character.
#
uint8 NEWLINE = '\n'

#
# The server is required to keep the result of the last executed command for at least this time.
# When this time expires, the server may remove the results in order to reclaim the memory, but it
# is not guaranteed. Hence, the clients must retrieve the results in this amount of time.
#
uint8 MIN_OUTPUT_LIFETIME_SEC = 10

#
# These flags control the shell and command execution.
#
uint8 FLAG_RESET_SHELL          = 1     # Restarts the shell instance anew; may or may not imply CLEAR_OUTPUT_BUFFERS
uint8 FLAG_CLEAR_OUTPUT_BUFFERS = 2     # Makes stdout and stderr buffers empty
uint8 FLAG_READ_STDOUT          = 64    # Output will contain stdout
uint8 FLAG_READ_STDERR          = 128   # Output will be extended with stderr
uint8 flags

#
# If the shell is idle, it will interpret this string.
# If there's a process running, this string will be piped into its stdin.
#
# If RESET_SHELL is set, new input will be interpreted by the shell immediately.
#
uint8[<=128] input

---

#
# Exit status of the last executed process, or error code of the shell itself.
# Default value is zero.
#
int32 last_exit_status

#
# These flags indicate the status of the shell.
#
uint8 FLAG_RUNNING              = 1     # The shell is currently running a process; stdin/out/err are piped to it
uint8 FLAG_SHELL_ERROR          = 2     # Exit status contains error code, output contains text (e.g. no such command)
uint8 FLAG_HAS_PENDING_STDOUT   = 64    # There is more stdout to read
uint8 FLAG_HAS_PENDING_STDERR   = 128   # There is more stderr to read
uint8 flags

#
# In case of a shell error, this string may contain ASCII string explaining the nature of the error.
# Otherwise, if stdout read is requested, this string will contain stdout data. If stderr read is requested,
# this string will contain stderr data. If both stdout and stderr read is requested, this string will start
# with stdout and end with stderr, with no separator in between.
#
uint8[<=256] output
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.AccessCommandShell
saturated uint8 flags
saturated uint8[<=128] input
---
saturated int32 last_exit_status
saturated uint8 flags
saturated uint8[<=256] output
******************************************************************************/

#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_ID              6
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_NAME            "uavcan.protocol.AccessCommandShell"
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_SIGNATURE       (0x59276B5921C9246EULL)

#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_MAX_SIZE ((1040 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_NEWLINE                 '\n' // '\n'
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_MIN_OUTPUT_LIFETIME_SEC         10 // 10
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_FLAG_RESET_SHELL           1 // 1
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_FLAG_CLEAR_OUTPUT_BUFFERS          2 // 2
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_FLAG_READ_STDOUT          64 // 64
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_FLAG_READ_STDERR         128 // 128

#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_REQUEST_INPUT_MAX_LENGTH                      128

typedef struct
{
    // FieldTypes
    uint8_t    flags;                         // bit len 8
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[128] max items
    } input;

} uavcan_protocol_AccessCommandShellRequest;

extern
uint32_t uavcan_protocol_AccessCommandShellRequest_encode(uavcan_protocol_AccessCommandShellRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_AccessCommandShellRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_AccessCommandShellRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_AccessCommandShellRequest_encode_internal(uavcan_protocol_AccessCommandShellRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_AccessCommandShellRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_AccessCommandShellRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_MAX_SIZE ((2097 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_FLAG_RUNNING              1 // 1
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_FLAG_SHELL_ERROR          2 // 2
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_FLAG_HAS_PENDING_STDOUT         64 // 64
#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_FLAG_HAS_PENDING_STDERR        128 // 128

#define UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL_RESPONSE_OUTPUT_MAX_LENGTH                    256

typedef struct
{
    // FieldTypes
    int32_t    last_exit_status;              // bit len 32
    uint8_t    flags;                         // bit len 8
    struct
    {
        uint16_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[256] max items
    } output;

} uavcan_protocol_AccessCommandShellResponse;

extern
uint32_t uavcan_protocol_AccessCommandShellResponse_encode(uavcan_protocol_AccessCommandShellResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_AccessCommandShellResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_AccessCommandShellResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_AccessCommandShellResponse_encode_internal(uavcan_protocol_AccessCommandShellResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_AccessCommandShellResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_AccessCommandShellResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_ACCESSCOMMANDSHELL
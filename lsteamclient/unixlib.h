#ifndef __STEAMCLIENT_UNIXLIB_H
#define __STEAMCLIENT_UNIXLIB_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <windef.h>
#include <winbase.h>
#include <winternl.h>

#include "steamclient_structs.h"

#include "wine/unixlib.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

unsigned int steamclient_unix_path_to_dos_path( bool api_result, const char *src, char *dst,
                                                uint32_t dst_bytes, int is_url );

#define PATH_MAX 4096
extern char g_tmppath[PATH_MAX];

struct steamclient_init_params
{
    const char *steam_app_id;
    bool steam_app_id_unset;
    const char *ignore_child_processes;
    bool ignore_child_processes_unset;
};

enum callback_type
{
    SOCKETS_DEBUG_OUTPUT = 1,
    WARNING_MESSAGE_HOOK,
};

struct callback
{
    enum callback_type type;
    uint32_t size;

    union
    {
        struct
        {
            void (*W_STDCALL pfnFunc)( uint32_t, const char * );
            uint32_t type;
            const char msg[1];
        } sockets_debug_output;

        struct
        {
            void (*W_CDECL pFunction)( int32_t, const char * );
            int32_t severity;
            const char msg[1];
        } warning_message_hook;
    };
};

struct steamclient_next_callback_params
{
    bool _ret;
    struct callback *callback;
    uint32_t size;
};

struct steamclient_CreateInterface_params
{
    void *_ret;
    const char *name;
    int *return_code;
};

struct steamclient_Steam_GetAPICallResult_params
{
    bool _ret;
    int32_t pipe;
    uint64_t call;
    void *w_callback;
    int w_callback_len;
    int id;
    bool *failed;
};

struct steamclient_Steam_BGetCallback_params
{
    bool _ret;
    uint32_t pipe;
    w_CallbackMsg_t *w_msg;
    int32_t *ignored;
    u_CallbackMsg_t *u_msg;
};

struct steamclient_callback_message_receive_params
{
    u_CallbackMsg_t *u_msg;
    w_CallbackMsg_t *w_msg;
};

struct steamclient_Steam_FreeLastCallback_params
{
    bool _ret;
    uint32_t pipe;
};

struct steamclient_Steam_ReleaseThreadLocalMemory_params
{
    int thread_exit;
};

struct steamclient_Steam_IsKnownInterface_params
{
    bool _ret;
    const char *version;
};

struct steamclient_Steam_NotifyMissingInterface_params
{
    int32_t pipe;
    const char *version;
};

struct steamclient_networking_messages_receive_144_params
{
    uint32_t count;
    w_SteamNetworkingMessage_t_144 **w_msgs;
};

struct steamclient_networking_messages_receive_147_params
{
    uint32_t count;
    w_SteamNetworkingMessage_t_147 **w_msgs;
};

struct steamclient_networking_messages_receive_153a_params
{
    uint32_t count;
    w_SteamNetworkingMessage_t_153a **w_msgs;
};

struct steamclient_networking_message_release_147_params
{
    w_SteamNetworkingMessage_t_147 *w_msg;
};

struct steamclient_networking_message_release_153a_params
{
    w_SteamNetworkingMessage_t_153a *w_msg;
};

struct networking_message_pool;
struct networking_message
{
    struct networking_message_pool *pool;
    void **p_data;
    uint32_t *p_size;

    union
    {
        u_SteamNetworkingMessage_t_144 *u_msg_144;
        u_SteamNetworkingMessage_t_147 *u_msg_147;
        u_SteamNetworkingMessage_t_153a *u_msg_153a;
    };
    union
    {
        w_SteamNetworkingMessage_t_144 w_msg_144;
        w_SteamNetworkingMessage_t_147 w_msg_147;
        w_SteamNetworkingMessage_t_153a w_msg_153a;
    };
};

typedef NTSTATUS (*unixlib_entry_t)( void *args );
extern const unixlib_entry_t __wine_unix_call_funcs[];

#define STEAMCLIENT_CALL( code, args ) __wine_unix_call_funcs[unix_ ## code]( args )

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "unixlib_generated.h"

#endif /* __STEAMCLIENT_UNIXLIB_H */

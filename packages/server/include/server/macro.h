/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** macro
*/

#pragma once

#define handle_select_error() ({ \
    if (errno == EINTR) return -1; \
    else { \
        cvector_free(_sclient); \
        eraise(_server); \
    } \
})

#define my_fd_set(s) FD_SET(s._socket_fd, &_server->_readfds);
#define my_select(nfds, readfds) select(nfds, readfds, NULL, NULL, NULL)

#define server_client_init() (server_client_t){._message = NULL, \
    ._socket_fd = 0, ._is_logged = false, ._uuid = NULL, ._username = NULL}

#define check_cmd(cmd) ((!strcmp(CCLIENT->_message, cmd)) ? \
    true : false)

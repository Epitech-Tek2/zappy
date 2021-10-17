/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** close
*/

#include "../../include/server.h"

int clean_client_instance(list_serv *_sclient, int const _id)
{
    client_message("client logout");
    close(CCLIENT->_socket_fd);
    _sclient->valueofl(_sclient, _id)->_socket_fd = 0;
    _sclient->valueofl(_sclient, _id)->_is_logged = false;
    memset(&CCLIENT->_address, 0, sizeof(CCLIENT->_address));
    return 1;
}
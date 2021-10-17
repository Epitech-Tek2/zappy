/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** send_logs_to_client
*/

#include "../../include/server.h"

void send_logs_to_client(list_serv *_sclient, int const _id)
{
    for (int i = 0; i != MAX_CLIENT; ++i) {
        if (i != _id && _sclient->valueofl(_sclient, i)->_is_logged) {
            dprintf(_sclient->valueofl(_sclient, i)->_socket_fd, "[log];%s;%s",
            CCLIENT->_username, CCLIENT->_uuid);
        }
    }
}
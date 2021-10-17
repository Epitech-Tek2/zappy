/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** logout
*/

#include "../../include/server.h"

int logout(list_serv *_sclient, int const _id)
{
    CCLIENT->_is_logged = false;
    CCLIENT->_uuid = NULL;
    CCLIENT->_username = NULL;
    clean_client_instance(_sclient, _id);
    return 1;
}
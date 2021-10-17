/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** uuid
*/

#include "../../../include/server.h"

char *parse_uuid(char *_uuid)
{
    for (int i = 0; _uuid[i]; ++i)
        if (findc(_uuid[i], '\r', '\n')) _uuid[i] = '\0';
    return _uuid;
}
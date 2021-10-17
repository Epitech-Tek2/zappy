/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** parse_username
*/

#include "../../include/server.h"

char *parse_username(str_const_restrict _username)
{
    char *username_cpy = strdup(_username);

    username_cpy++;
    username_cpy[strlen(username_cpy) - 1] = '\0';
    return username_cpy;
}
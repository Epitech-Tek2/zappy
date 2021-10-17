/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include "../include/server.h"

static int process(int const _ac, arr_const_restrict _av)
{
    _av++;
    if (2 != _ac) return 84;
    if (!strcmp("-help", *_av)) helper(0);
    if (!issdigit(*_av)) uraise("Invalid port number.");
    create_server(atoi(*_av));
    return 0;
}

int main(int const _ac, char ** _av)
{
    return process(_ac, _av);
}
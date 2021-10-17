/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdio.h>
#include "../include/server.h"

int smain(int const ac, char const **av)
{
    char **names = 0;
    char **args = get_args(&names, ac, av);
    world_t *world = NULL;

    if (!args || !names)
        return (84);
    world = init_world(args, names);
    if (!world)
        return (84);
    else
        return (0);
}

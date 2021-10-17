/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdio.h>
#include "../include/server.h"

bool fflag(char **args, int const ac, char const **av, int const c)
{
    if (ac <= (c + 1) || '-' == av[c + 1][0]) {
         printf("No argument after the flag '-f'(id:%d).\n", c);
         return (false);
    }
    if (args[3])
         free(args[3]);
    args[3] = strdup(av[c + 1]);
    if (!args[3]) {
         printf("Failed to retrieve args.\n");
         return (false);
    }
    return (true);
}

bool cflag(char **args, int const ac, char const **av, int const c)
{
    if (ac <= (c + 1) || '-' == av[c + 1][0]) {
         printf("No argument after the flag '-c'(id:%d).\n", c);
         return (false);
    }
    if (args[2])
         free(args[2]);
    args[2] = strdup(av[c + 1]);
    if (!args[2]) {
         printf("Failed to retrieve args.\n");
         return (false);
    }
    return (true);
}

bool yflag(char **args, int const ac, char const **av, int const c)
{
    if (ac <= (c + 1) || '-' == av[c + 1][0]) {
         printf("No argument after the flag '-y'(id:%d).\n", c);
         return (false);
    }
    if (args[1])
         free(args[1]);
    args[1] = strdup(av[c + 1]);
    if (!args[1]) {
         printf("Failed to retrieve args.\n");
         return (false);
    }
    return (true);
}

bool xflag(char **args, int const ac, char const **av, int const c)
{
    if (ac <= (c + 1) || '-' == av[c + 1][0]) {
        printf("No argument after the flag '-x'(id:%d).\n", c);
        return (false);
    }
    if (args[0])
        free(args[0]);
    args[0] = strdup(av[c + 1]);
    if (!args[0]) {
        printf("Failed to retrieve args.\n");
        return (false);
    }
    return (true);
}

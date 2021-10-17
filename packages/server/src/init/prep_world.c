/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdio.h>
#include "../include/server.h"

static char **init_args(int const ac, char const **av)
{
    char **args = NULL;
    int n = 0;

    for (int i = 0; ac > i; ++i)
        ++n;
    if (12 > n) {
        printf("%s must have 10 args at least.\n");
        return (NULL);
    }
    args = malloc(sizeof(char *) * (6 + 1));
    if (!args) {
        printf("Initialisation failed.\n");
        return (NULL);
    }
    for (int i = 0; 7 > i; ++i)
        args[i] = NULL;
    return (args);
}

static bool check_arg(char **args)
{
    if (!args)
        return (false);
    for (int i = 0; 4 > i; ++i) {
        if (3 == i && !args[i])
            continue;
        if (!args[i])
            return (NULL);
        for (int y = 0; args[i][y]; ++y)
            if (!isdigit(args[i][y])) {
                printf("%s must be integer.\n", args[i]);
                return (false);
            }
    }
    return (true);
}

char **get_args(int const ac, char const **av, char ***names)
{
    char **args = init_args(ac, av);

    if (!args)
        return (NULL);
    if (!parse_args(args, names, av, ac))
        return (NULL);
    if (!names) {
        printf("No names.\n");
        return (NULL);
    } else if (!check_args(args))
        return (NULL);
    else
        return (args);
}

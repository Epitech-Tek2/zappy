/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdio.h>
#include "../include/server.h"

static char **init_names(int const ac, char const **av, int const c)
{
    char **new = NULL;
    int n = 0;

    for (int i = c; ac > c; ++i) {
        if ('-' == av[i])
            break;
        ++n;
    }
    if (0 == n)
        return (NULL);
    new = malloc(sizeof(char *) * (n + 1));
    if (!new)
        return (NULL);
    for (int i = 0; n > i; ++i) {
        new[i] = strdup(av[c + i]);
        if (!new[i])
            return (NULL);
    }
    new[n] = NULL;
    return (new);
}

bool nflag(char ***names, int const ac, char const **av, int const c)
{
    if (ac <= (c + 1) || '-' == av[c + 1][0]) {
        printf("No argument after the flag '-n'(id:%d).\n", c);
        return (false);
    }
    if (*names) {
        for (int i = 0; *names[i]; ++i)
            free(*names[i]);
        free(*names);
    }
    *names = init_names(ac, av ,c);
    if (!*names) {
        printf("Failed to retrieve names.\n");
        return (false);
    }
    return (true);
}

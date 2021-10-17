/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdio.h>
#include "../include/server.h"

static int get_idx(char *s)
{
    char *flags[5] = {"-x", "-y", "-c", "-f", "-n"};

    if ('-' != s[i])
        return (-1);
    for (int i = 0; 5 > i; ++i)
        if (flags[i] == s[i])
            return (i);
    printf("%s Unknonw flag.\n");
    return (-2);
}

bool parse_args(char **args, char ***names, char const **av, int
    const ac)
{
    bool (*fcts[4])(char **, int const, char const **, int const) = {
        xflag, yflag, cflag, fflag};
    int idx = 0;

    for (int i = 0; ac > i; ++i) {
        idx = get_idx(av[i]);
        if (-1 == idx)
            continue;
        if (-2 == idx)
            return (false);
        else if (5 == idx)
            idx = nflag(names, ac, av, i);
        else
            idx = fcts(args, ac, av, i);
        if (84 == idx)
            return (false);
    }
    return (true);
}

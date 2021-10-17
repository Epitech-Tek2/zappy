/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** bct
*/

#include <stdbool.h>
#include <string.h>
#include <stddef.h>

bool got_x_args(char const **args, unsigned int const nbr)
{
    unsigned int n = 0;

    if (!args)
        return (false);
    for (unsigned int i = 1; args[i]; ++i)
        ++n;
    if (n != nbr)
        return (false);
    else
        return (true);
}

void scat(char *s, char const *add)
{
    unsigned int len = (s) ? strlen(add) + strlen(s) : strlen(add);
    char *new = (s) ? strdup(s) : NULL;

    free(s);
    s = malloc(sizeof(char) * (len + 1));
    if (!s)
        s = new;
    else if (new) {
        strcpy(s, new);
        strcat(s, add);
    } else
        strcpy(s, add);
}

/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** msz
*/

#include <stdlib.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

int msz(list_serv *_sclient, int const _id, world_t *world)
{
    char *s = strdup("msz ");
    char tmp[10];

    if (!got_x_args(CCLIENT->_commands, 0)) {
        print("msz error does not need args.\n");
        return (84);
    } else if (!s) {
        print("msz error failed.\n");
        return (84);
    } else {
        itoa(world->x, tmp, 10);
        scat(s, tmp);
        scat(s, " ");
        itoa(world->y, tmp, 10);
        scat(s, tmp);
        scat(s, "\n");
	print(s);
	free(s);
	return (0);
    }
}

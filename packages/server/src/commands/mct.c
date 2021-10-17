/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** msz
*/

#include <uuid/uuid.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static void get_res(world_t *world, unsigned int x, unsigned int y, char *s)
{
    tile_t *tile = world->_tiles[y][x];
    char tmp[10];

    for (unsigned int i = 0; 7 > i; ++i) {
        itoa(tmp, tile->res[i], 10);
        scat(s, tmp);
        if (7 > (i + 1))
            scat(s, " ");
    }
    scat(s, "\n");
}

int mct(list_serv *_sclient, int const _id, world_t *world)
{
    char *s = NULL;

    if (!got_x_args(CCLIENT->_commands, 0)) {
        print("mct error does not need args.\n");
        return (84);
    }
    for (unsigned int i = 0; world->y > i; ++i)
        for (unsigned int j = 0; world->_x > j; ++j) {
            scat(s, "bct ");
            get_res(world, i , j, s);
            print(s);
            free(s);
        }
    return (0);
}

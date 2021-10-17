/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** bct
*/

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static bool s_is_digit(char const *s)
{
    for (unsigned int i = 0; s[i]; ++i)
        if (!isdigit(s[i]))
            return (false);
    return (true);
}

static bool check_args(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 2)) {
        print("bct error need 2 args.\n");
        return (false);
    }
    for (unsigned int i = 1; CCLIENT->_commands[i]; ++i)
        if (!s_is_digit(CCLIENT->_commands[i])) {
            print("bct error args must be integer.\n");
            return (false);
        }
    if (atoi(CCLIENT->_commands[1]) >= world->x ||
        atoi(CCLIENT->_commands[2]) >= world->y) {
        print("bct error wrong pos.\n");
        return (false);
    }
    return (true);
}

static void prep_bct_answer(list_serv *_sclient, int const _id, world_t *world,
    char *s)
{
    int x = atoi(CCLIENT->_commands[1]);
    int y = atoi(CCLIENT->_commands[2]);
    tile_t *tile = world->_tiles[y][x];
    char tmp[10];

    for (unsigned int i = 0; 7 > i; ++i) {
        itoa(tmp, tile->_res[i], 10);
        scat(s, tmp);
        if (7 > (i + 1))
            scat(s, " ");
    }
    scat(s, "\n");
}

int bct(list_serv *_sclient, int const _id, world_t *world)
{
    char *s = strdup("bct ");

    if (!check_args(_sclient, _id, world))
        return (84);
    else if (!s) {
        print("bct error failed.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[i]; ++i) {
        scat(s, CCLIENT->_commands[i]);
        scat(s, " ");
    }
    prep_ct_answer(_sclient, _id, world, s);
    print(s);
    free(s);
    return (0);
}

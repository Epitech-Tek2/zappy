/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** plv
*/

#include <uuid/uuid.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static bool get_player_level(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1] + 1));
    char *s = strdup("plv ");
    char lvl[2];
    char n[(player) ? player->_id : 1];

    if (!s) {
        print("plv error failed.\n");
        return (false);
    } else if (!player) {
        print("plv error no player found.\n");
        return (false);
    }
    itoa(lvl, player->_lvl, 10);
    itoa(n, player->_id, 10);
    scat(s, n);
    scat(" ");
    scat(s, lvl);
    scat(s, "\n");
    print(s);
    free(s);
    return (true);
}

int plv(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("plv error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("plv error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("plv error number need to be an integer.\n");
            return (84);
        }
    if (!get_player_level(_sclient, _id, world))
        return (84);
    else
        return (0);
}

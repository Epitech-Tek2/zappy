/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** ppo
*/

#include <uuid/uuid.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static void save_player_pos(char *s, player_t *player)
{
    char x[world->_x];
    char y[world->_y];
    char n[player->_id];

    itoa(n, player->_id, 10);
    itoa(x, player->_posx, 10);
    itoa(y, player->_posy, 10);
    scat(s, n);
    scat(s, " ");
    scat(s, x);
    scat(s, " ");
    scat(s, y);
    scat("\n");
}

static bool send_player_pos(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1]) + 1);
    char *s = strdup("ppo ");

    if (!player) {
        print("ppo error no player found.\n");
        return (false);
    } else if (!s) {
        print("ppo error failed.\n");
        return (false);
    }
    save_player_pos(s, player);
    print(s);
    free(s);
    return (true);
}

int ppo(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("ppo error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("pin error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("ppo error number need to be an integer.\n");
            return (84);
        }
    if (!send_player_pos(_sclient, _id, world))
        return (84);
    return (0);
}

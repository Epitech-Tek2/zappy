/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** pin
*/

#include <uuid/uuid.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static void get_inv(player_t *player, char *s, char const *n)
{
    char tmp[100];

    scat(s, n);
    scat(s, " ");
    for (unsigned int i = 0; 7 > i; ++i) {
        itoa(tmp, player->_inv[i], 10);
        scat(s, tmp);
        if (7 > (i + 1))
            scat(s , " ");
    }
    scat(s, "\n");
}

static bool print_inv(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1] + 1));        
    char *s = strdup("pin ");
    char n[(player) ? player->_id : 1];
        
    if (!player) {
        print("pin error no player found.\n");
        return (false);
    } else if (!s) {
        print("pin error failed.\n");
        return (false);
    }
    get_inv(player, s, n);
    print(s);
    free(s);
    return (true);
}

int pin(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("pin error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("pin error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("pin error number need to be an integer.\n");
            return (84);
        }
    if (!print_inv(_sclient, _id, world))
        return (84);
    else
        return (0);
}

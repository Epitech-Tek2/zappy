/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** msz
*/

#include <uuid/uuid.h>
#include "../../include/server.h"
#include "../../../../libs/includes/string.h"

static void get_teams_name(team_t *tmp, world_t *world)
{
    char *s = NULL;

    while (tmp) {
        s = strdup("tna ");        
        if (!s) {
            print("tna error failed.\n");
            continue;
        }
        scat(s, tmp->_name);
        scat(s, "\n");
        print(s);
        free(s);
        tmp = tmp->_next;
    }
}

int tna(list_serv *_sclient, int const _id, world_t *world)
{
    team_t *tmp = world->_teams;

    if (!got_x_args(CCLIENT->_commands, 0)) {
        print("tna error does not need args.\n");
        return (84);
    } else if (!tmp) {
        print("tna");
        return (0);
    }
    get_teams_name(tmp, world);
    return (0);
}

/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdlib.h>
#include "world.h"

static player_t *init_player(unsigned int const x,
    unsigned int const y)
{
    player_t *player = malloc(sizeof(player_t));
    time_t t;

    if (!player)
        return (NULL);
    srand((unsigned)time(&t));
    player->_health = 120;
    player->_x = rand() % x;
    player->_y = rand() % y;
    player->_o = (Orientation)rand() % 4;
    player->_lvl = 1;
    for (unsigned int i = 0; INV_MAX > i; ++i)
        player->_inv[i] = 0;
    player->_inv[0] = 9;
    player->_next = NULL;
    return (player);
}

player_t *add_player(player_t **players, unsigned int const w,
    unsigned int const h)
{
    player_t *tmp = *players;
    player_t *new = NULL;

    while (tmp && tmp->_next)
        tmp = tmp->_next;
    new = init_player(w, h);
    if (!new)
        return (NULL);
    if (tmp) {
        new->_id = tmp->_id + 1;
        tmp->_next = new;
    } else {
        new->_id = 0;
        *players = new;
    }
    return (new);
}

void rm_player(player_t **players, player_t *player)
{
    player_t *tmp = *players;
    player_t *next = NULL;

    if (!tmp)
        return;
    if (tmp && tmp->_id == player->_id) {
        next = tmp->_next;
        free(tmp);
        *players = next;
        return;
    }
    while (tmp && tmp->_id != player->_id)
        tmp =tmp->_next;
    next = tmp->_next;
    tmp->_next = next->_next;
    free(next);
}

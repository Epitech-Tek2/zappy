/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static bool check_ressources(player_t *player, int const n)
{
    int invs[7][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0}, {2, 0, 1, 0, 2, 0},
                      {1, 1, 2, 0, 1, 0}, {1, 2, 1, 3, 0, 0}, {1, 2, 3, 0, 1, 0},
                      {2, 2, 2, 2, 2, 1}};
    int players[7] = {1, 2, 2, 4, 4, 6, 6};

    if (players[player->_lvl - 1] > n) {
        print("elevate error not enough players at this level.\n");
        return (false);
    }
    for (int i = 0; (INV_MAX - 1) > i; ++i)
        if (invs[player->_lvl - 1][i] > player->_inv[i + 1]) {
            print("elevate error not enough ingredients.\n");
            return (false);
        }
    for (int i = 0; (INV_MAX - 1) > i; ++i)
        player->_inv[i + 1] -= invs[player->_lvl - 1][i];
    return (true);
}

static int get_nplayer_lvl(player_t *players, int const lvl)
{
    player_t *tmp = players;
    int n = 0;

    while (tmp)
        if (tmp->_lvl == lvl)
            ++n;
    return (n);
}

int elevate(client_t *clt, world_t *world)
{
    player_t *player = find_player(world->_players, clt->_id);
    int n = 0;
        
    if (!player) {
        print("elevate error no player found.\n");
        return (84);
    }
    if (8 == player->_lvl)
        return (0);
    n = get_nplayer_lvl(world->_players, player->_lvl);
    if (check_ressources(player, n)) {
        print("elevate ok");
        return (0);
    } else
        return (84);
}

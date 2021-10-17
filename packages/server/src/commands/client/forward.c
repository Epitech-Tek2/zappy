/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static void try_move(world_t *world, player_t *player, int *x, int *y)
{
    switch (player->_o) {
    case (UP):
        *x = player->_x;
        *y = (0 < (player->_y - 1)) ? world->_y - 1 : player->_y - 1;
    case (DOWN):
        *x = player->_x;
        *y = (world->_y <= (player->_y + 1)) ? 0 : player->_y + 1;
    case (RIGHT):
        *x = (world->_x <= (player->_x + 1)) ? 0 : player->_x + 1;
        *y = player->_y;
    case (LEFT):
        *x = (0 < (player->_x - 1)) ? world->_x - 1 : player->_x - 1;
        *y = player->_y;
    }
}

int forward(client_t *clt, world_t *world)
{
    player_t *player = find_player(clt->_id, world->_players);
    int x = 0;
    int y = 0;
        
    if (!player) {
        print("forward error no player found.\n");
        return (84);
    }
    try_move(world, player, &x, &y);
    player->_x = x;
    player->_y = y;
    print("forward ok.\n");
    return (0);
}

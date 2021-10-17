/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static void get_sressources(tile_t *tile, char *s)
{
    int n = 0;
    char *str[INV_MAX] = {"food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};

    for (int i = 0; INV_MAX > i; ++i)
        if (0 != tile->_res[i])
            ++n;
    if (0 == n)
        return;
    for (int i = 0; INV_MAX > i; ++i) {
        if (0 == tile->_res[i])
            continue;
        scat(s, str[i]);
        --n;
        if (0 == n)
            break;
        else
            scat(s, " ");
    }
}

static void add_res_tile(world_t *world, player_t *player, char *s, int lvl)
{
    int c = 2 * (lvl - 1);
    int y = (0 > player->_y - lvl) ? world->_y - abs(player->_y - lvl) : player->_y - lvl;
    int x = 0;

    for (int i = player->_x - c; player->_x > i; ++i) {
        x = (i < 0) ? world->_x - abs(i) : i;
        get_sressources(world->_tiles[y][x]);
        if (player->_x > (i + 1))
            scat(s, ",");
    }
    get_sressources(world->_tiles[y][player->_x], s);
    for (int i = player->_x; (player->_x + c) >= i; ++i) {
        x = (i >= world->_x) ? (-1 + i - world->_x) : i;
        get_sressources(world->_tiles[y][x]);
        if ((player->_x + c) >= (i + 1))
            scat(s, ",");
    }
}
// clt represented the clt structure
// dont get the start of the message (char *s)
int look(client_t *clt, world_t *world)
{
    player_t *player = find_player(clt->_id);
    int idx = 0;
    char *s = "[";
        
    if (!player) {
        print("look error no player found.\n");
        return (84);
    }
    while (idx > player->_lvl)
        add_res_tile(world, player, s, idx);
    scat(s, "]\n");
    print(s);
    free(s);
    return (0);
}

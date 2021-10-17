/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

int right(client_t *clt, world_t *world)
{
    player_t *player = find_player(clt->_id, world->_players);
        
    if (!player) {
        print("forward error no player found.\n");
        return (84);
    }
    if (3 == (int)player->_o)
        player->_o = UP;
    else
        player->_o = (Orientation)((int)player->_o + 1);
}

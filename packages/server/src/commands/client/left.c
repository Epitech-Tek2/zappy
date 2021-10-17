/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

int left(client_t *clt, world_t *world)
{
    player_t *player = find_player(clt->_id, world->_players);
        
    if (!player) {
        print("forward error no player found.\n");
        return (84);
    }
    if (0 == (int)player->_o)
        player->_o = LEFT;
    else
        player->_o = (Orientation)((int)player->_o - 1);
}

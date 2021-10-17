/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

int fork(client_t *clt, world_t *world)
{
    player_t *player = find_player(world->_players, clt->_id);
    team_t *team = NULL;
    int n = 0;

    if (!player) {
        print("forward error no player found.\n");
        return (84);
    }
    team = find_player_team(world->_teams, player->_id);
    if (!team) {
        print("forward error no team found.\n");
        return (84);
    }
    n = get_nleft(team, world->_nclts);
}

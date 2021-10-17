/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

int get_nleft(team_t *team, int const max)
{
    int n = 0;
        
    for (int i = 0; -1 == team->_ids[i]; ++i)
        ++n;
    return (max - n);
}

int connect_nbr(client_t *clt, world_t *world)
{
    player_t *player = find_player(clt->_id, world->_players);
    team_t *team = NULL;
    char *s = "connect_nbr ";
    char tmp[world->_nclts];
        
    if (!player) {
        print("forward error no player found.\n");
        return (84);
    }
    team = find_player_team(world->_teams, player->_id);
    if (!team) {
        print("forward error no team found.\n");
        return (84);
    }
    itoa(tmp, get_nleft(team, world->_nclts), 10);
    scat(s, tmp);
    scat(s, "\n");
    print(s);
    free(s);
    return (0);
}

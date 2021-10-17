/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

player_t *find_player(player_t *players, int const id)
{
    player_t *tmp = players;

    if (!tmp)
        return (NULL);
    while (tmp && id != tmp->_id)
        tmp = tmp->_next;
    return (tmp);
}

team_t *find_player_team(team_t *teams, int const id)
{
    team_t *tmp = teams;
        
    while (tmp) {
        for (int i = 0; -1 != team->_ids[i]; ++i)
            if (id == team->_ids[i])
                return (tmp);
        tmp = tmp->_next;
    }
    return (NULL);
}

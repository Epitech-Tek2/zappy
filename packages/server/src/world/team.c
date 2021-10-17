/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

void free_team(team_t *team)
{
    if (!team)
        return;
    free(team->_name);
    free(team);
}

static team_t *ctr_team(char const *name)
{
    team_t *new = malloc(sizeof(team_t));
        
    if (!new)
        return (NULL);
    new->_name = strdup(name);
    new->_ids = NULL;
    return (new);
}

team_t *add_team(team_t **teams, char const *name)
{
    team_t *tmp = *teams;
    team_t *new = NULL;
        
    while (tmp && tmp->_next)
        tmp = tmp->_next;
    new = crt_team(name);
    if (!new)
        return (NULL);
    if (tmp)
        tmp->_next = new;
    else
        *teams = new;
    return (new);
}

void rm_team(team_t **teams, team_t *team)
{
    team_t *tmp = *teams;
    team_t *next = NULL;
        
    if (!tmp)
        return;
    if (!strcmp(tmp->_name, team->_name)) {
        next = tmp->_next;
        free(tmp);
        *teams = next;
        return;
    }
    while (tmp->_next || strcmp(tmp->_next->_name, team->_name))
        tmp = tmp->_next;
    if (!tmp->_next)
        return;
    next = tmp->_next;
    tmp->_next = next->_next;
    free_team(next);
}

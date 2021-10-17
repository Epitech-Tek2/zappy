/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static egg_t *ctr_egg(int const x, int const y)
{
    egg_t *new = malloc(sizeof(egg_t));
        
    if (!new)
        return (NULL);
    new->_x = x;
    new->_y = y;
    new->_life = 600;
    new->_lay = 42;
    return (new);
}

egg_t *add_egg(egg_t **eggs, int const x, int const y)
{
    egg_t *tmp = *eggs;
    egg_t *new = NULL;
        
    while (tmp && tmp->_next)
        tmp = tmp->_next;
    new = crt_egg(x, y);
    if (!new)
        return (NULL);
    if (tmp)
        tmp->_next = new;
    else
        *eggs = new;
    return (new);
}

void rm_egg(egg_t **eggs, egg_t *egg)
{
    egg_t *tmp = *eggs;
    egg_t *next = NULL;
        
    if (tmp && tmp->_x == egg->_x && tmp->_y == egg->_y &&
        tmp->_life == egg->_life && tmp->_lay == egg->_lay)) {
        next = tmp->_next;
        free(tmp);
        *eggs = next;
        return;
    }
    while (tmp && tmp->_next && tmp->_next->_x == egg->_x &&
        tmp->_next->_y == egg->_y && tmp->_next->_life == egg->_life &&
	tmp->_next->_lay == egg->_lay)
        tmp = tmp->_next;
    if (!tmp->_next || !tmp)
        return;
    next = tmp->_next;
    tmp->_next = next->_next;
    free(next);
}

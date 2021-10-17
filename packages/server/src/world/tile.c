/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <stdlib.h>
#include "world.h"

void free_tile(tile_t *tile)
{
    if (!tile)
        return;
    if (tile->_ids)
        free(tile->_ids);
    free(tile);
}

tile_t *init_tile(unsigned int const x,
    unsigned int const y)
{
    tile_t *tile = malloc(sizeof(tile_t));

    if (!tile)
        return (NULL);
    tile->_x = x;
    tile->_y = y;
    for (unsigned int i = 0; INV_MAX > i; ++i)
        tile->_res[i] = 0;
    tile->_ids = NULL;
    return (tile);
}

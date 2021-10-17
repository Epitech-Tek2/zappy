/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static bool fill_tiles(world_t *world)
{
    world->_tiles = malloc(sizeof(tile_t **) * (world->_h + 1));
    if (!world->_tiles)
        return (false);
    world->_tiles[world->_h] = NULL;
    for (int i = 0; world->_h > i; ++i) {
        for (int y = 0; world->_w > y; ++y) {
            world->_tiles[i][y] = init_team(i, y);
            if (!world->_tiles[i][y])
                return (false);
        }
        world->_tiles[i][world->_w] = NULL;
    }
    return (true);
}

world_t *init_world(char **args, char **names)
{
    world_t *world = malloc(sizeof(world_t));
        
    if (!world)
        return (NULL);
    world->_w = atoi(args[0]);
    world->_h = atoi(args[1]);
    world->_nclts = atoi(args[2]);
    world->_f = atoi(args[3]);
    world->_teams = names;
    world->_players = NULL;
    world->_eggs = NULL;
    if (!fill_tiles(world))
        return (NULL);
    free_split(args);
    set_ressources(world);
}

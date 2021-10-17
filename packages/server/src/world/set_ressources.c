/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

static void put_ressources(world_t *world, int const idx, int const n)
{
    int x = 0;
    int y = 0;
    time_t t = time(NULL);
        
    srand(t);
    while (n != 0) {
        x = rand % world->_w;
        y = rand % world->_h;
        if (0 == world->_tiles[y][x]->_res[idx]) {
            ++world->_tiles[y][x]->_res[idx];
            --n;
        }
    }
}

static void add_ressources(tile_t *tile, int *res)
{
    for (int i = 0; INV_MAX > i; ++i)
        res[i] += tile->_res[i];
}

static void get_ressources(world_t *world, int *res)
{
    for (int y = 0; world->_tiles[y]; ++y)
        for (int x = 0; world->_tiles[y][x]; ++x)
            add_ressources(world->_tiles[y][x], res);
}

void set_ressources(world_t *world)
{
    int res[INV_MAX];
    int add[INV_MAX];
    float density[INV_MAX] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};
    float tmp = 0;

    get_ressources(world, res);
    for (int i = 0; INV_MAX > i; ++i) {
        tmp = (float)world->_w * (float)world->_h * density[i];
        if (res[i] < tmp)
            add[i] = tmp - res[i];
    }
    for (int i = 0; INV_MAX > i; ++i)
        put_ressources(world, i, add[i]);
}

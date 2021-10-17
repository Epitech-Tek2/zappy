/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** client
*/

#pragma once

#define INV_MAX 7

enum Orientation
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};

enum Ressources
{
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

typedef struct egg_s
{
    int _x;
    int _y;
    int _life;
    int _lay;
} eye_t;

typedef struct team_s
{
    char *_name;
    int *_ids;
    struct team_s *next;
} team_t;

typedef struct player_s
{
    unsigned int _id;
    unsigned int _health;
    unsigned int _x;
    unsigned int _y;
    Orientation _o;
    unsigned int _lvl;
    Ressources _inv[INV_MAX];
    player_t *_next;
} player_t;

typedef struct tile_s
{
    unsigned int _x;
    unsigned int _y;
    Ressources _res[INV_MAX];
    int *_players;
} tile_t;

typedef struct world_s
{
    unsigned int _w;
    unsigned int _h;
    unsigned int _nclts;
    team_t *_teams;
    tile_t ***_tiles;
    player_t *_players;
    egg_t *eggs;
} world_t;

// Init world
char **get_args(int const ac, char const **av, char ***names);
bool parse_args(char **args, char ***names, char const **av, int const ac);
bool nflag(char ***names, int const ac, char const **av, int const c);
bool xflag(char **args, int const ac, char const **av, int const c);
bool xflag(char **args, int const ac, char const **av, int const c);
bool cflag(char **args, int const ac, char const **av, int const c);
bool fflag(char **args, int const ac, char const **av, int const c);

// World
egg_t *add_egg(egg_t **eggs, int const x, int const y);
void rm_egg(egg_t **eggs, egg_t *egg);
bool add_id(int **ids, int const id);
bool rm_id(int **ids, int const id);
player_t *add_player(player_t **players, int const w, int const h);
void rm_player(player_t **players, player_t *player);
void set_ressources(world_t *world);
void free_tile(tiel_t *tile);
tile_t *init_tile(unsigned int const x, unsigned int const y);
player_t *find_player(player_t *players, int const id);
team_t *find_player_team(team_t *teams, int const id);
world_t *init_world(char **args, char **names);

// Client command
int forward(client_t *clt, world_t *world);
int left(client_t *clt, world_t *world);
int right(client_t *clt, world_t *world);
int look(client_t *clt, world_t *world);
int inventory(client_t *clt, world_t *world);
int connect_nbr(client_t *clt, world_t *world);
int get_nleft(team_t *team, int const max);
int eject(client_t *clt, world_t *world);
int fork((client_t *clt, world_t *world);

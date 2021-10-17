        /* PWN */
        // A command that would never be called after receiving a message.
//        static print_new_player(char *s, player_t *player,

int pnw(client_t *clt, world_t *world) // Need the new client, and the game struct
{
    player_t *new = add_players(world->_players);
    char *s = "pwn ";
    char n[100];
    //char 
        
    if (!new || !add_id(clt->_ids, player->_id)) {
        print("pnw Could not add a new player in the game.\n");
        return (84);
    }
}

/* SGT */
int sgt(list_serv *_sclient, int const _id, world_t *world)
{
        
}

/* PEX */
//int pex(list_serv *_sclient, int const _id, world_t *world)

/* PIN */
static void get_inv(player_t *player, char *s, char const *n)
{
    char tmp[100];

    scat(s, n);
    scat(s, " ");
    for (unsigned int i = 0; 7 > i; ++i) {
        itoa(tmp, player->_inv[i], 10);
        scat(s, tmp);
        if (7 > (i + 1))
            scat(s , " ");
    }
    scat(s, "\n");
}

static bool print_inv(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1] + 1));        
    char *s = strdup("pin ");
    char n[(player) ? player->_id : 1];
        
    if (!player) {
        print("pin error no player found.\n");
        return (false);
    } else if (!s) {
        print("pin error failed.\n");
        return (false);
    }
    get_inv(player, s, n);
    print(s);
    free(s);
    return (true);
}

int pin(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("pin error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("pin error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("pin error number need to be an integer.\n");
            return (84);
        }
    if (!print_inv(_sclient, _id, world))
        return (84);
    else
        return (0);
}

/* PLV */
static bool get_player_level(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1] + 1));
    char *s = strdup("plv ");
    char lvl[2];
    char n[(player) ? player->_id : 1];

    if (!s) {
        print("plv error failed.\n");
        return (false);
    } else if (!player) {
        print("plv error no player found.\n");
        return (false);
    }
    itoa(lvl, player->_lvl, 10);
    itoa(n, player->_id, 10);
    scat(s, n);
    scat(" ");
    scat(s, lvl);
    scat(s, "\n");
    print(s);
    free(s);
    return (true);
}

int plv(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("plv error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("plv error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("plv error number need to be an integer.\n");
            return (84);
        }
    if (!get_player_level(_sclient, _id, world))
        return (84);
    else
        return (0);
}

/* PPO */
static void save_player_pos(char *s, player_t *player)
{
    char x[world->_x];
    char y[world->_y];
    char n[player->_id];

    itoa(n, player->_id, 10);
    itoa(x, player->_posx, 10);
    itoa(y, player->_posy, 10);
    scat(s, n);
    scat(s, " ");
    scat(s, x);
    scat(s, " ");
    scat(s, y);
    scat("\n");
}

static bool send_player_pos(list_serv *_sclient, int const _id, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1]) + 1);
    char *s = strdup("ppo ");

    if (!player) {
        print("ppo error no player found.\n");
        return (false);
    } else if (!s) {
        print("ppo error failed.\n");
        return (false);
    }
    save_player_pos(s, player);
    print(s);
    free(s);
    return (true);
}

int ppo(list_serv *_sclient, int const _id, world_t *world)
{
    if (!got_x_args(CCLIENT->_commands, 1)) {
        print("ppo error need one arg.\n");
        return (84);
    } else if (2 != strlen(CCLIENT->_commands[1]) ||
               '#' != CCLIENT->_commands[1][0]) {
        print("pin error the arg is not a player id.\n");
        return (84);
    }
    for (unsigned int i = 1; CCLIENT->_commands[1][i]; ++i)
        if (!isdigit(CCLIENT->_commands[1][i])) {
            print("ppo error number need to be an integer.\n");
            return (84);
        }
    if (!send_player_pos(_sclient, _id, world))
        return (84);
    return (0);
}

/* TNA */

static void get_teams_name(team_t *tmp, world_t *world)
{
    char *s = NULL;

    while (tmp) {
        s = strdup("tna ");        
        if (!s) {
            print("tna error failed.\n");
            continue;
        }
        scat(s, tmp->_name);
        scat(s, "\n");
        print(s);
        free(s);
        tmp = tmp->_next;
    }
}

int tna(list_serv *_sclient, int const _id, world_t *world)
{
    team_t *tmp = world->_teams;

    if (!got_x_args(CCLIENT->_commands, 0)) {
        print("tna error does not need args.\n");
        return (84);
    } else if (!tmp) {
        print("tna");
        return (0);
    }
    get_teams_name(tmp, world);
    return (0);
}

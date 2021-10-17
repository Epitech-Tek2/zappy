/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

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

int inventory(client_t *clt, world_t *world)
{
    player_t *player = find_player(world->_players, atoi(CCLIENT->_commands[1] + 1));        
    char *s = strdup("inventory ");
    char n[(player) ? player->_id : 1];
        
    if (!player) {
        print("inventory error no player found.\n");
        return (false);
    } else if (!s) {
        print("inventory error failed.\n");
        return (false);
    }
    get_inv(player, s, n);
    print(s);
    free(s);
    return (true);    
}

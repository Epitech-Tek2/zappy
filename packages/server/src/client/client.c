/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** client
*/

#include "../../include/server.h"

static commands get_command(str_const_restrict _any_command)
{
    if (NULL == _any_command) return command[NOP];
    for (int i = 1; i != 3; ++i)
        if (!strcmp(_any_command, commands_name[i - 1])) return command[i];
    return command[NOP];
}

static int call_requested_command(list_serv *_sclient,
mstat_t *_stat, int const _id)
{
    /**
     * @brief Stuff to handle your command
     */

    int error = 0;

    printf("%s\n", CCLIENT->_commands[0]);
    if (!strcmp(CCLIENT->_commands[0], "/login")) {
         error = login_client(_sclient, _id);
         return error;
     }
    // else if (CCLIENT->_is_logged && !strcmp(CCLIENT->_message, "/logout"))
    //     return logout(_sclient, _id);
    // if (CCLIENT->_is_logged)
    //     get_command(CCLIENT->_commands[0])(_sclient, _id, _stat->_length);
    return 0;
}

static int process_requested_command(list_serv *_sclient,
int const _id, mstat_t *_stat)
{
    CCLIENT->_commands = _stat->_parse;
    if (check_cmd("msz")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return msz(_sclient, _id);
    }
    if (check_cmd("bct")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return bct(_sclient, _id);
    }
    if (check_cmd("mct")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return mct(_sclient, _id);
    }
    if (check_cmd("tna")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return tna(_sclient, _id);
    }
    if (check_cmd("pnw")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pnw(_sclient, _id);
    }
    if (check_cmd("ppo")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return ppo(_sclient, _id);
    }
    if (check_cmd("plv")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return plv(_sclient, _id);
    }
    if (check_cmd("pin")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pin(_sclient, _id);
    }
    if (check_cmd("pex")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pex(_sclient, _id);
    }
    if (check_cmd("pbc")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pbc(_sclient, _id);
    }
    if (check_cmd("pic")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pic(_sclient, _id);
    }
    if (check_cmd("pie")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pie(_sclient, _id);
    }
    if (check_cmd("pfk")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pfk(_sclient, _id);
    }
    if (check_cmd("pdr")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pdr(_sclient, _id);
    }
    if (check_cmd("pgt")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pgt(_sclient, _id);
    }
    if (check_cmd("pdi")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return pdi(_sclient, _id);
    }
    if (check_cmd("enw")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return enw(_sclient, _id);
    }
    if (check_cmd("eht")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return eht(_sclient, _id);
    }
    if (check_cmd("ebo")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return eht(_sclient, _id);
    }
    if (check_cmd("edi")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return edi(_sclient, _id);
    }
    if (check_cmd("sgt")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return edi(_sclient, _id);
    }
    if (check_cmd("sst")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return sst(_sclient, _id);
    }
    if (check_cmd("seg")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return seg(_sclient, _id);
    }
    if (check_cmd("smg")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return smg(_sclient, _id);
    }
    if (check_cmd("suc")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return suc(_sclient, _id);
    }
    if (check_cmd("sbp")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return sbp(_sclient, _id);
    }

    printf("command = %s\n", CCLIENT->_commands[0]);
    /**
    * @brief Handle command here :)
    */
    // if (-1 == call_requested_command(_sclient, _stat, _id)) {
    //     my_free_arr(_stat->_parse);
    //     free( _stat);
    //     return -1;
    // }
    my_free_arr(_stat->_parse);
    free( _stat);
    return 0;
}

int handle_client_command(list_serv *_sclient, int const _id)
{
    mstat_t *stat = malloc(sizeof(mstat_t));

    if (NULL == stat) return -1;
    if (strlen(CCLIENT->_message))
        CCLIENT->_message[strlen(CCLIENT->_message) - 1] = '\0';
    *stat = (mstat_t){._length = 0, ._parse = NULL};
    if (NULL == CCLIENT->_message) return 0;
    strcpy(stat->_line, CCLIENT->_message);
    my_strctok(stat, ' ');
    if (NULL == stat->_parse) {
        free(stat);
        return 1;
    }
    return process_requested_command(_sclient, _id, stat);
}
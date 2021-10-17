/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** functions
*/

#pragma once

#include <stdbool.h>
#include <stdnoreturn.h>
#include "struct.h"

/**
* @brief Parse _stat->_line and return splited array by _sep.
*
* @param _stat Stat object.
* @param _sep Separator for parsing.
* @return Parsed array.
*/
void my_strctok(mstat_t *_stat, char const _sep);

/**
* @brief Remove '"' from _username
*
* @param _username Username to parse.
* @return parse username.
*/
char *parse_username(str_const_restrict _username);
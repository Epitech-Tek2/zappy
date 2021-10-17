/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** empty
*/

#include "include/string.h"

bool empty(string_const_restrict _this)
{
    return _this->length(_this) ? false : true;
}
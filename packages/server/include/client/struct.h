/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** struct
*/

#pragma once

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>

static volatile sig_atomic_t run = 1;

typedef struct client_s client_t;

typedef struct hostent hostent_t;

struct client_s
{
    int _in_use;
    int _socket_fd;
    int _length_address;
    char *_message;
    char *_uuid;
    char *_username;
    char **_commands;
    ssize_t _ip;
    sockaddr_in_t _address;
    bool _is_logged;
};

typedef enum cmd {
    NOP,
    USERS,
    USER,
    LOG,
    LOGOUT
} cmd_e;

static const char *commands_name[] = {
    "[users]",
    "[user]",
    "[log]",
    "[logout]",
    NULL
};
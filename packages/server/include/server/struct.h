/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** struct
*/

#pragma once

/* DESCRIPTION
 * X width or horizontal position
 * Y height or vertical position
 * q0 resource 0 (food) quantity
 * q1 resource 1 (linemate) quantity
 * q2 resource 2 (deraumere) quantity
 * q3 resource 3 (sibur) quantity
 * q4 resource 4 (mendiane) quantity
 * q5 resource 5 (phiras) quantity
 * q6 resource 6 (thystame) quantity
 * SYMBOL MEANING
 * n player number
 * O orientation: 1(N), 2(E), 3(S), 4(W)
 * L player or incantation level
 * e egg number
 * T time unit
 * N name of the team
 * R incantation result
 * M message
 * i resource number
 */

#include <signal.h>
#include "../../../../libs/includes/vector.h"
#include "../struct.h"

static volatile sig_atomic_t run = 1;

typedef struct server_s server_t;

typedef enum { FDS, READFDS } fds_t;

typedef bool (*commands)(list_serv *_sclient,
    int const _id, int const _length);

typedef enum cmd {
    NOP,
    MSZ,
    BCT,
    TNA,
    PNW,
    PPO,
    PLV,
    PIN,
    PEX,
    PBC,
    PIC,
    PIE,
    PFK,
    PDR,
    PGT,
    PDI,
    ENW,
    EHT,
    EBO,
    EDI,
    SGT,
    SST,
    SEG,
    SGM,
    SUC,
    SBP,
} cmd_e;

static const char *commands_name[] = {
    "/msz",
    "/bct",
    "/tna",
    "/pnw",
    "/ppo",
    "/plv",
    "/pin",
    "/pex",
    "/pbc",
    "/pic",
    "/pie",
    "/pfk",
    "/pdr",
    "/pgt",
    "/pdi",
    "/enw",
    "/eht",
    "/ebo",
    "/edi",
    "/sgt",
    "/sst",
    "/seg",
    "/smg",
    "/suc",
    "/sbp",
    NULL
};

struct server_s
{
    int _socket_fd;
    int _max_sd;
    fd_set _fds;
    fd_set _readfds;
};

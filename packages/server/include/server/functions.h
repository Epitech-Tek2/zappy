/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** functions
*/

#pragma once

#include "../../../../libs/includes/vector.h"
#include "../../../../libs/includes/string.h"

/**
* @brief Create a server object and start it.
*
* @param _port Server listening port.
*/
void create_server(int const _port);

/**
* @brief Create a all save file object
*
* @return -1 in case of error, otherwise 0.
*/
int create_all_save_file(void);

/**
* @brief Load registered client.
*
* @return -1 in case of error, otherwise 0.
*/
int load_registered_user(void);

/**
* @brief Parse the uuid.
*
* @param _uuid uuid to parse.
* @return Parsed uuid
*/
char *parse_uuid(char *_uuid);

/**
* @brief Initialize the client.
*
* @param _sclient Current server client instance.
* @param _server Instance of the server.
* @return -1 in case of error, otherwise 0.
*/
int init_client(list_serv *_sclient, server_t *_server);

/**
* @brief Get the client command object
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return 1 in case of error and then logout/clean_client_instance, otherwise 0
*/
int get_client_command(list_serv *_sclient, int const _id);

/**
* @brief Sharing with other clients that a client has disconnected.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
*/
void share_client_logout(list_serv *_sclient, int const _id);

/**
* @brief Update the current client's status
*
* @param _id Current client id.
* @param _status 0
* @return -1 in case of error, otherwise 0
*/
int update_client_status(list_serv *_sclient, int const _id,
int const _status);

/**
* @brief Handle the client connection.
*
* @param _sclient Current server client instance.
* @param _server Instance of the server
*/
void client_connection(list_serv *_sclient, server_t *_server);

/**
* @brief Reset the _id client metadata.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return 1
*/
int clean_client_instance(list_serv *_sclient, int const _id);

/**
* @brief Handle client command.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return -1 in case of error, otherwise 0
*/
int handle_client_command(list_serv *_sclient, int const _id);

/**
* @brief Check if _username client already exist in save user file.
*
* @param _line Line inside the user save file where data are.
* @param _username Requested username.
* @return -1 in case of error, otherwise 0 if user exist else 1
*/
int check_user_already_register(int const _line, string *_username);

/**
* @brief Handle login client
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return -1 in case of error, otherwise 0.
*/
int login_client(list_serv *_sclient, int const _id);

/**
* @brief Function call to do nothing in function pointer array commands.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length
* @return true
*/
bool nop(list_serv *_sclient __attribute__((unused)),
int const _id __attribute__((unused)),
int const _length __attribute__((unused)));

/**
* @brief Display all users registered data.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length Number of line in save user file
* @return false in case of error, otherwise true
*/
bool users(list_serv *_sclient, int const _id,
int const _length);

/**
* @brief Search a user by uuid.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length Number of line in save user file
* @return false in case of error, otherwise true
*/
bool user(list_serv *_sclient, int const _id, int const _length);

/**
* @brief List of user command
*/
static const commands command[] = {
    &nop,
    &users,
    &user,
    NULL
};

/**
* @brief Append _string in the user save file.
*
* @param _line N line where to append _string
* @param _string String to append
* @return -1 in case of error, otherwise 0
*/
int append_client_data_in_save_file(int const _line,
str_const_restrict _string);

/**
* @brief Append new user logs into user save file.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
*/
void add_new_client_to_save_file(list_serv *_sclient,
int const _id);

int get_registered_user(list_serv *_sclient, int const _id);

void send_logs_to_client(list_serv *_sclient, int const _id);

int logout(list_serv *_sclient, int const _id);

int msz(list_serv *_sclient, int const _id);

int bct(list_serv *_sclient, int const _id);

int mct(list_serv *_sclient, int const _id);

int tna(list_serv *_sclient, int const _id);

int pnw(list_serv *_sclient, int const _id);

int ppo(list_serv *_sclient, int const _id);

int plv(list_serv *_sclient, int const _id);

int pin(list_serv *_sclient, int const _id);

int pex(list_serv *_sclient, int const _id);

int pbc(list_serv *_sclient, int const _id);

int pic(list_serv *_sclient, int const _id);

int pie(list_serv *_sclient, int const _id);

int pfk(list_serv *_sclient, int const _id);

int pdr(list_serv *_sclient, int const _id);

int pgt(list_serv *_sclient, int const _id);

int pdi(list_serv *_sclient, int const _id);

int enw(list_serv *_sclient, int const _id);

int eht(list_serv *_sclient, int const _id);

int ebo(list_serv *_sclient, int const _id);

int edi(list_serv *_sclient, int const _id);

int sgt(list_serv *_sclient, int const _id);

int sst(list_serv *_sclient, int const _id);

int seg(list_serv *_sclient, int const _id);

int smg(list_serv *_sclient, int const _id);

int suc(list_serv *_sclient, int const _id);

int sbp(list_serv *_sclient, int const _id);
/*
** EPITECH PROJECT, 2021
** Core.hpp
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "Interface.hpp"
#include "../Global.hpp"
#include <iostream>

class Core {
public:
    Core(std::string ip, std::string port);

    ~Core();

    void checkConnection(); //check if connection is okay to the server
    void init(); // launcher initalisation
    void run(); // launcher loop
private:
    std::string _ip;
    std::string _port;

    Interface *interface;
};

#endif /* !CORE_HPP_ */

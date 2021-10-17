/*
** EPITECH PROJECT, 2021
** Error.hpp
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>

class Error : public std::exception {
public:
    Error(std::string Error) : _error(Error) {}

    ~Error() = default;

    const char *what() const throw() { return this->_error.c_str(); }

private:
    std::string _error;
};

#endif /* !ERROR_HPP_ */

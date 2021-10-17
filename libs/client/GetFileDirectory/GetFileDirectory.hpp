/*
** EPITECH PROJECT, 2021
** GetFileDirectory.hpp
** File description:
** GetFileDirectory
*/

#ifndef GET_FILE_DIRECTORY_HPP_
#define GET_FILE_DIRECTORY_HPP_

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <dlfcn.h>
#include <algorithm>
#include <dirent.h>

class GetFileDirectory
{
public:
    GetFileDirectory(const std::string path);
    ~GetFileDirectory() = default;

    void sort();

    std::vector<std::string> getList() const;
private:
    DIR *dir;
    struct dirent *diread;
    std::vector<std::string> files;
};

#endif /* !GET_FILE_DIRECTORY_HPP_ */

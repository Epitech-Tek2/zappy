/*
** EPITECH PROJECT, 2021
** GetFileDirectory.cpp
** File description:
** GetFileDirectory
*/

#include "GetFileDirectory.hpp"

GetFileDirectory::GetFileDirectory(const std::string path)
{
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (std::string(diread->d_name) == "." || std::string(diread->d_name) == "..")
                continue;
            files.push_back(path + diread->d_name);
        }
        closedir(dir);
    } else {
        perror("Opendir");
        return;
    }
}

void GetFileDirectory::sort()
{
    std::sort(files.begin(), files.end());
}

std::vector<std::string> GetFileDirectory::getList() const
{
    return files;
}
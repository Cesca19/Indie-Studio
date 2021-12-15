/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** tools
*/

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::string> cut_str_del(std::string str, std::string del)
{
    std::vector<std::string> array;
    
    // std::string tmp = str.substr(0, str.find(del));
    // array.push_back(tmp);
    // str.erase(0, str.find(del) + del.length());
    while (str.find(del) != std::string::npos) {
        std::string tmp = str.substr(0, str.find(del));
        array.push_back(tmp);
        str.erase(0, str.find(del) + del.length());
    }
    array.push_back(str);
    return (array);
}

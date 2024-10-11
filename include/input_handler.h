#pragma once

#include <iostream>
#include <string>
#include <limits>

template<typename varType>
varType prompt(std::string txt)
{
    varType result;
    std::cout << txt;
    if constexpr(std::is_same_v<varType, std::string>)
        std::getline(std::cin, result);
    else{
        std::cin >> result;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return result;
}

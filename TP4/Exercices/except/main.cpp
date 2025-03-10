/**
 * @file except.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdexcept>
#include <iostream>

using namespace std::string_literals;

#include "ofstream_exc.hpp"
#include "ifstream_exc.hpp"

int main()
{
    ofstream_exc f { "test.txt" };

    f << "fuck tumors!"s << "fuck them honestly!"s << "\n"s;

    ofstream_exc fr { "root_owned_file.txt" };

    try 
    {
        fr << "frfr nocap\n"s;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    ifstream_exc f1 { "numbers.txt" };
    int a, b, c;

    f1 >> a >> b >> c;

    std::cout << a << " " << b << " " << c << std::endl;

    ifstream_exc f2 { "thisfiledoesnotexist.lololol" };

    std::string buffer;

    try 
    {
        f2 >> buffer;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
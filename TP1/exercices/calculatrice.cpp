/**
 * @file calculatrice.cpp
 * @author your name (you@domain.com)
 * @brief version recursive
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <stdexcept>
#include <string>



float compute(std::string& input, int depth, bool invert)
{
    std::cout << "float compute(input=" << input << ", depth=" << depth << ", invert= " << invert << ")" << std::endl;
    if (depth == 100)
        throw std::overflow_error("Maximum recursion depth reached");
    
    float res { 0. };

    if ((input.find_first_of("+-") != std::string::npos))
    {
        const int start = input.find_first_of("+-");
        const int lensubstr2 = input.size() - start;
        std::string substr1 = input.substr(0, start);
        std::string substr2 = input.substr(start+1, lensubstr2);

        if (input[start] == '-')
            substr2 = "m" + substr2;

        float res1 = compute(substr1, depth+1, false);
        float res2 = compute(substr2, depth+1, false);

        if (input[start] == '+')
        {
            res = res1 + res2;
            std::cout << res << " = " << res1 << " + " << res2 << std::endl;
        }
        if (input[start] == '-')
        {
            res = res1 + res2;
            std::cout << res << " = " << res1 << " - " << res2 << std::endl;
        }
    }
    else if ((input.find_first_of("*/") != std::string::npos))
    {
        const int start = input.find_first_of("*/");
        const int lensubstr2 = input.size() - start;
        std::string substr1 = input.substr(0, start);
        std::string substr2 = input.substr(start+1, lensubstr2);

        float res1 = compute(substr1, depth+1, false);
        float res2 = compute(substr2, depth+1, false);

        if (input[start] == '*')
        {
            res = res1 * res2;
            std::cout << res << " = " << res1 << " * " << res2 << std::endl;
        }
        if (input[start] == '/')
        {
            res = res1 / res2;
            std::cout << res << " = " << res1 << " / " << res2 << std::endl;
        }
    }
    else
    {
        if (input != "" && input[0] != 'm')
        {
            res = std::stof(input);
        }
        else if (input[0] == 'm')
        {
            std::cout << input.substr(1, input.size() - 1) << std::endl;
            res = - std::stof(input.substr(1, input.size() - 1));
        }
        else
        {
            res = 0.;
        }
    }

    if (invert)
        res *= -1;

    return res;
}

void test()
{
    std::string toto {"toto"};
    if (toto.find_first_of("*") != std::string::npos)
        std::cout << "* in toto" << std::endl;
}


int main()
{
    std::string facile { "3+5" };
    std::string moyen { "3-5*7" };
    std::string difficile { "3+2+5*7-3*3-1" };

    std::cout << facile << " = " << std::endl << compute(facile, 0, false) << std::endl;
    std::cout << moyen << " = " << std::endl << compute(moyen, 0, false) << std::endl;
    std::cout << difficile << " = " << std::endl << compute(difficile, 0, false) << std::endl;

    return 0;
}
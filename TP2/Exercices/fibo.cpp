/**
 * @file fibo.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <fstream>
#include <iostream>

int main()
{
    std::ofstream fout {"fibo.txt"};
    int p1 = 1, p2 = 1;
    fout << "1;1" << std::endl;
    fout << "2;1" << std::endl;
    for (int i = 2 ; i < 20 ; i++)
    {
        int tmp = p1 + p2;
        p1 = p2;
        p2 = tmp;
        fout << i + 1 << ";" << p2 << std::endl;
    }

    return 0;
}
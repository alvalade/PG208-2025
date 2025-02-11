/**
 * @file array_square.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <array>
#include <iostream>

#define TAB_SIZE 4

std::array<int, TAB_SIZE> tab_square(std::array<int, TAB_SIZE>& a)
{
    std::array<int, TAB_SIZE> out;
    for (int i = 0 ; i < TAB_SIZE ; i++)
        out[i] = a[i] * a[i];

    return out;
}


int main()
{
    std::array<int, TAB_SIZE> test {1, 2, 3, 4};
    std::array<int, TAB_SIZE> test2 = tab_square(test);

    for (int i = 0 ; i < TAB_SIZE ; i++)
        std::cout << "Le carre de " << test[i] << " est " << test2[i] << std::endl;

    return 0;

}
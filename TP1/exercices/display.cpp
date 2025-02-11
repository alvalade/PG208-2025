/**
 * @file display.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <array>
#include <vector>
#include <iostream>

#define TAB_SIZE 4

void display_vect_col(std::vector<int>& v)
{
    for (const int e : v)
        std::cout << e << std::endl;
}

void display_vect_line(std::vector<int>& v)
{
    for (size_t i { 0 } ; i < v.size() - 1 ; i++)
        std::cout << v[i] << ", ";
    std::cout << v[v.size() - 1] << std::endl;
}

void display_array(std::array<int, TAB_SIZE>& a)
{
    for (size_t i { 0 } ; i < TAB_SIZE - 1 ; i++)
        std::cout << a[i] << ", ";
    std::cout << a[TAB_SIZE - 1] << std::endl;
}

int main()
{
    std::vector<int> test_vector {1,2,3,4};
    std::array<int, TAB_SIZE> test_array {1,2,3,4};

    std::cout << " -- vecteur colonne" << std::endl;
    display_vect_col(test_vector);

    std::cout << "\n\n";

    std::cout << " -- vecteur ligne" << std::endl;
    display_vect_line(test_vector);

    std::cout << "\n\n";

    std::cout << " -- Tableau " << std::endl;
    display_array(test_array);
}
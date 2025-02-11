/**
 * @file pratique.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>


int sum(std::vector<int>& v1)
{
    int out { 0 };

    for (const int e : v1)
        out += e;

    return out;
}

int scal(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
    {
        std::cout << "Erreur ! Les deux vecteurs sont de dimension differente" << std::endl;
        exit(1);
    }

    int out { 0 };

    for (size_t i {0} ; i < v1.size() ; i++)
        out += v1[i] * v2[i];

    return out;
}

std::vector<int> add(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
    {
        std::cout << "Erreur ! Les deux vecteurs sont de dimension differente" << std::endl;
        exit(1);
    }

    std::vector<int> out (v1.size());

    for (size_t i {0} ; i < v1.size() ; i++)
        out[i] = v1[i] + v2[i];

    return out;
}

void display_vect_line(std::vector<int> v)
{
    for (size_t i { 0 } ; i < v.size() - 1 ; i++)
        std::cout << v[i] << ", ";
    std::cout << v[v.size() - 1] << std::endl;
}

int main()
{   
    std::vector<int> v1 {1,2,3};
    std::vector<int> v2 {2,4,6};

    std::cout << "sum(v1) = " << sum(v1) << std::endl;
    std::cout << "scal(v1, v2) = " << scal(v1, v2) << std::endl;
    std::cout << "add(v1, v2) = ";
    display_vect_line(add(v1, v2));
    std::cout << std::endl;

}
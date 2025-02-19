/**
 * @file surcharge.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>

void print_vector(std::vector<double> & v)
{
    std::cout << "{";
    for (size_t i = 0 ; i < v.size() - 1 ; i++)
        std::cout << v[i] << ", ";
    std::cout << v[v.size() - 1] << "}\n";
}

std::vector<double> add(std::vector<double>& v1, std::vector<double>& v2)
{
    if (v1.size() != v2.size())
        return {}; // si vous ecrivez cela, vous etes des dangers publics, sachez le
    
    std::vector<double> out (v1.size());
    for (size_t i {0} ; i < v1.size() ; i++)
        out[i] = v1[i] + v2[i];

    return out;
}

std::vector<double> add(std::vector<double>& v, double d)
{
    
    std::vector<double> out (v.size());
    for (size_t i {0} ; i < v.size() ; i++)
        out[i] = v[i] + d;

    return out;
}

double add(double d, std::vector<double>& v)
{
    double out = d;
    for (const double e : v)
        d += e;

    return out;
}

int main()
{
    std::vector<double> test {1., 2., 3.};
    double d {4};

    std::vector<double> vect_vect_somme {add(test,test)};
    std::vector<double> vect_double_somme {add(test, d)};
    double double_vect_somme {add(d, test)};

    std::cout << "-- Somme vecteurs :\n";
    print_vector(vect_vect_somme);
    std::cout << "\n\n";

    std::cout << "-- Somme vecteur double :\n";
    print_vector(vect_double_somme);
    std::cout << "\n\n";

    std::cout << "-- Somme double vecteur :\n" << double_vect_somme << "\n";
    
}
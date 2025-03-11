/**
 * @file trinom.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TRINOM_HPP_
#define TRINOM_HPP_

#include "polynomial.hpp"

class Trinom: public Polynomial
{
public:
    Trinom(std::vector<float>& v);
    Trinom(float a, float b, float c);

    std::vector<float> roots();
private:
    std::vector<float> _solve_degree_2();
    std::vector<float> _solve_degree_1();

private:
};


#endif
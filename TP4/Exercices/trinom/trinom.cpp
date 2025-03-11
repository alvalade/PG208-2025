/**
 * @file trinom.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "trinom.hpp"
#include "polynomial.hpp"
#include <cmath>
#include <stdexcept>

Trinom
::Trinom(std::vector<float>& v)
: Polynomial()
{
    if (v.size() > 3)
    {
        throw std::runtime_error("Trinom cannot be a higher degree than 2");
    }

    this->m_coeffs = v;
}

Trinom
::Trinom(float a, float b, float c)
: Polynomial()
{
    this->m_coeffs = {a,b,c};
}

std::vector<float> Trinom
::roots()
{
    int deg = this->degree(); // calls reduct

    if (deg == 2)
    {
        return _solve_degree_2();
    }
    else if (deg == 1)
    {
        return _solve_degree_1();
    }
    else
    {
        throw std::runtime_error("Polynomial has no roots, it is constant");
    }
}

std::vector<float> Trinom
::_solve_degree_2()
{
    float discr = (m_coeffs[1] * m_coeffs[1]) - 4 * m_coeffs[0] * m_coeffs[2];

    if (discr > 0)
    {
        float x1 = (-m_coeffs[1] + std::sqrt(discr))/ (2 * m_coeffs[0]);
        float x2 = (-m_coeffs[1] - std::sqrt(discr))/ (2 * m_coeffs[0]);

        return {x1, x2};
    }
    else if (discr == 0)
    {
        float x = -m_coeffs[1]/(2*m_coeffs[0]);
        return {x};
    }
    else
    {
        throw std::runtime_error("Trinom has negative discriminant, can't be fucked to implement it");
    }

    return {};
}

std::vector<float> Trinom
::_solve_degree_1()
{

    return {-m_coeffs[1]/m_coeffs[0]};
}
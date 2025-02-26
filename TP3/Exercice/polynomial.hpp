/**
 * @file Polynomial.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef POLYNOMIAL_HPP_
#define POLYNOMIAL_HPP_

#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <array>


class Polynomial
{
public:
    // =================== //
    // == CONSTRUCTEURS == //
    // =================== //
    Polynomial();

    Polynomial(const std::vector<float>& v);
    
    template <size_t SIZE>
    Polynomial(const std::array<float, SIZE>& a);

    Polynomial(const float a, const float b, const float c);

    // =================== //
    // ==    METHODES   == //
    // =================== //

    int degree();

    std::vector<float> coeffs();

    std::string to_string();

    friend std::ostream& operator<<(std::ostream& os, Polynomial& p);

    float operator()(float x);
    std::complex<float> operator()(std::complex<float>& x);

    Polynomial operator+ (Polynomial& other);
    Polynomial operator- (Polynomial& other);
    Polynomial operator*(Polynomial& other);

    void operator+=(Polynomial& other);
    void operator-=(Polynomial& other);

    friend Polynomial pow(Polynomial& p, const unsigned int power);

private:
    void reduct();

private:
    std::vector<float> m_coeffs;

};

#endif
/**
 * @file Polynomial.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "polynomial.hpp"
#include <algorithm>


// =============================================================================
// CONSTRUCTEURS
// =============================================================================

Polynomial::Polynomial()
{
    std::cout << "Hello, World!" << std::endl;
}

// - - - - - - - - - - - - - - - - - - - 

Polynomial
::Polynomial(const std::vector<float>& v)
: m_coeffs(v)
{}

// - - - - - - - - - - - - - - - - - - - 

template <size_t SIZE>
Polynomial
::Polynomial(const std::array<float, SIZE>& a)
{
    m_coeffs.resize(a.size());
    std::copy(a.begin(), a.end(), m_coeffs.begin());
}

// - - - - - - - - - - - - - - - - - - - 

Polynomial
::Polynomial(const float a,
             const float b,
             const float c)
: m_coeffs({a,b,c})
{}


// =============================================================================
// METHODES
// =============================================================================

int Polynomial
::degree()
{
    reduct();
    return m_coeffs.size() - 1;
}

// - - - - - - - - - - - - - - - - - - - 

std::vector<float> Polynomial
::coeffs()
{
    return m_coeffs;
}

// - - - - - - - - - - - - - - - - - - - 

std::string Polynomial
::to_string()
{
    reduct();

    if (m_coeffs.size() == 0)
        return "Polynomial({})";

    std::string str { "Polynomial({"};

    for (unsigned int i { 0 } ; i < m_coeffs.size()-1 ; i++)
        str += std::to_string(m_coeffs[i]) + ", ";

    str += std::to_string(m_coeffs[m_coeffs.size() - 1]) + "})";
    return str;
}

// - - - - - - - - - - - - - - - - - - - 

void Polynomial
::reduct()
{
    if (m_coeffs.empty())
        return;

    std::vector<float> new_coeffs {};
    unsigned int copy_start_idx = 0;
    for (unsigned int i { 0 } ; i < m_coeffs.size() ; i++)
    {
        if (m_coeffs[i] != 0.)
        {
            break;
        }
        copy_start_idx++;
    }

    new_coeffs.resize(m_coeffs.size() - copy_start_idx);

    std::copy(m_coeffs.begin() + copy_start_idx, m_coeffs.end(), new_coeffs.begin());

    m_coeffs = new_coeffs;
}

Polynomial pow(Polynomial& p, const unsigned int power)
{
    Polynomial out {p};

    for (unsigned int i { 1 } ; i < power ; i++)
    {
        out = out * p;
    }
    return out;
}

// =============================================================================
// OPERATEURS
// =============================================================================

std::string format_coeff(float coeff)
{
    if (coeff == 1.)
        return "";
    else if (coeff == -1)
        return "-";
    else
        return std::to_string(coeff);
}

std::ostream& operator<<(std::ostream& os, Polynomial& p)
{
    unsigned int power = p.degree();
    std::vector<float> coeffs = p.coeffs();

    for (unsigned int i = 0 ; i < coeffs.size() ; i++)
    {
        if (coeffs[i] != 0)
        {
            if (power > 1)
            {
                os << format_coeff(coeffs[i]) << "x^" << power;
            }
            else if (power == 1)
            {
                os << format_coeff(coeffs[i]) << "x";
            }
            else
            {
                os << coeffs[i];
            }
        }
        if (i < coeffs.size() - 1 && coeffs[i+1] != 0)
            std::cout << " + ";
        power--;
    }
    return os;
}

// - - - - - - - - - - - - - - - - - - -

float Polynomial
::operator()(float x)
{
    float res {0};
    for (std::size_t i{m_coeffs.size()}; i>0 ; i--) 
    {
        res = res*x + m_coeffs[i-1];
    }

    return res;
}

// - - - - - - - - - - - - - - - - - - -

Polynomial Polynomial
::operator+(Polynomial& other)
{
    std::vector<float> coeffs_out;
    unsigned int max_degree = 0;
    if (this->degree() > other.degree())
    {
        coeffs_out.resize(this->degree()+1);
        max_degree = this->degree();
    }
    else 
    {
        coeffs_out.resize(other.degree()+1);
        max_degree = other.degree();
    }

    std::vector<float> this_coeffs = this->coeffs();
    std::vector<float> other_coeffs = other.coeffs();

    unsigned int delta_this = max_degree - this->degree();
    unsigned int delta_other = max_degree - other.degree();

    for (unsigned int i { 0 } ; i <= max_degree ; i++)
    {
        if (i >= delta_this)
            coeffs_out[i] += this_coeffs[i-delta_this];
        if (i >= delta_other)
            coeffs_out[i] += other_coeffs[i-delta_other];
    }

    return Polynomial {coeffs_out};

}

// - - - - - - - - - - - - - - - - - - -

Polynomial Polynomial
::operator-(Polynomial& other)
{
    std::vector<float> coeffs_out;
    unsigned int max_degree = 0;
    if (this->degree() > other.degree())
    {
        coeffs_out.resize(this->degree()+1);
        max_degree = this->degree();
    }
    else 
    {
        coeffs_out.resize(other.degree()+1);
        max_degree = other.degree();
    }

    std::vector<float> this_coeffs = this->coeffs();
    std::vector<float> other_coeffs = other.coeffs();

    unsigned int delta_this = max_degree - this->degree();
    unsigned int delta_other = max_degree - other.degree();

    for (unsigned int i { 0 } ; i <= max_degree ; i++)
    {
        if (i >= delta_this)
            coeffs_out[i] += this_coeffs[i-delta_this];
        if (i >= delta_other)
            coeffs_out[i] -= other_coeffs[i-delta_other];
    }

    return Polynomial {coeffs_out};
}

// - - - - - - - - - - - - - - - - - - -

Polynomial Polynomial
::operator*(Polynomial& other)
{
    unsigned int degree = this->degree() + other.degree();

    std::vector<float> new_coeffs (degree + 1);
    std::vector<float> this_coeffs {this->coeffs()};
    std::vector<float> other_coeffs {other.coeffs()};

    for (unsigned int i_this { 0 } ; i_this <= this->degree() ; i_this++)
        for (unsigned int i_other { 0 } ; i_other <= other.degree() ; i_other++)
        {
            new_coeffs[i_this+i_other] += this_coeffs[i_this] 
                                           * other_coeffs[i_other];
        }

    Polynomial out {new_coeffs};

    return out;
}

// - - - - - - - - - - - - - - - - - - -

void Polynomial
::operator+=(Polynomial& other)
{
    Polynomial tmp { *this + other };
    m_coeffs = tmp.coeffs();
}

// - - - - - - - - - - - - - - - - - - -

void Polynomial
::operator-=(Polynomial& other)
{
    Polynomial tmp { *this - other };
    m_coeffs = tmp.coeffs();
}


// =============================================================================
// SPECIALISATION DU TEMPLATE
// Obligatoire en multi-fichiers
// =============================================================================
template Polynomial::Polynomial(const std::array<float, 2>& a);
template Polynomial::Polynomial(const std::array<float, 3>& a);
template Polynomial::Polynomial(const std::array<float, 5>& a);
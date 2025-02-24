#include <vector>
#include <iostream>

struct Polynomial 
{
    std::vector<double> m_coeffs;
    int degree();
}; // n'oubliez pas ce point-virgule !!

int Polynomial::degree()
{
    return m_coeffs.size() - 1;
}

int main()
{
    Polynomial myPoly;
    std::vector<double> coeffs {1., 1., 1.};

    myPoly.m_coeffs = coeffs;

    std::cout << "Degre du polynome : " << myPoly.degree() << std::endl;
}
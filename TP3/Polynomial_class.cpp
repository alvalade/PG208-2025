#include <vector>
#include <iostream>


class Polynomial
{
public:
    // Constructeur
    Polynomial(std::vector<double>& coeffs);
    
    // Destructeur
    ~Polynomial();

    int degree();

private:
    std::vector<double> m_coeffs;
};

Polynomial::Polynomial(std::vector<double> & coeffs)
{
    m_coeffs = coeffs;
}

Polynomial::~Polynomial()
{
    std::cout << "Je suis un destructeur, Mouah ah ah ah !!!!" << std::endl;
}

int Polynomial::degree()
{
    return m_coeffs.size() - 1;
}

int main()
{
    std::vector<double> coeffs {1.,1.,1.};
    Polynomial P {coeffs};

    std::cout << "Degre du polynome : " << P.degree() << std::endl;
    return 0;
}
/**
 * @file main.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "polynomial.hpp"
#include <array>
#include <vector>
#include <iostream>
#include <complex>

std::ostream& operator<<(std::ostream& os, std::vector<float> v)
{

    if (v.empty())
    {
        os << "{}";
        return os;
    }
    os << "{";
    for (size_t i = 0 ; i < v.size() - 1 ; i++)
        os << v[i] << ", ";
    os << v[v.size() - 1] << "}\n";
    return os;
}

void lb()
{
    std::cout << "\n\n";
}

int main()
{
    std::cout << "## TESTS POUR TP3" << std::endl;
    std::cout << "-- Constructeur par vecteur" << std::endl;
    
    std::vector<float> test_coeffs_vecteur {0,2,3};
    Polynomial poly_constructeur_vecteur {test_coeffs_vecteur};
    std::cout << poly_constructeur_vecteur.to_string() << std::endl;
    std::cout << "Degree : " << poly_constructeur_vecteur.degree() << std::endl;
    std::cout << "Coeffs : " << poly_constructeur_vecteur.coeffs() << std::endl;

    lb();

    std::cout << "-- Constructeur par array" << std::endl;
    std::array<float, 5> test_coeffs_array {4,5,6, 7, 8};
    Polynomial poly_constructeur_array {test_coeffs_array};
    std::cout << poly_constructeur_array.to_string() << std::endl;
    std::cout << "Degree : " << poly_constructeur_array.degree() << std::endl;
    std::cout << "Coeffs : " << poly_constructeur_array.coeffs() << std::endl;

    lb();

    std::cout << "-- Constructeur par floats" << std::endl;
    Polynomial poly_constructeur_floats {7,8,9};
    std::cout << poly_constructeur_floats.to_string() << std::endl;
    std::cout << "Degree : " << poly_constructeur_floats.degree() << std::endl;
    std::cout << "Coeffs : " << poly_constructeur_floats.coeffs() << std::endl;
    
    lb();

    std::cout << "-- Debug empty polynomial" << std::endl;
    std::vector<float> debug_empty_poly_coeffs (10, 0.);
    Polynomial debug_empty_poly {debug_empty_poly_coeffs};
    std::cout << debug_empty_poly.to_string() << std::endl;
    std::cout << "Degree : " << debug_empty_poly.degree() << std::endl;
    std::cout << "Coeffs : " << debug_empty_poly.coeffs() << std::endl;

    lb();

    std::cout << "-- Debug sum" << std::endl;
    std::vector<float> coeffs_vecteur_poly_1 {1,1,1};
    std::vector<float> coeffs_vecteur_poly_2 {-1,1};

    Polynomial p1 {coeffs_vecteur_poly_1};
    Polynomial p2 {coeffs_vecteur_poly_2};
    Polynomial sum {p1 + p2};

    std::cout << p1 << " + " << p2 << " = " << sum << std::endl;
    
    lb();
    
    std::cout << "-- Debug diff" << std::endl;

    Polynomial diff {p1 - p2};

    std::cout << p1 << " - " << p2 << " = " << diff << std::endl;

    lb();
    
    std::cout << "-- Test Application Numerique reelle" << std::endl;
    float val {1.};
    float res {0.};

    res = p1(val);

    std::cout << p1 << " ( " << val << " ) = " << res << std::endl;

    lb();
    
    std::cout << "-- Test Application Numerique complexe" << std::endl;

    std::complex<float> cval {0., 1.};
    std::complex<float> cres {0., 0.};

    cres = p1(cval);

    std::cout << p1 << " ( " << cval << " ) = " << cres << std::endl;

    lb();

    std::cout << "-- Test operator +=" << std::endl;
    Polynomial sumpe {coeffs_vecteur_poly_1};

    std::cout << p1 << " += " << p2 << " : ";
    sumpe += p2;
    std::cout << sumpe << std::endl;

    lb();

    std::cout << "-- Test operator -=" << std::endl;
    Polynomial diffme {coeffs_vecteur_poly_1};

    std::cout << p1 << " += " << p2 << " : ";
    diffme -= p2;
    std::cout << diffme << std::endl;

    lb();

    std::cout << "-- Test operator *" << std::endl;
    Polynomial mult {p1 * p2};

    std::cout << p1 << " * " << p2 << " = " << mult << std::endl;

    lb();

    std::cout << "-- Test pow" << std::endl;
    Polynomial power {pow(p1, 2)};

    std::cout << p1 << " ^ " << 2 << " = " << power << std::endl;



    return 0;
}
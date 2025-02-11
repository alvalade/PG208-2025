/**
 * @file solveur.cpp
 * @author your name (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <cmath>

void send_error()
{
    char response[100];
    std::cin.clear(); // reset les flags d'erreur
    std::cin.ignore(0);
    std::cin >> response;
    std::cout << response << " n'est pas un entier!!!" << std::endl;
}

int main()
{
    float a {0.}, b {0.}, c {0.};

    if (std::cin >> a)
    {
        if (std::cin >> b)
        {
            if (std::cin >> c)
            {
                if (a != 0)
                {
                    float delta { b * b - 4 * a * c};
                    if (delta < 0)
                    {
                        std::cout << "Le polynome a deux racines complexes." << std::endl;
                    }
                    else if (delta == 0)
                    {
                        std::cout << "Le polynome a une racine double : x = " << -b/2*a << std::endl;
                    }
                    else
                    {
                        std::cout << "Le polynome a deux racines : x1 = " << (-b - std::sqrt(delta))/(2*a)
                                  << " et x2 = "                          << (-b + std::sqrt(delta))/(2*a)
                                  << std::endl;
                    }
                }
            }
            else
            {
                send_error();
                return 1;
            }
        }
        else
        {
            send_error();
            return 1;
        }
    }
    else
    {
        send_error();
        return 1;
    }

    return 0;
}
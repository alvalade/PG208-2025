#include <iostream>
#include <cmath>


int main()
{
    // Premiere etape : demander a l'utilisateur les valeurs de a, b et c
    // Dans ce fichier, on va le faire de la maniere la plus basique possible
    // en partant du principe que notre utilisateur va etre sympathique avec nous
    // et que s'il ne l'est pas, on abandonne tout
    
    int a = 0, b = 0, c = 0; // Nos coefficients
    std::cout << "Veuillez entrer la valeur du coefficient de degre 2 : ";
    if (std::cin >> a)       // Lecture du coefficient de degre 2
    {
        std::cout << "Veuillez entrer la valeur du coefficient de degre 1 : ";
        if (std::cin >> b)   // Lecture du coefficient de degre 1
        {
            std::cout << "Veuillez entrer la valeur du coefficient de degre 0 : ";
            if (std::cin >> c) // Lecture du coefficient de degre 0
            {
                // On a nos coefficients ! Plus qu'a calculer

                if (a == 0) // Ultime check : on ne traite que le degre 2
                {
                    // Si a vaut 0, on ne peut plus diviser par 2*a dans le calcul des racines
                    // donc on va dire a l'utilisateur qu'on s'arrete la
                    // J'aurais aussi pu decider de calculer les racines de degre 1
                    // mais pour voir ca, je vous redirige vers le fichier `racines_overkill.cpp`
                    std::cout << "Erreur ! Le polynome specifie n'est pas de degre 2. Terminaison." << std::endl;
                    return 1; 
                }

                // La conversion en float ici sert juste a faire disparaitre un warning du compilateur
                float delta {(float) (b*b - 4*a*c)}; 

                if (delta < 0)
                {
                    std::cout << "Erreur ! Delta est negatif et le polynome a deux racines complexes. Terminaison." << std::endl;
                    return 1; 
                }
                
                if (delta == 0)
                {
                    std::cout << "Le polynome a une racine double X = " << -b/(2*a) << std::endl;
                }
                else // delta > 0 
                {
                    // Notez la conversion en float du numerateur et du denominateur
                    // Si on l'omet, le compilateur va automatiquement convertir le numerateur 
                    // en float, du fait de l'addition de std::sqrt(delta)
                    // mais le denominateur sera un entier (produit d'un entier par un entier)
                    // et le resultat sera un entier. On veut que ce soit un float, donc on force la conversion en float.

                    float x1 {(float) (-b + std::sqrt(delta))/(float) (2 * a)};
                    float x2 {(float) (-b - std::sqrt(delta))/(float) (2 * a)};

                    std::cout << "Les racines du polynome sont x1 = " << x1 << " et x2 = " << x2 << std::endl;
                }
            }
            else // S'il y a eu une erreur
            {
                char response[100];
                std::cin.clear(); // reset les flags d'erreur
                std::cin.ignore(0);
                std::cin >> response;
                std::cout << response << " n'est pas un entier!!!" << std::endl;

                return 1;
            }
        }
        else // S'il y a eu une erreur
        {
            char response[100];
            std::cin.clear(); // reset les flags d'erreur
            std::cin.ignore(0);
            std::cin >> response;
            std::cout << response << " n'est pas un entier!!!" << std::endl;

            return 1;
        }
    }
    else // S'il y a eu une erreur
    {
        char response[100];
        std::cin.clear(); // reset les flags d'erreur
        std::cin.ignore(0);
        std::cin >> response;
        std::cout << response << " n'est pas un entier!!!" << std::endl;

        return 1;
    }

    return 0;
} 
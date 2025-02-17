#include <iostream>

// Version "triche"
float add(float x1, float x2, float x3=0.0, float x4=0.0)
{
    return x1 + x2 + x3 + x4;
}

void vraie_surcharge(int val)
{
    std::cout << val << " est un int" << std::endl;
}

void vraie_surcharge(std::string val)
{
    std::cout << val << " est un std::string" << std::endl;
}

int main()
{
    // Comme add a deux arguments avec des valeurs par defaut
    // on peut ne pas leur donner de valeur lors de l'appel
    std::cout << add(1., 2.) << " " << add(1., 2., 3.) << " " << add(1., 2., 3., 4.) << std::endl;

    // La vraie surcharge differe ici du type de l'argument
    // on aurait aussi pu la faire differer du nombre
    // le compilateur choisit la meilleure surcharge en fonction
    // de ce qu'on lui donne
    vraie_surcharge(12);
    vraie_surcharge("Bonjour");
}
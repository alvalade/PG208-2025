#include <iostream>
#include <fstream>



int main()
{
    std::ofstream fich { "fichier_test.txt" };
    
    if (fich)
    {
        fich << "Hello";
    }
    else
    {
        std::cout << "Oooops ! Erreur de fichier !" << std::endl;
    }

    return 0;
}
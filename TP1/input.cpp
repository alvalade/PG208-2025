#include <iostream>


int main()
{
    int value;
    std::cout << "Entrez un entier." << std::endl;

    if (std::cin >> value) // Verifie si la lecture et la conversion se passent bien
    {
        std::cout << value + 1 << std::endl;
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
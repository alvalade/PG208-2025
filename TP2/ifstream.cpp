#include <fstream>
#include <iostream>

int main()
{
    std::ifstream fich { "data.txt" };
    if (fich)
    {
        int a;
        std::string s;
        fich >> a;
        fich >> s;
        std::cout << a << " " << s << std::endl;
    }
    else
    {
        std::cout << "Erreur !" << std::endl;
    }

    return 0;
}
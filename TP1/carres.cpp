#include <iostream>

int main()
{
    int i {42};
    // Remarquez que contrairement a la syntaxe avec printf, on n'a pas besoin
    // de specifier de type de donnees
    std::cout << "Le double de " << i << " est " << 2 * i << std::endl;
    // Si i avait ete un float par exemple, la syntaxe serait restee la meme
    std::cout << "Son carre est " << i * i << std::endl;
    return 0;
}
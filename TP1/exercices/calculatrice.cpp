/**
 * @file calculatrice.cpp
 * @author your name (you@domain.com)
 * @brief version recursive
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <stdexcept>
#include <string>


/**
 * /!\ Une liberte a ete prise ici par rapport a l'enonce
 * Je commence par rechercher les additions et soustractions
 * puis les multiplications et divisions
 * afin de respecter l'ordre PEMDAS
 *
 * Si vous avez fait la version qui recherche d'abord les divisions
 * et multiplications, ce n'est pas faux. Mais sachez que
 * votre programme se comporte comme si vous aviez des
 * parentheses a gauche et a droite de chaque symbole * ou /
 */
float compute(std::string& input, int depth)
{
    // Pour empecher une recursion infinie
    // Si vous ne comprenez pas ce bloc, pas d'inquietude
    // nous verrons exactement ce qu'il fait en seance 3
    // Retenez juste que si la condition devient vraie, l'execution s'arrete
    if (depth == 100)
        throw std::overflow_error("Maximum recursion depth reached");
    
    float res { 0. };

    // Recherche des symboles + et - dans la chaine
    if ((input.find_first_of("+-") != std::string::npos))
    {
        // Extraction du premier symbole
        const int start = input.find_first_of("+-");
        // Calcul de la longueur de la deuxieme sous-chaine
        const int lensubstr2 = input.size() - start;

        // Separation en sous-chaines
        std::string substr1 = input.substr(0, start);
        std::string substr2 = input.substr(start+1, lensubstr2);

        // Je m'attarde un peu sur ces deux lignes
        // Si on les retire, le programme va echouer les multiplications
        // dont l'operande de gauche est negative
        // J'ajoute ici un "m" devant l'operande negative afin d'avoir un
        // marqueur qui n'est ni un nombre, ni un operateur
        // Si j'ajoute un operateur "-" devant l'operande de gauche
        // je me retrouve avec une recursion infinie (si, si, essayez)
        if (input[start] == '-')
            substr2 = "m" + substr2; // Concatenation des chaines de caracteres

        // Appel recursif sur les sous chaines
        float res1 = compute(substr1, depth+1);
        float res2 = compute(substr2, depth+1);

        // Traitement des resultats
        if (input[start] == '+')
        {
            res = res1 + res2;
        }
        if (input[start] == '-')
        {
            res = res1 + res2;
        }
    }
    // Recherche des divisions et multiplications
    else if ((input.find_first_of("*/") != std::string::npos))
    {
        const int start = input.find_first_of("*/");
        const int lensubstr2 = input.size() - start;

        std::string substr1 = input.substr(0, start);
        std::string substr2 = input.substr(start+1, lensubstr2);

        float res1 = compute(substr1, depth+1);
        float res2 = compute(substr2, depth+1);

        if (input[start] == '*')
        {
            res = res1 * res2;
        }
        if (input[start] == '/')
        {
            res = res1 / res2;
        }
    }
    // Aucun operateur n'a ete detecte
    // Soit ma chaine est un litteral, et je peux la convertir en float
    // Soit ma chaine est vide, et je dois retourner 0.
    else 
    {
        if (input != "" && input[0] != 'm') // Si ma chaine est non vide et que mon litteral est positif
        {
            res = std::stof(input);
        }
        else if (input != "" && input[0] == 'm') // Si ma chaine est non vide et que mon litteral est negatif
        {
            res = - std::stof(input.substr(1, input.size() - 1));
        }
        else // ma chaine est vide
        {
            res = 0.;
        }
    }

    return res;
}

int main()
{
    std::string facile { "3+5" };
    std::string moyen { "3-5*7" };
    std::string difficile { "3+2+5*7-3*3-1" };

    std::cout << facile << " = " << compute(facile, 0) << std::endl;
    std::cout << moyen << " = " << compute(moyen, 0) << std::endl;
    std::cout << difficile << " = " << compute(difficile, 0) << std::endl;

    return 0;
}
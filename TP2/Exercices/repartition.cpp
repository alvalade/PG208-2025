/**
 * @file repartition.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

void parse_letters(std::string filename)
{
    std::unordered_map<std::string, unsigned int> chars;

    std::ifstream file {filename};

    std::string buffer {""};

    while (file >> buffer)
    {
        std::string mychar {""};

        for (size_t i = 0 ; i < buffer.size() ; i++)
        {
            // /!\ Attention /!\
            // La ligne ci-dessous permet d'etre plus laxistes sur les "lettres"
            // que l'on veut compter
            // Il y a une conversion implicite du caractere a l'indice i en 
            // chaine de caractere, et non en variable `char`
            // ce qui permet notamment de conserver les accents
            // Cependant, cela valide aussi beaucoup de caracteres qui
            // ne sont pas des lettres
            // A utiliser a vos risques et perils

            mychar = buffer[i];

            if (chars.count(mychar))
            {
                chars[mychar]++;
            }
            else
            {
                chars[mychar] = 1;
            }
        }
    }

    for (std::pair<std::string, unsigned int> p : chars)
    {
        std::cout << p.first << ":" << p.second << std::endl;
    }
}

std::vector<std::string> remove_punctuation(std::string input)
{
    std::vector<std::string> out;
    
    if (input.empty()) // on n'a rien a traiter
    {
        out.push_back("");
        return out;
    }

    size_t idx;

    // La condition ci-dessous se lit
    // "Tant que la valeur affectee a la variable idx n'est pas std::string::npos"
    // S'il n'y a plus de ponctuation, input.find() retournera std::string::npos

    while( std::string::npos != (idx = input.find_first_of("-,.:;\'\"!?()#")) )
    {
        std::cout << "Fetching... " << std::endl;
        if (idx == 0) // cas extreme no. 1, la chaine commence par une ponctuation
        {
            // on recupere la sous chaine qui commence apres la ponctuation,
            // et on reverifie qu'elle est bonne
            input = input.substr(idx + 1, input.size() - 1);
        }
        else if (idx == input.size() - 1) // cas extreme no. 2, la chaine finit par une ponctuation
        {
            // on recupere la sous chaine qui finit avant la ponctuation,
            // et on reverifie qu'elle est bonne
            input = input.substr(0, input.size() - 1);
        }
        else // On a au moins deux chaines concatenees ensemble par une ponctuation
        {
            std::cout << "Punctuation mid string!!" << std::endl;
            // on va les traiter deux a deux et voir ce que nous retourne chacune
            std::string substr1 = input.substr(0, idx);
            std::string substr2 = input.substr(idx + 1, input.size() - idx);

            std::cout << "Substr1 is " << substr1 << " pass it on mhm" << std::endl;
            std::cout << "Substr2 is " << substr2 << " pass it on mhm" << std::endl;

            std::vector<std::string> v1 = remove_punctuation(substr1);
            std::vector<std::string> v2 = remove_punctuation(substr2);

            // Enfin, on prepare en sortie les chaines non-vides
            for (auto s : v1)
            {
                if (s != "")
                    out.push_back(s);
            }
            for (auto s : v2)
            {
                if (s != "")
                out.push_back(s);
            }

            break; // on a deja traite nos sous-chaines recursivement, on sait
                   // qu'on peut quitter la boucle l'esprit tranquille
        }
    }

    if (out.empty()) // on sort du cas 1 ou du cas 2, input est maintenant safe
    {
        out.push_back(input);
    }

    return out;
}

void parse_words(std::string filename)
{
    std::unordered_map<std::string, unsigned int> chars;

    std::ifstream file {filename};

    std::string buffer {""};
    while (file >> buffer)
    {
        std::vector<std::string> sanitized_buffer { remove_punctuation(buffer) };
        for (std::string elmt : sanitized_buffer)
        {
            if (chars.count(elmt))
            {
                chars[elmt]++;
            }
            else
            {
                chars[elmt] = 1;
            }
        }
    }

    for (std::pair<std::string, unsigned int> p : chars)
    {
        std::cout << p.first << ":" << p.second << std::endl;
    }
}



int main()
{

    parse_letters("jvdltall.txt");
    parse_words("jvdltall.txt");

    return 0;
}
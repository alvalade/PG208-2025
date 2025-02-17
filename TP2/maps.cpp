#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    // declaration :
    //    keys     : string
    //    elements : float

    // Rappel : Comme pour les vecteurs et arrays
    // `std::unordered_map<std::string, float>` nomme UN type unique
    std::unordered_map<std::string, float> eval;

    // Insertion des elements
    eval["Bornat"]  = 1.5;
    eval["Kolbl"]   = 3.5;
    eval["Renaud"]  = 2.5;
    eval["Taris"]   = 3.0;
    eval["Valade"]  = 17.25;
    eval["Vincent"] = 2.75;

    // Lecture des elements
    std::cout << eval["Taris"] << std::endl;

    // Iteration sur les elements
    for (std::pair<std::string, float> item : eval)
        std::cout << item.first << " : " << item.second << std::endl;
}
/** DISCLAIMER
 * Ce fichier fait appel a des complexes un poil plus pousses de C++
 * si vous etiez confortable dans votre module de C, rien ne devrait
 * vous etre etranger.
 *
 * Ce fichier propose une maniere un peu plus complete de repondre au 
 * probleme du calcul de racines. La resolution naive proposee dans
 * le premier fichier fonctionne, mais qu'elle est moche !!!
 *
 */

#include <iostream>
#include <cmath>

/** NOTE
 * J'aurais aime rajouter un argument a cette fonction pour forcer
 * l'utilisateur a rentrer un coefficient different de 0 pour a.
 *
 * Cependant, j'ai peur que cela fasse trop et sorte du scope de
 * cet exercice, en plus de noyer la logique.
 *
 * Si cela vous interesse, faites-m'en part en seance et je vous
 * partagerai une version du code qui gere aussi cette condition
 * supplementaire.
 */
int ask_for_coeff()
{
    int value { 0 };
    if (std::cin >> value)
    {
        return value;
    }
    else
    {
        char response[100];
        std::cin.clear(); // reset les flags d'erreur
        std::cin.ignore(0);
        std::cin >> response;
        std::cout << response << " n'est pas un entier!!!" << std::endl;

        exit(1);
    }
}

int compute_roots(int a, int b, int c)
{
    if (a == 0) // Ultime check : on ne traite que le degre 2
    {
        std::cout << "Erreur ! Le polynome specifie n'est pas de degre 2. Terminaison." << std::endl;
        exit(1); 
    }

    // La conversion en float ici sert juste a faire disparaitre un warning du compilateur
    float delta {(float) (b*b - 4*a*c)}; 

    if (delta < 0)
    {
        std::cout << "Erreur ! Delta est negatif et le polynome a deux racines complexes. Terminaison." << std::endl;
        exit(1); 
    }
    
    if (delta == 0)
    {
        std::cout << "Le polynome a une racine double X = " << -b/(2*a) << std::endl;
    }
    else // delta > 0 
    {
        float x1 {(-b + std::sqrt(delta))/(2.f * a)};
        float x2 {(-b - std::sqrt(delta))/(2.f * a)};

        std::cout << "Les racines du polynome sont x1 = " << x1 << " et x2 = " << x2 << std::endl;
    }

    return 0;
}

int main()
{
    // Comme avant, on commence par demander a l'utilisateur des valeurs
    // pour les coefficients
    // On va decaler la requete et l'affichage d'erreur dans une fonction
    // pour liberer un peu le main

    int a { 0 }, b { 0 }, c { 0 };

    std::cout << "Veuillez entrer la valeur du coefficient de degre 2 : ";
    a = ask_for_coeff();
    std::cout << "Veuillez entrer la valeur du coefficient de degre 1 : ";
    b = ask_for_coeff();
    std::cout << "Veuillez entrer la valeur du coefficient de degre 0 : ";
    c = ask_for_coeff();

    // Idem, on va deplacer la logique du calcul des racines dans une fonction
    compute_roots(a, b, c);

    // Si on arrive ici, aucune erreur n'a eu lieu
    return 0;
}
#include <iostream>
#include <stdexcept>


void fonction_qui_leve_l_exception()
{
    throw std::runtime_error("Je suis une exception !");
}

void fonction_qui_rattrape_l_exception()
{
    try
    {
        fonction_qui_leve_l_exception();
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << "J'ai rencontre une exception :" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
}

int main()
{
    // Ici on fait un try, on va donc continuer l'execution
    fonction_qui_rattrape_l_exception();


    // Ici on ne rattrape pas l'exception... Aie
    fonction_qui_leve_l_exception();

    return 0;
}
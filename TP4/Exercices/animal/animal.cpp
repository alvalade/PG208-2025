/**
 * @file animal.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "animal.hpp"
#include "vertebre.hpp"
#include <cmath>
#include <stdexcept>

Animal
::Animal(int pattes, std::string cri)
: m_pattes(pattes),
  m_cri(cri)
{}

void Animal
::talk()
{
    std::cout << m_cri << std::endl;
}

void Animal
::bouge()
{
    throw std::runtime_error("Cannot move!");
}

int Animal
::nb_pattes()
{
    return m_pattes;
}


void marche(Animal& ani)
{
    for (int i = 0 ; i < ani.nb_pattes() ; i++)
        try
        {
            ani.bouge();
        } 
        catch (std::runtime_error& exception) 
        {
            std::cerr << "Cannot move: " << exception.what() << std::endl;
            return;
        }
    // TODO: Find how to make this shit work
    std::cout << "I have " << dynamic_cast<Vertebre*>(&ani)->nb_os << " bones" << std::endl;
    display_nb_os(ani);
}

void display_nb_os(Vertebre& v)
{
    std::cout << "I have " << v.nb_os << " bones" << std::endl;
}
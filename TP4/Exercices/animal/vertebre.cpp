/**
 * @file vertebre.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "vertebre.hpp"


Vertebre
::Vertebre(int nb_os, int pattes, std::string cri)
: Animal(pattes, cri),
  nb_os(nb_os)
{}

void Vertebre
::bouge()
{
    std::cout << "leve la patte" << std::endl;
    std::cout << "pose la patte" << std::endl;
}
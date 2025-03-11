/**
 * @file vertebre.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VERTEBRE_HPP_
#define VERTEBRE_HPP_

#include "animal.hpp"

class Vertebre: public Animal
{
public:
    Vertebre(int nb_os, int pattes, std::string cri);

    void bouge() override;
    int nb_os;
private:

private:

};

#endif
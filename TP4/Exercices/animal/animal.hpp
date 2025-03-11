/**
 * @file animal.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include "vertebre.hpp"
#include <string>
#include <iostream>

class Vertebre;

class Animal
{
public:
    Animal(int pattes, std::string cri);

    void talk();

    virtual void bouge();

    int nb_pattes();
private:

private:
    int m_pattes;
    std::string m_cri;

};

void marche(Animal& ani);
void display_nb_os(Vertebre& v);

#endif
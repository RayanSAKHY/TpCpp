//
// Created by rsakhy on 18/11/2025.
//

#include "Couple.hpp"
#include <iostream>

Couple::Couple()
{
    std::cout << "Couple cree " << std::endl;
}

Couple::~Couple()
{
    std::cout << "Couple detruit" << std::endl;
}

Couple::Couple(int a = 0, int b = 0) : b1(a), b2(b)
{

}
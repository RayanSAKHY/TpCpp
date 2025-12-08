#include "Fille.hpp"

#include <iostream>

Fille::Fille(std::string nom) : Mere::Mere(nom)
{
    std::cout << "Fille cree" << std::endl;
}

Fille::~Fille()
{
    std::cout << "Fille detruite" << std::endl;
}


void  Fille::afficher()
{
    std::cout << "Objet de classe fille " << std::endl;
}

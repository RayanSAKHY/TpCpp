#include "Mere.hpp"
#include <iostream>

int Mere::compteur = 0;

Mere::Mere(std::string nom) : nom(nom)
{
    std::cout << "Mere cree " << std::endl;
    compteur++;
}

std::string Mere::getNom()
{
    return nom;
}

Mere::~Mere()
{
    std::cout << "Mere detruite" << std::endl;
}

int Mere::getCompteur()
{
    return compteur;
}

void Mere::afficher()
{
    std::cout << "Objet de classe mere " << std::endl;
}
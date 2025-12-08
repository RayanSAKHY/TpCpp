//
// Created by rsakhy on 18/11/2025.
//

#include "Bavarde.hpp"
#include <iostream>

Bavarde::Bavarde(int i) : id(i) {
    std::cout << "Construction de " << id << std::endl;
}

Bavarde::Bavarde() : Bavarde(0)
{
};

void Bavarde::afficher()
{
    std::cout << "Affichage de " << id << std::endl;
}

int Bavarde::get()
{
    return id;
}

Bavarde::~Bavarde() {
    std::cout << "Tais-toi " << id << std::endl;
}
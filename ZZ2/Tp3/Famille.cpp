#include "Famille.hpp"

Famille::Famille(int taille)
{
    if (taille > 0)
    {
        ptr = new Bavarde[taille];
    }
}

Famille::~Famille()
{
    delete [] ptr;
}
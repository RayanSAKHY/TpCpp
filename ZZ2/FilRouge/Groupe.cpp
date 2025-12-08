#include "Groupe.hpp"

int Groupe::index = 0;

int Groupe::getCompteur()
{
    return index;
}

Groupe::Groupe() : Forme()
{
}


void Groupe::ajouter(Forme * f)
{
    if (index < capacite)
    {
        tab[index] = f;
        index ++;
        if (f->getHauteur() > getHauteur())
        {
            setHauteur(f->getHauteur());
        }
        if (f->getLargeur() > getLargeur())
        {
            setLargeur(f->getLargeur());
        }
    }
}

std::string Groupe::toString() const
{
    int currentOrdre = 0;
    std::string chaine;

    while (currentOrdre < index)
    {
        chaine += tab[currentOrdre]->toString();
        currentOrdre ++;
    }
    return chaine;
}
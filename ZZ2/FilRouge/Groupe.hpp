#ifndef FILROUGE_LISTE_HPP
#define FILROUGE_LISTE_HPP

#include "Forme.hpp"

class Groupe : public Forme
{
private:
    static int index;
public:
    static constexpr int capacite = 50;
    Forme * tab[capacite];
    Groupe();
    static int getCompteur();
    std::string toString() const override;
    void ajouter(Forme * f);
};


#endif //FILROUGE_LISTE_HPP
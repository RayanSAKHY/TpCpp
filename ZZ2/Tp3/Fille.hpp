#ifndef ZZ2_FILLE_HPP
#define ZZ2_FILLE_HPP

#include "Mere.hpp"

class Fille : public Mere
{
public:
    Fille(std::string nom = "");
    ~Fille();
    void afficher();
};


#endif //ZZ2_FILLE_HPP
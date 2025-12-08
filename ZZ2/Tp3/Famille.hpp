#ifndef ZZ2_FAMILLE_HPP
#define ZZ2_FAMILLE_HPP

#include "Bavarde.hpp"

class Famille
{
private:
    Bavarde * ptr;
public:
    Famille(int taille);
    ~Famille();
};


#endif //ZZ2_FAMILLE_HPP
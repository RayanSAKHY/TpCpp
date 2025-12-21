#ifndef ZZ2_CERCLE_H
#define ZZ2_CERCLE_H

#include <string>
#include "Forme.hpp"

class Cercle : public Forme
{
public:
    Cercle(int x, int y, int w, int h,COULEURS c = COULEURS::BLEU);
    Cercle(int cx, int cy, int rayon,COULEURS c= COULEURS::BLEU);
    Cercle();
    std::string toString() const override;
    int getRayon() const;
    void setRayon(int rayon);
    Cercle * clone() const override;
};


#endif
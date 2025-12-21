#include "Cercle.hpp"
#include <sstream>
#include <unistd.h>


std::string Cercle::toString() const
{
    std::stringstream oss;
    oss << "CERCLE " << getPoint().getX() << " " << getPoint().getY() << " " << getLargeur() << " " << getHauteur();
    return oss.str();
}

Cercle::Cercle(int x, int y, int w, int h, COULEURS c) : Forme(x,y,c,w,h)
{

}

Cercle::Cercle(int cx, int cy, int rayon,COULEURS c) :
    Cercle(cx,cy,2*rayon,2*rayon,c)
{
}

Cercle::Cercle() :
    Cercle(0,0,0,0,COULEURS::BLEU)
{
}

int Cercle::getRayon() const
{
   return getHauteur()/2;
}

void Cercle::setRayon(int rayon)
{
    setHauteur(rayon*2);
    setLargeur(rayon*2);
}

Cercle * Cercle::clone() const {
    return new Cercle(*this);
}
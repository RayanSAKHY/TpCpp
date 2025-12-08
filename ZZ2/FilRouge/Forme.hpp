#ifndef FILROUGE__FORME__HPP
#define FILROUGE__FORME__HPP

#include "Point.hpp"
#include <string>

#include "Couleur.hpp"

class Forme
{
private:
    Point p;
    static int nbFormes;
    COULEURS couleur;
    int id;
    int w;
    int h;
public:
    COULEURS getCouleur() const;
    void setCouleur(COULEURS couleurs);
    Point const & getPoint() const;
    Forme(const Point& point = ORIGINE , COULEURS couleur = COULEURS::BLEU, int w = 0, int h = 0);
    Forme(int x, int y, COULEURS couleur = COULEURS::BLEU, int w = 0, int h = 0);
    static int getNbFormes();
    virtual std::string toString() const;
    void setX(int& x);
    void setY(int& y);
    int getX() const;
    int getY() const;
    int getId() const;
    static int prochainId();
    int getHauteur() const;
    int getLargeur() const;
    void setHauteur(int hauteur);
    void setLargeur(int largeur);
};


#endif //FILROUGE_FORME_HPP
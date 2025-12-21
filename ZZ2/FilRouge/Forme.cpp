#include "Forme.hpp"
#include <sstream>

int Forme::nbFormes = 0;

int Forme::getNbFormes()
{
    return nbFormes;
}

std::string Forme::toString() const
{
    std::stringstream oss;
    oss << "Forme " << p.getX() << " " << p.getY() << " " << chaineCouleur(couleur);
    return oss.str();
}

COULEURS Forme::getCouleur() const
{
    return couleur;
}

Point const & Forme::getPoint() const
{
    return p;
}

void Forme::setCouleur(COULEURS couleurs)
{
    couleur = couleurs;
}

Forme::Forme(const Point& point, COULEURS c, int w, int h) : p(point), couleur(c), id(nbFormes), w(w), h(h)
{
    nbFormes++;
}

Forme::Forme(int x, int y, COULEURS c,int w,int h) : Forme(Point(x, y) , c,w,h)
{
}

void Forme::setX(int& x)
{
    p.setX(x);
}

void Forme::setY(int& y)
{
    p.setY(y);
}

int Forme::getId() const
{
    return id;
}

int Forme::prochainId()
{
    return nbFormes;
}

int Forme::getX() const
{
    return p.getX();
}

int Forme::getY() const
{
    return p.getY();
}

int Forme::getHauteur() const
{
    return h;
}

int Forme::getLargeur() const
{
    return w;
}

void Forme::setHauteur(int hauteur)
{
    h = hauteur;
}

void Forme::setLargeur(int largeur)
{
    w = largeur;
}

Forme * Forme::clone() const {
    Forme * f = new Forme(*this);
    f->couleur = couleur;
    f->p.setX(p.getX());
    f->p.setY(p.getY());
    f->id = getId();
    f->w = getLargeur();
    f->h = getHauteur();
    nbFormes++;
}
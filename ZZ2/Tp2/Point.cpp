// Fichier Point.cpp

#include <iostream>  // Inclusion d'un fichier standard
#include "Point.hpp" // Inclusion d'un fichier du répertoire courant

void Point::init()
{
    this->x = 0;
    this->y = 0;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setX(int x)
{
    this->x=x;
}

void Point::setY(int y)
{
    this->y=y;
}
void Point::deplacerDe(int dx,int dy)
{
    x+=dx;
    y+=dy;
}

void Point::deplacerVers(int x,int y)
{
    this->x=x;
    this->y=y;
}
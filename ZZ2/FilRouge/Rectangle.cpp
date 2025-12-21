#include "Rectangle.hpp"
#include <sstream>

std::string Rectangle::toString() const
{
    std::stringstream oss;
    oss << "RECTANGLE " << getPoint().getX() << " " << getPoint().getY() << " " << getLargeur() << " " << getHauteur();
    return oss.str();
}

Rectangle::Rectangle(int x, int y, int w, int h,COULEURS c) :
Forme(x,y,c,w,h)
{
}

Rectangle * Rectangle::clone() const {
    return new Rectangle(*this);
}
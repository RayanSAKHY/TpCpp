#ifndef ZZ2_RECTANGLE_H
#define ZZ2_RECTANGLE_H

#include <string>
#include "Forme.hpp"

class Rectangle : public Forme
{
public:
    Rectangle(int x, int y, int w, int h,COULEURS c = COULEURS::BLEU);
    Rectangle();
    std::string toString() const override;
};


#endif
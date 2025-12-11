#ifndef ZZ2_RECTANGLE_H
#define ZZ2_RECTANGLE_H

#include <string>
#include "Forme.hpp"

class Rectangle : public Forme
{
public:
    Rectangle(int x= 0, int y =0, int w = 0, int h = 0,COULEURS c = COULEURS::BLEU);
    std::string toString() const override;
};


#endif
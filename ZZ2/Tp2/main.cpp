// Fichier main.cpp

#include <iostream>
#include "Point.hpp"

int main(int, char**) {
    Point p;
    p.init();

    std::cout << p.getX() << std::endl;
    p.setX(5);
    std::cout << p.getX() << std::endl;
    p.deplacerDe(5,5);
    std::cout << p.getX() << " " <<  p.getY() << std::endl;
    p.deplacerVers(10,10);
    std::cout << p.getX() << " " <<  p.getY() << std::endl;

    return 0;
}
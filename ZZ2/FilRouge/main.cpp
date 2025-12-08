#include <iostream>
#include <string>

#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Groupe.hpp"
#include "Point.hpp"
#include "Forme.hpp"
#include "Couleur.hpp"

int main(int, char**)
{
    std::cout << "Bienvenue dans ce fil rouge" << std::endl;

    // std::cout << c.toString() << std::endl;
    // std::cout << c.toString() << std::endl;
    //
    // Rectangle r1(3,4,5,8);
    //
    // std::cout << r1.toString() << std::endl;

    Groupe l;
    // nb_r == nb_c = 0

    Forme * r1 = new Rectangle(10, 10, 20, 20);
    l.ajouter(r1);
    // nb_r ==1, nb_c == 0, "r1.ordre" == 1
    //std::cout <<"Rectangle " << r1.getOrdre() << " dans main" << std::endl;

    Forme * c1= new Cercle(15, 15, 5);
    l.ajouter(c1);
    // nb_r ==1, nb_c == 1, "c1.ordre" == 2
    //std::cout <<"Cercle " << c1.getOrdre() << " dans main" << std::endl;

    Forme * r2 = new Rectangle(20, 20, 30, 30);
    l.ajouter(r2);
    // nb_r ==2, nb_c == 1, "r2.ordre" == 3
    //std::cout <<"Rectangle " << r2.getOrdre() << " dans main" << std::endl;

    std::cout << l.toString() << std::endl;

    int n =10;
    Forme f(n,n);

    std::cout << f.toString() << std::endl;


    return 0;
}
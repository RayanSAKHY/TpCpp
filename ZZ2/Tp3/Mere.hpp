#ifndef ZZ2_MERE_HPP
#define ZZ2_MERE_HPP
#include <iostream>

class Mere
{
private:
    static int compteur;
    std::string nom;
public:
    Mere(std::string nom = "");
    ~Mere();
    static int getCompteur();
    std::string getNom();
    void afficher();
};


#endif //ZZ2_MERE_HPP
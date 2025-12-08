#include <iostream>
#include "Bavarde.hpp"
#include "Couple.hpp"
#include "Famille.hpp"
#include "Fille.hpp"

int main(int, char **) {

    //1


    /*const int TAILLE = 20;
     Bavarde   tab1[TAILLE];
     Bavarde * tab2 = new Bavarde[TAILLE];
     // Combien d'instances sont créées ? 40

     for (int i =0; i < TAILLE; ++i) {
         tab1[i].afficher();
         tab2[i].afficher();
     }

     // Combien d'instances sont détruites ? 20
     //Correction desalloue tab2
     delete [] tab2;

    Couple c;

    Couple c1(3,9);

    Famille f(4);

     std::string ch="héhé";
     std::cout << ch.length() << ch << std::endl;
    renvoie 6 car é est code en 2 octet en utf8

    Bavarde * b1 = (Bavarde *) malloc(sizeof(Bavarde));

    Bavarde * b2 = new Bavarde(3);

    delete b2;
    if (b1 != nullptr) free(b1);*/


    //2


    Mere m;
    std::cout << "nb mere " << m.getCompteur() << " nom mere : " << m.getNom() << std::endl;

    Mere m1("test");
    std::cout << "nb mere " << m1.getCompteur() << " nom mere : " << m1.getNom() << std::endl;
    Fille f;
    std::cout << "nb fille " << f.getCompteur() << " nom fille : " << f.getNom() << std::endl;
    // Fille f1("test");
    // std::cout << "nb fille " << f1.getCompteur() << std::endl;

    m.afficher();
    m1.afficher();
    f.afficher();

    Mere  *pm = new Mere("mere_dyn");
    Fille *pf = new Fille("fille_dyn");
    Mere  *pp = new Fille("fille vue comme mere");
    pm->afficher(); // affiche Mere
    pf->afficher(); // affiche Fille
    pp->afficher(); // affiche Fille

    delete pm;
    delete pf;
    delete pp;

    return 0;
}
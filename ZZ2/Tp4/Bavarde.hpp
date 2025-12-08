#ifndef ZZ2_BAVARDE_HPP
#define ZZ2_BAVARDE_HPP

class Bavarde
{
private:
    int id;  // identifiant (ou "paramètre %")

public:
    // Constructeur avec valeur par défaut
    Bavarde(int i);
    Bavarde();
    void afficher();

    // Destructeur
    ~Bavarde();

    int get();
};


#endif //ZZ2_BAVARDE_HPP
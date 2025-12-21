#ifndef TP5_AGREGATEUR_HPP
#define TP5_AGREGATEUR_HPP
#include <iostream>


class Agregateur {
private:
    int capacite;
    int taille;
    double * tab;
    double * allocateNewTab(int capacite);
public:
    const double * getTab() const;
    Agregateur(int capacite,double * inTab = nullptr);
    Agregateur();
    int capacity() const;
    int size() const;
    Agregateur(const Agregateur & a);
    ~Agregateur();
    double & operator[](int index) const;
    void pushBack(double elt);
    void afficher(std::ostream & o) const;
    Agregateur & operator=(const Agregateur & a);
};

std::ostream & operator<<(std::ostream & o, const Agregateur & a);
Agregateur operator+(const Agregateur & a,const Agregateur & b);

#endif //TP5_AGREGATEUR_HPP
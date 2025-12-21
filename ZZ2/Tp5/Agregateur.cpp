#include "Agregateur.hpp"
#include <algorithm>
#include <cstring>

Agregateur::Agregateur(int capacite,double * inTab) : capacite(capacite< 10 ? 10:capacite), taille(capacite), tab(inTab)
{
}

Agregateur::Agregateur() : capacite(10), taille(0), tab(nullptr)
{
}

double * Agregateur::allocateNewTab(int capacite) {
    try {
        tab = new double[capacite];
        return tab;
    } catch (const std::bad_alloc &) {
        delete [] tab;
        throw;
    }
}

int Agregateur::capacity() const {
    return capacite;
}

const double * Agregateur::getTab() const {
    return tab;
}

int Agregateur::size() const {
    return taille;
}

Agregateur::Agregateur(const Agregateur & a) : capacite(a.capacite),taille(a.taille), tab(nullptr) {
    if (capacite >= 0 && a.tab != nullptr) {
        tab = allocateNewTab(capacite);
        std::copy_n(a.tab,capacite,tab);
    }
}

Agregateur::~Agregateur() {
    delete [] tab;
}

double & Agregateur::operator[](int index) const
{
    int i = index;
    if (index < 0 || index >= capacite) {
       throw std::out_of_range("index out of range");
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

void Agregateur::pushBack(double elt)
{
    if (capacite >= taille) {
        tab = allocateNewTab(capacite*2);
    }
    tab[taille] = elt;
    taille++;
}

void Agregateur::afficher(std::ostream & o) const {
    if (tab) o << tab;
}

std::ostream & operator<<(std::ostream & o, const Agregateur & a) {
    const int taille = a.size();
    if (a.getTab()) {
        for (int i =0; i < taille; i++) {
            o << a.getTab()[i] << " ";
        }
    }
    return o;
}

Agregateur & Agregateur::operator=(const Agregateur & a) {
    if (&a != this) {
        delete [] tab;
        capacite = a.capacite;
        taille = a.taille;

        if (capacite) {
            tab = allocateNewTab(capacite);
            std::copy_n(a.tab,capacite,tab);
        }
    }
    return *this;
}

Agregateur operator+(const Agregateur & a,const Agregateur & b) {
    int capa = a.capacity()+b.capacity();
    double * tab = new double[capa];
    memcpy(tab,a.getTab(),a.capacity()*sizeof(double));
    memcpy(tab+a.size(),b.getTab(),b.capacity()*sizeof(double));
    Agregateur temp(capa,tab);
    delete [] tab;

    return temp;
}
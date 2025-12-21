#include "AgregateurG.hpp"
#include <algorithm>
#include <cstring>

template<typename T>
AgregateurG<T>::AgregateurG(int capa,T * inTab) :  taille(0), tab(inTab)
{
    if (capa <= 0) {
        throw std::invalid_argument("capacite must be greater than 0");
    }

    capacite = (capa< 10 ? 10:capa);
    if (inTab != nullptr) {
        taille = capacite;
    }
}

template<typename T>
AgregateurG<T>::AgregateurG() : capacite(10), taille(0), tab(nullptr)
{
}

template<typename T>
T * AgregateurG<T>::allocateNewTab(int capacite) {
    try {
        tab = new T[capacite];
        return tab;
    } catch (const std::bad_alloc &) {
        delete [] tab;
        throw;
    }
}

template<typename T>
int AgregateurG<T>::capacity() const {
    return capacite;
}

template<typename T>
const T * AgregateurG<T>::getTab() const {
    return tab;
}

template<typename T>
int AgregateurG<T>::size() const {
    return taille;
}

template<typename T>
AgregateurG<T>::AgregateurG(const AgregateurG & a) : capacite(a.capacite),taille(a.taille), tab(nullptr) {
    if (capacite >= 0 && a.tab != nullptr) {
        tab = allocateNewTab(capacite);
        std::copy_n(a.tab,capacite,tab);
    }
}

template<typename T>
AgregateurG<T>::~AgregateurG() {
    delete [] tab;
}

template<typename T>
T & AgregateurG<T>::operator[](int index) const
{
    int i = index;
    if (index < 0 || index >= capacite) {
       throw std::out_of_range("index out of range");
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

template<typename T>
void AgregateurG<T>::pushBack(T elt)
{
    if (capacite >= taille) {
        tab = allocateNewTab(capacite*2);
    }
    tab[taille] = elt;
    taille++;
}

template<typename T>
void AgregateurG<T>::afficher(std::ostream & o) const {
    if (tab) o << tab;
}

template<typename T>
std::ostream & operator<<(std::ostream & o, const AgregateurG<T> & a) {
    const int taille = a.size();
    if (a.getTab()) {
        for (int i =0; i < taille; i++) {
            o << a.getTab()[i] << " ";
        }
    }
    return o;
}

template<typename T>
AgregateurG<T> & AgregateurG<T>::operator=(const AgregateurG<T> & a) {
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

template<typename T>
AgregateurG<T> operator+(const AgregateurG<T> & a,const AgregateurG<T> & b) {
    int capa = a.capacity()+b.capacity();
    T * tab = new T[capa];
    memcpy(tab,a.getTab(),a.capacity()*sizeof(double));
    memcpy(tab+a.size(),b.getTab(),b.capacity()*sizeof(double));
    AgregateurG<T> temp(capa,tab);
    delete [] tab;

    return temp;
}

template<typename T>
bool AgregateurG<T>::empty() const {
    if (taille == 0) {
        std::cout << "agregateur is empty" << std::endl;
    }
    return taille == 0;
}
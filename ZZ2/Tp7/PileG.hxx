#include "PileG.hpp"
#include <cstring>

template<typename T>
PileG<T>::PileG() : taille(0),capacite(1),tab(nullptr) {
}
template<typename T>
T *PileG<T>::allocateNewTab(int capacite) {
    try {
        tab = new T[capacite];
        return tab;
    }catch (const std::bad_alloc &) {
        delete [] tab;
        throw;
    }
}
template<typename T>
PileG<T>::PileG(int capa): taille(0), tab(nullptr) {
    if (capa <= 0) {
        throw std::invalid_argument("capacite must be greater than 0");
    }
    capacite = capa;
    //std::cout << "ca marche ?" << std::endl;
    tab = PileG::allocateNewTab(capacite);
}

template<typename T>
PileG<T>::PileG(T * newTab,int capacite) : taille(0),capacite(capacite),tab(nullptr){
    if (capacite) {
        tab = allocateNewTab(capacite);
        memcpy(tab,newTab,sizeof(int)*capacite);
    }
}

template<typename T>
int PileG<T>::size() const {
    return taille;
}

template<typename T>
bool PileG<T>::empty() const {
    if (taille == 0) {
        std::cout << "pile is empty" << std::endl;
    }
    return taille == 0;
}

template<typename T>
PileG<T>::PileG(const PileG &p) {
    if (&p!=this) {
        capacite = p.capacite;
        taille = p.taille;
        tab = allocateNewTab(capacite);
        memcpy(tab,p.tab,sizeof(int)*capacite);
    }else tab = nullptr;

}

template<typename T>
PileG<T> & PileG<T>::operator=(const PileG& p) {
    if (&p!=this) {
        delete [] tab;
        capacite = p.capacite;
        if (capacite) {
            tab = allocateNewTab(capacite);
            memcpy(tab,p.tab,sizeof(int)*capacite);
        }else tab = nullptr;
    }
    return *this;
}

template<typename T>
void PileG<T>::push(T elt) {
    if (taille >= capacite) {
        int * newTab = allocateNewTab(capacite*2);
        memcpy(newTab,tab,sizeof(int)*capacite);
        delete [] tab;

    }
    tab[taille] = elt;
    taille++;
}

template<typename T>
int PileG<T>::capacity() const {
    return capacite;
}

template<typename T>
T & PileG<T>::operator[](int index) {
    //std::cout <<"ca marche pas";
    int i = index;
    if (index < 0 || index >= capacite) {
        throw std::out_of_range("index out of range");
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

template<typename T>
PileG<T> operator+(const PileG<T> & p1,const PileG<T> & p2) {
    int capa = p1.capacity() + p2.capacity();
    T * newTab = new T[capa];
    memcpy(newTab,p1.getTab(),sizeof(int)*p1.capacity());
    memcpy(newTab+p1.capacity(),p2.getTab(),sizeof(int)*p2.capacity());
    PileG<T> p(newTab,capa);
    return p;
}

template<typename T>
void PileG<T>::pop() {
    if (empty()) {
        throw std::invalid_argument("Pile is empty");
    }
    taille--;
}

template<typename T>
const T * PileG<T>::getTab() const {
    return tab;
}

template<typename T>
PileG<T>::~PileG() {
    delete [] tab;
}

template<typename T>
T PileG<T>::top() const {
    return tab[taille-1];
}
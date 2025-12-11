#include "Pile.hpp"

#include <cstring>

Pile::Pile() : taille(0),capacite(1),tab(nullptr) {
}

int *Pile::allocateNewTab(int capacite) {
    try {
        tab = new int[capacite];
        return tab;
    }catch (const std::bad_alloc &) {
        delete [] tab;
        throw;
    }
}

Pile::Pile(int capacite): taille(0), tab(nullptr) {
    if (capacite <= 0) {
        throw std::invalid_argument("capacite must be greater than 0");
    }
    if (capacite) {
        tab = allocateNewTab(capacite);
    }
}

Pile::Pile(int * newTab,int capacite) : taille(0),capacite(capacite),tab(nullptr){
    if (capacite) {
        tab = allocateNewTab(capacite);
        memcpy(tab,newTab,sizeof(int)*capacite);
    }
}

int Pile::size() const {
    return taille;
}

bool Pile::empty() {
    return taille == 0;
}

Pile::Pile(const Pile &p) {
    if (&p!=this) {
        capacite = p.capacite;
        taille = p.taille;
        tab = allocateNewTab(capacite);
        memcpy(tab,p.tab,sizeof(int)*capacite);
    }else tab = nullptr;

}

Pile & Pile::operator=(const Pile& p) {
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

void Pile::push(int elt) {
    if (taille >= capacite) {
        int * newTab = allocateNewTab(capacite*2);
        memcpy(newTab,tab,sizeof(int)*capacite);
        delete [] tab;

    }
    tab[taille] = elt;
    taille++;
}

int Pile::capacity() const {
    return capacite;
}
int & Pile::operator[](int index) {
    std::cout <<"ca marche pas";
    int i = index;
    if (index < 0 || index >= capacite) {
        throw std::out_of_range("index out of range");
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

Pile operator+(const Pile & p1,const Pile & p2) {
    int capa =
}

void Pile::pop() {
    if (this->empty()) {
        throw std::invalid_argument("Pile is empty");
    }
    taille--;
}

Pile::~Pile() {
    delete [] tab;
}

int Pile::top() const {
    return tab[taille-1];
}
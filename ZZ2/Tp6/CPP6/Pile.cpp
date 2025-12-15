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

Pile::Pile(int capa): taille(0), tab(nullptr) {
    if (capa <= 0) {
        throw std::invalid_argument("capacite must be greater than 0");
    }
    capacite = capa;
    //std::cout << "ca marche ?" << std::endl;
    tab = allocateNewTab(capacite);
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

bool Pile::empty() const {
    if (taille == 0) {
        std::cout << "pile is empty" << std::endl;
    }
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
    //std::cout <<"ca marche pas";
    int i = index;
    if (index < 0 || index >= capacite) {
        throw std::out_of_range("index out of range");
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

Pile operator+(const Pile & p1,const Pile & p2) {
    int capa = p1.capacity() + p2.capacity();
    int * newTab = new int[capa];
    memcpy(newTab,p1.getTab(),sizeof(int)*p1.capacity());
    memcpy(newTab+p1.capacity(),p2.getTab(),sizeof(int)*p2.capacity());
    Pile p(newTab,capa);
    return p;
}

void Pile::pop() {
    if (this->empty()) {
        throw std::invalid_argument("Pile is empty");
    }
    taille--;
}

const int * Pile::getTab() const {
    return tab;
}
Pile::~Pile() {
    delete [] tab;
}

int Pile::top() const {
    return tab[taille-1];
}
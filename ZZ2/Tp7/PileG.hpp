#ifndef CPP6__PILE_HPP
#define CPP6__PILE_HPP

#include <iostream>
template<typename T>
class PileG  {
private:
    int taille;
    int capacite;
    T * tab;
    T * allocateNewTab(int capacite);
public:
    PileG(int capacite);
    PileG(T * tab,int capacite);
    PileG();
    int size() const;
    const T * getTab() const;
    int capacity() const;
    bool empty() const;
    void push(T elt);
    void pop();
    T top() const;
    ~PileG();
    PileG(const PileG & p);
    PileG& operator=(const PileG & p);
    T & operator[](int index);
};

template<typename T>
PileG<T> operator+(const PileG<T> & p1,const PileG<T> & p2);

#include "PileG.hxx"
#endif

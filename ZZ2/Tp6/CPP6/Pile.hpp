#ifndef CPP6__PILE_HPP
#define CPP6__PILE_HPP

#include <iostream>

class Pile  {
private:
    int taille;
    int capacite;
    int * tab;
    int * allocateNewTab(int capacite);
public:
    Pile(int capacite);
    Pile(int * tab,int capacite);
    Pile();
    int size() const;
    int capacity() const;
    bool empty();
    void push(int elt);
    void pop();
    int top() const;
    ~Pile();
    Pile(const Pile & p);
    Pile& operator=(const Pile & p);
    int & operator[](int index);
};

Pile operator+(const Pile & p1,const Pile & p2);

#endif

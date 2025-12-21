#ifndef TP5_AGREGATEUR_HPP
#define TP5_AGREGATEUR_HPP
#include <iostream>

template<typename T>
class AgregateurG {
private:
    int capacite;
    int taille;
    T * tab;
    T * allocateNewTab(int capacite);
public:
    const T * getTab() const;
    AgregateurG(int capacite,T * inTab = nullptr);
    AgregateurG();
    int capacity() const;
    int size() const;
    AgregateurG(const AgregateurG & a);
    ~AgregateurG();
    T & operator[](int index) const;
    void pushBack(T elt);
    bool empty() const;
    void afficher(std::ostream & o) const;
    AgregateurG & operator=(const AgregateurG & a);
};
template<typename T>
std::ostream & operator<<(std::ostream & o, const AgregateurG<T> & a);

template<typename T>
AgregateurG<T> operator+(const AgregateurG<T> & a,const AgregateurG<T> & b);

#include "AgregateurG.hxx"
#endif //TP5_AGREGATEUR_HPP
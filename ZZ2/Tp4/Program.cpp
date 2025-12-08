#include "Bavarde.hpp"
#include <iostream>


void test1(Bavarde) {
    std::cout << "appel de fonction avec parametre objet et copie" << std::endl;
}

Bavarde test2a() {
    std::cout << "appel de fonction avec retour" <<std::endl;
    return Bavarde(); // creation d'un objet local
} // plus de copie - voir ZZ3

Bavarde test2b() {
    Bavarde b; // creation d'un objet local
    std::cout << "appel de fonction avec retour" << std::endl;
    return b;
} // plus de copie - ZZ3

void test3(Bavarde&) {
    std::cout << "appel de fonction avec référence " << std::endl;
}

void test4(Bavarde *) {
    std::cout << "appel de fonction avec un pointeur sur un objet" << std::endl;
}

int main()
{
    Bavarde b(4);
    test1(b);
    Bavarde b1 = test2a();
    Bavarde b2 = test2b();
    test3(b);
    test4(&b);

    return 0;
}

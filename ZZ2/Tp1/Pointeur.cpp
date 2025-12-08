#include <iostream>

int main()
{
    // int   a = 4;
    // int * p = nullptr;
    //
    // p = &a;
    // std::cout << *p << " " << p;

    // int * p = new int;
    //
    // *p = 3;
    // std::cout << *p << std::endl;
    //
    // delete p;

    const int TAILLE = 500;

    int * p = new int[TAILLE];

    for(auto i = 0; i< TAILLE; ++i ) p[i] = i;
    for(auto i = 0; i< TAILLE; ++i ) std::cout << p[i] << std::endl;

    // delete p;
    delete [] p;
    return 0;
}
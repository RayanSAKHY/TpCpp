#ifndef ZZ2_A_HPP
#define ZZ2_A_HPP
#include "B.hpp"

class B;
class A
{
protected:
    int i = 0;

public:
    void exec(int n);
    void send(B * unB);
    int getI();
};


#endif //ZZ2_A_HPP
#ifndef ZZ2_B_HPP
#define ZZ2_B_HPP
#include "A.hpp"

class A;
class B
{
protected:
    int j = 0;
public:
    void send(A * unA);
    void exec(int n);
    int getJ();
};


#endif //ZZ2_B_HPP
#include "A.hpp"

void A::send(B * unB)
{
    unB->exec(2);
}

void A::exec(int n)
{
    i+=n;
}

int A::getI()
{
    return i;
}

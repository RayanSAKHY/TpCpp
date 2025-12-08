#include "B.hpp"

void B::send(A * unA)
{
    unA->exec(2);
}

void B::exec(int n)
{
    j+=n;
}

int B::getJ()
{
    return j;
}

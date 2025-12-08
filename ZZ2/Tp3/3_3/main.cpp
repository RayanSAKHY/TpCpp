#include <iostream>
#include "A.hpp"
#include "B.hpp"

int main()
{
    A unA;
    B unB;

    std::cout << unA.getI() << std::endl;
    std::cout << unB.getJ() << std::endl;
    unA.send(&unB);

    std::cout << unA.getI() << std::endl;
    std::cout << unB.getJ() << std::endl;

    return 0;
}
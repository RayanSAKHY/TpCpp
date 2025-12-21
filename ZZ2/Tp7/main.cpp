#include <iostream>
#include "maximum.hpp"
#include "PileG.hpp"
#include "AgregateurG.hpp"

int main() {
    int a = 2;
    int b = 4;
    const int c = maximum(a, b);
    std::cout << c << std::endl;

    double d = 3.0;
    double e = maximum(a,static_cast<int>(d));
    std::cout << e << std::endl;

    return 0;
}
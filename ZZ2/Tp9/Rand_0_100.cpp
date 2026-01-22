#include "Rand_0_100.hpp"

int Rand_0_100::operator()(){
    val = distrib(gen);
    return val;
}

Rand_0_100::Rand_0_100(int a, int b) {
    val = 0;
    distrib = std::uniform_int_distribution<int>(a,b);
}

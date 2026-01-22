#ifndef TP9_RAND_0_100_HPP
#define TP9_RAND_0_100_HPP

#include <random>

class Rand_0_100 {
private:
    int val;
    std::mt19937 gen{std::random_device()()};
    std::uniform_int_distribution<int> distrib;

public:
    int operator()();
    Rand_0_100(int a,int b);
};


#endif //TP9_RAND_0_100_HPP
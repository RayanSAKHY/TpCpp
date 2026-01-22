#ifndef TP9_COMPARATEURZZ_HPP
#define TP9_COMPARATEURZZ_HPP

#include "ZZ.hpp"

class ComparateurZZ {
public:
    double operator() (const ZZ& zz1, const ZZ& zz2) const;
};


#endif //TP9_COMPARATEURZZ_HPP
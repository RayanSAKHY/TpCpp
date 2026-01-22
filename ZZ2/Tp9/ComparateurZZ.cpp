#include "ComparateurZZ.hpp"

double ComparateurZZ::operator()(const ZZ &zz1,const ZZ & zz2) const {
    return zz1.getNote()<zz2.getNote();
}
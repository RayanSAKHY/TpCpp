#ifndef TP8_ZZ_HPP
#define TP8_ZZ_HPP

#include <string>
#include <iostream>

class ZZ {
private:
    std::string nom, prenom;
    double note;

public:
    ZZ(std::string nom,std::string prenom,double note);
    bool operator<(const ZZ& zz) const;
    std::string getNom() const;
    std::string getPrenom() const;
    double getNote() const;
    double operator() (const ZZ& zz) const;
};

std::ostream& operator<<(std::ostream& o,const ZZ& zz);
#endif //TP8_ZZ_HPP
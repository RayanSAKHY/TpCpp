#include "ZZ.hpp"

std::ostream& operator<<(std::ostream& o,const ZZ& zz) {
    o << "Nom :" << zz.getNom() << " ,Prenom : " << zz.getPrenom() << " Note : " << zz.getNote();
    return o;
}

// bool ZZ::operator<(const ZZ& zz) const {
//     return (note < zz.note);
// }

bool ZZ::operator<(const ZZ& zz) const {
    std::string s1 = nom+prenom;
    std::string s2 = this->getNom()+this->getPrenom();
    return s1<s2;
}

double ZZ::operator()(const ZZ &zz) const {
    return note<this->getNote();
}

ZZ::ZZ(std::string nom, std::string prenom, double note): nom(nom),prenom(prenom),note(note) {
}

std::string ZZ::getNom() const{
    return nom;
}

double ZZ::getNote() const {
    return note;
}

std::string ZZ::getPrenom() const {
    return prenom;
}
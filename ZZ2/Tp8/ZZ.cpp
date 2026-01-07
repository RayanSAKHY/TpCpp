#include "ZZ.hpp"

std::ostream& operator<<(std::ostream& o,const ZZ& zz) {
    o << "Nom :" << zz.getNom() << " ,Prenom : " << zz.getPrenom() << " Note : " << zz.getNote();
    return o;
}

bool ZZ::operator<(const ZZ& zz) const {
    return (note < zz.note);
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
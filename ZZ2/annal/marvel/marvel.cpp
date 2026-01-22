#include "marvel.hpp"

#include <sstream>

Personne::Personne(std::string prenom,std::string nom,Genre genre): prenom(prenom),nom(nom),genre(genre) {
}

std::string Personne::getPrenom() const{
    return prenom;
}
std::string Personne::getNom() const {
    return nom;
}

Personne::Genre Personne::getGenre() const {
    return genre;
}
        
std::stringstream& Personne::afficher(std::stringstream & ss) const {

    ss << prenom << " " << nom << " [";

    switch (genre) {
        case HOMME:
            ss << "HOMME";
            break;
        case FEMME:
            ss << "FEMME";
            break;
        case INDETERMINE:
            ss << "INDETERMINE";
            break;
    }
    ss << "]";

    return ss;
}
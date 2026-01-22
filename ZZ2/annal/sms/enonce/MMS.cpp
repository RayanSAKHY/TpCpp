#include "MMS.hpp"

MMS::MMS(std::string exp,std::string dest, std::string date): SMS(exp,dest,date) {
}


void MMS::joindre(Media * media) {
    listMedia.push_back(media);
}

std::string MMS::afficher() const {
    std::ostringstream oss;

    oss << getTexte();
    std::vector<Media *>::const_iterator it = listMedia.begin();
    while (it!=listMedia.end()) {
        oss << (*it)->afficher();
        it++; 
    }

    return oss.str();
}

MMS::~MMS() {
    std::vector<Media *>::const_iterator it = listMedia.begin();
    while (it!=listMedia.end()) {
        delete (*it);
        it++;
    }
}

std::string MMS::getDe() const {
    return expediteur;
}

std::string MMS::getA() const {
    return destinataire;
}
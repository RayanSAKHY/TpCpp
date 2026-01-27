#include "batiment.hpp"

int Ouvrier::compteur = 0;

Adresse::Adresse(std::string nom, double latitude, double longitude): nom(nom),latitude(latitude),longitude(longitude) {
}
        
Adresse::Adresse(): Adresse(nom_zz,latitude_zz,longitude_zz) {}
        
std::string Adresse::getNom() const {
    return nom;
}
        
double Adresse::getLatitude() const {
    return latitude;
}
        
double Adresse::getLongitude() const {
    return longitude;
} 

std::ostream& Adresse::toStream(std::ostream& flux) const{
    flux << nom<< " ( " << std::fixed << std::setprecision(4) << latitude << " ; " << longitude<< " )";
    return flux;
}

Ouvrier::Ouvrier(Adresse adresse) : disponible(true), id(compteur+1),adresse(adresse){
    compteur++;
}

Ouvrier::Ouvrier(): Ouvrier(Adresse()) {
}

std::ostream& Ouvrier::travailler(std::ostream& flux) const {
    if (!disponible) {
        throw IndisponibleException();
    }
    flux << "Ouvrier #" << id << " travaille à ";
    adresse.toStream(flux);
    return flux;
}

int Ouvrier::getCompteur() {
    return compteur;
}

void Ouvrier::setChantier(Adresse _adresse) {
    adresse = _adresse;
}

Adresse Ouvrier::getChantier() const {
    return adresse;
}

int Ouvrier::getId() const {
    return id;
}

bool Ouvrier::isDisponible() const {
    return disponible;
}

Ouvrier::Ouvrier(const Ouvrier& ouvrier): Ouvrier(ouvrier.adresse){
}

const char * IndisponibleException::what() const noexcept {
    return "je travaille pas";
}

void Ouvrier::setDisponible(bool dispo) {
    disponible = dispo;
}

Ouvrier::~Ouvrier() {
    compteur--;
}

void Chef::ajouter(Ouvrier* ouvrier) {
    equipe.emplace(ouvrier->getId(),ouvrier);
}

void Chef::setChantier(Adresse _adresse) {
    adresse = _adresse;
    auto it = equipe.begin();
    while (it !=equipe.end()) {
        it->second->setChantier(_adresse);
        it++;
    }
}

std::ostream& Chef::travailler(std::ostream& flux) const {
    if (!disponible) {
        throw IndisponibleException();
    }
    flux << "Chef #" << id << " travaille à ";
    adresse.toStream(flux);
    auto it = equipe.begin();
    while (it !=equipe.end()) {
        if (it->second->isDisponible()) {
            flux << "\n avec Ouvrier #" << it->first;
        }
        it++;
    }
    return flux;
}

std::ostream& operator<<(std::ostream& flux,const Ouvrier& ouvrier) {
    ouvrier.travailler(flux);
    return flux;
}

bool Comparateur::operator()(const Ouvrier * o1,const Ouvrier * o2) const{
    return o1->getId() < o2->getId();
}


std::string Electricite::getNom() const {
    return "electricite";
}

std::string Chauffage::getNom() const {
    return "chauffage";
}


std::string Plomberie::getNom() const {
    return "plomberie";
}

std::string PlomberieChauffage::getNom() const {
    return "plomberie-chauffage";
}
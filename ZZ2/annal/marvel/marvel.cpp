#include "marvel.hpp"

#include <sstream>
#include <iostream>

Personne::Personne(std::string prenom,std::string nom,Genre genre): prenom(prenom),nom(nom),genre(genre) {
}

Personne::Personne(std::string prenom,std::string nom): Personne(prenom,nom,INDETERMINE) {}
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

const Personne Personne::INCONNU(
    "Inconnu",
    "Inconnu",
    Personne::INDETERMINE
);

bool Personne::operator==(const Personne& other) const {
    return prenom == other.prenom
        && nom == other.nom
        && genre == other.genre;
}


std::stringstream& operator<<(std::stringstream& a, const Personne& b) {
    return b.afficher(a);
}

Super::Super(std::string nom,Personne identite): nom(nom), identite(identite) {
    anonyme = true;
}

void Super::enregistrer() {
    anonyme = false;
}

Personne Super::getIdentite() const {
    if (anonyme) {
        throw AnonymeException();
    }
    return identite;
}

void Super::setIdentite(Personne newIdentite) {
    identite = newIdentite;
    anonyme = true;
}

std::stringstream& Materiel::actionner(std::stringstream& ss) {
    utiliser(ss);
    return ss; 
}

std::stringstream& Physique::exercer(std::stringstream& ss) {
    utiliser(ss);
    return ss;
}

std::stringstream& Psychique::penser(std::stringstream& ss) {
    utiliser(ss);
    return ss;
}

Psychique::Psychique(std::string nom,int niveau): Capacite(nom,niveau) {
}

Physique::Physique(std::string nom,int niveau): Capacite(nom,niveau) {
}

Materiel::Materiel(std::string nom,int niveau): Capacite(nom,niveau) {
}

Capacite::Capacite(std::string nom,int niveau): nom(nom),niveau(niveau) {
}
std::stringstream& Materiel::utiliser(std::stringstream& ss) {
    Capacite::utiliser(ss);
    ss << " en action";
    return ss;
}

std::stringstream& Physique::utiliser(std::stringstream& ss) {
    Capacite::utiliser(ss);
    return ss;
}

std::stringstream& Psychique::utiliser(std::stringstream& ss) {
    Capacite::utiliser(ss);
    return ss;
}

void Super::ajouter(Capacite * capa) {
    listCapacite.push_back(capa);
}

int Super::getNiveau() const {
    int niveau= 0;

    std::vector<Capacite *>::const_iterator it = listCapacite.begin();
    while (it != listCapacite.end()) {
        niveau += (*it)->getNiveau();
        it++;
    }
    return niveau;
}

std::stringstream& Capacite::utiliser(std::stringstream& ss) {
    ss << nom << " [" << niveau << "]";
    return ss;
}
Capacite * Capacite::clone() const {
    return new Capacite(this->nom,this->niveau);
}

Materiel * Materiel::clone() const {
    return (Materiel*) Capacite::clone();
}

Physique * Physique::clone() const {
    return (Physique*) Capacite::clone();
}

Psychique * Psychique::clone() const {
    return (Psychique *) Capacite::clone();
}

void Super::setNom(std::string Nom) {
    nom = Nom;
}

Super& Super::operator=(const Super &) {
    return *this;
}

Equipe::Equipe(std::string nom): nom(nom){
}
        
void Equipe::ajouter(Super * super) {
    listSuper.push_back(super);
}
        
int Equipe::getNiveau() const {
    int niveau = 0;
    std::vector<Super *>::const_iterator it = listSuper.begin();
    while (it != listSuper.end()) {
        niveau += (*it)->getNiveau();
        it++;
    }

    return niveau;
}

int Equipe::getNombre() const {
    return listSuper.size();
}
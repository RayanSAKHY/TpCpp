#include "musique.hpp"

int Instrument::compteur = 0;

Personne::Personne(std::string nom, std::string prenom): nom(nom),prenom(prenom) {
}

        
std::string Personne::getNom() const {
    return nom;
}
        
std::string Personne::getPrenom() const{
    return prenom;
}
        
void Personne::setNom(std::string _nom) {
    nom=_nom;
}
        
void Personne::setPrenom(std::string _prenom){
    prenom=_prenom;
}
        
std::ostream& Personne::sePresenter(std::ostream& flux) const{
    flux << "je m'appelle "<<prenom <<" "<< nom << ".";
    return flux;
}

std::ostream& operator<<(std::ostream& flux,const Personne ind){
    ind.sePresenter(flux);
    return flux;
}

const char* ImpossibleException::what() const noexcept {
    return "operation impossible";
}
   
Instrument::Instrument(std::string nom): identifiant(compteur),fonctionnel(true),nom(nom) {
    compteur ++;
}
        
int Instrument::getCompteur() {
    return compteur;
}
        
int Instrument::getIdentifiant() const{
    return identifiant;
}
        
std::string Instrument::getNom() const{
    return nom;
}
        
bool Instrument::isFonctionnel() const{
    return fonctionnel;
}


Violon::Violon(): Instrument("violon") {
}


Piano::Piano(): Instrument("piano") {
}


Flute::Flute(): Instrument("flute") {
}

std::ostream& Violon::jouer(Partition,std::ostream& flux ) {
    if (!isFonctionnel()) {
        throw ImpossibleException();
    }
    flux << "partition jouee par violon";
    return flux;
}

std::ostream& Piano::jouer(Partition,std::ostream& flux ) {
    if (!isFonctionnel()) {
        throw ImpossibleException();
    }
    flux << "partition jouee par piano";
    return flux;
}

std::ostream& Flute::jouer(Partition,std::ostream& flux ) {
    if (!isFonctionnel()) {
        throw ImpossibleException();
    }
    flux << "partition jouee par flute";
    return flux;
}

void Instrument::setFonctionnel(bool fonc) {
    fonctionnel = fonc;
}

Personne::Personne() : Personne("jean","yves") {

}

void Facteur::reviser(Instrument& instru){
    if (typeid(instru)!= typeid(instr)) {
        throw ImpossibleException();
    }

    instru.setFonctionnel(true);
}


std::ostream& Musicien::sePresenter(std::ostream& flux) const {
    Personne::sePresenter(flux);
    flux << " je joue ";

    std::set<std::string> dejaAffiches;
    bool first = true;

    std::set<Instrument*>::iterator it = listInstrument.begin();
    while (it!=listInstrument.end()) {
        std::string nom = (*it)->getNom();
        if (dejaAffiches.insert(nom).second) {
            if (!first) flux << ", ";
            flux << nom;
            first = false;
        }
        it++;
    }
    return flux;
}
        
std::ostream& Musicien::listerInstruments(std::ostream& flux) const{
    for (auto i : listInstrument) {
        flux << i->getNom()
             << " (" << i->getIdentifiant() << ") :\n";
    }
    return flux;
}
        
void Musicien::apprendre(Instrument* instru) {
    listInstrument.insert(instru);
}


Musicien::Musicien(std::string nom,std::string prenom): Personne(nom,prenom) {}

bool Foncteur::operator()(Instrument * instru1, Instrument * instru2) const {
    if (instru1->getNom() != instru2->getNom())
            return instru1->getNom() < instru2->getNom();
        return instru1->getIdentifiant() < instru2->getIdentifiant();
    
}

std::ostream& operator<<(std::ostream& flux,const Musicien& musicien) {
    musicien.Personne::sePresenter(flux);
    flux << "\n" << "je possede :\n";
    musicien.listerInstruments(flux);
    return flux;
}

Musicien::~Musicien() {
    for (auto i : listInstrument) {
        delete i;
    }
}
#include "Telephone.hpp"

Telephone::Telephone(std::string numero,Reseau * reseau): numero(numero),reseau(reseau) {}

Telephone::Telephone(std::string numero): Telephone(numero,nullptr) {
}
Telephone::Telephone(): Telephone("") {}
        
std::string Telephone::getNumero() const {
    return numero;
}
        
void Telephone::setNumero(std::string _numero){
    numero = _numero;
}

bool Telephone::operator<(const Telephone& other) const {
    return numero < other.numero;
}

Reseau * Telephone::getReseau() const {
    return reseau;
}

int Telephone::getNbMessages() const {
    return listMessageEnvoye.size()+listMessageRecu.size();
}
void Telephone::recevoirSMS(SMS message) {
    listMessageRecu.push_back(message);
}

void Telephone::textoter(std::string num,std::string content) {
    if (!reseau) 
        throw std::logic_error("Telephone non connecté à un réseau");
    SMS message(numero,num,"63/63");
    message.setTexte(content);
    listMessageEnvoye.push_back(message);
    try {
        SMS messageA(num,numero,"63/63");
        messageA.setTexte(content);
        reseau->trouveTel(num).recevoirSMS(messageA);
    }
    catch (MauvaisNumero e) {
        std::cout << "Le destiantaire n'existe pas \n" << std::endl; 
    }

}

void Telephone::mmser(std::string expediteur, MMS * mms) {
    if (!reseau) 
        throw std::logic_error("Telephone non connecté à un réseau");
    
    listMessageEnvoye.push_back(*mms);
    try {
        MMS messageA(expediteur,numero,"63/63");
        messageA.setTexte((*mms).getTexte());
        reseau->trouveTel(expediteur).recevoirSMS(messageA);
    }
    catch (MauvaisNumero e) {
        std::cout << "Le destiantaire n'existe pas \n" << std::endl; 
    }
}

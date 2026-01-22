#include "sms.hpp"

std::string SMS::afficher() const {
    return texte;
}

void SMS::setTexte(std::string txt) {
    texte = txt;
}

SMS::SMS(std::string exp,std::string dest, std::string date): Message(exp,dest,date) {

}

std::string SMS::getTexte() const{
    return texte;
}

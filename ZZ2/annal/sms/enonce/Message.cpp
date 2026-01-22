#include "Message.hpp"

int Message::cle = 0;

Message::Message(std::string exp,std::string dest,std::string date): 
    expediteur(exp), 
    destinataire(dest), 
    date(date),
    id(cle){
    cle++;
}

int Message::getCle() {
    return cle;
}

int Message::getId() const {
    return id;
} 

Message::~Message() {
    cle--;
}
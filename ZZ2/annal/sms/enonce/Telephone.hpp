#ifndef __TELEPHONE__HPP__
#define __TELEPHONE__HPP__

#include <iostream>
#include <string>
#include "Reseau.hpp"
#include <vector>
#include "MMS.hpp"

class Reseau;

class Telephone {
    
    private: 
        std::string numero;
        Reseau * reseau;
        std::vector<SMS> listMessageEnvoye;
        std::vector<SMS> listMessageRecu;

    public:
        Telephone(std::string numero,Reseau * reseau);
        Telephone(std::string numero);
        Reseau * getReseau() const;
        Telephone();
        std::string getNumero() const;
        void setNumero(std::string numero);
        bool operator<(const Telephone& other) const;
        int getNbMessages() const;
        void textoter(std::string num,std::string content);
        void recevoirSMS(SMS message);
        void mmser(std::string expediteur, MMS * mms);

};

#endif
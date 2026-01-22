#ifndef __SMS
#define __SMS

#include "Message.hpp"

class SMS : public Message {
    private:
        std::string texte;

    public:
        SMS(std::string exp,std::string dest, std::string date);
        virtual std::string afficher() const override;
        void setTexte(std::string txt);
        std::string getTexte() const;
        

};

#endif
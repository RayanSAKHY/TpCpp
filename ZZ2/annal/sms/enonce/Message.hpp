#ifndef __MESSAGE__HPP__
#define __MESSAGE__HPP__

#include <string>

class Message {
    protected:
        std::string expediteur;
        std::string destinataire;
        std::string date;
        const int id;
        static int cle;
    public:
        Message(std::string exp,std::string dest,std::string date);
        virtual std::string afficher() const = 0;
        static int getCle();
        int getId() const;
        virtual ~Message();
};

#endif
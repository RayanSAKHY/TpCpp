#ifndef __RESEAU__HPP__
#define __RESEAU__HPP__

#include <map>
#include <string>
#include "Telephone.hpp"
#include <exception>

class Telephone;

class Reseau {
    private:
        std::map<std::string,Telephone> listTel;

    public:
        std::string lister() const;
        void ajouter(std::string num);
        const Telephone & trouveTel(std::string num) const;
        Telephone & trouveTel(std::string num);
};

class MauvaisNumero : std::exception {
    public:
        virtual const char * what() const noexcept; 
};
#endif
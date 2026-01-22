#include "Reseau.hpp"

#include <sstream>

std::string Reseau::lister() const {
    std::ostringstream oss;
    for (const auto& pair : listTel) {
        oss << pair.first << "\n";
    }
    return oss.str();
}


void Reseau::ajouter(std::string num) {
    Telephone tel(num,this);
    listTel.insert({num,tel});
}

const Telephone& Reseau::trouveTel(std::string num) const {
    auto it = listTel.find(num);
    if (it == listTel.end()) {
        throw MauvaisNumero();
    }
    return it->second;
}


Telephone& Reseau::trouveTel(std::string num) {
    std::map<std::string,Telephone>::iterator it = listTel.find(num);
    if (it == listTel.end()) {
        throw MauvaisNumero();
    }
    return it->second;
}

const char * MauvaisNumero::what() const noexcept{
    return "mauvais numero";
}
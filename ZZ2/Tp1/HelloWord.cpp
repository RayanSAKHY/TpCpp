#include <iostream>
#include <string>

int main(int, char **) {  // parametres muets
    std::string chaine1;     // type chaines de caracteres"
    std::string chaine2;

    std::cout << "Donnez une première chaine de caractère : ";
    std::cin  >> chaine1;
    std::cout << "Donnez une deuxième chaine de caratère : ";
    std::cin  >> chaine2;

    std::cout << "La chaine de caractère la plus petite est : " << ((chaine1.size()>chaine2.size()) ?chaine2:chaine1 )
    << " et elle contient "<< ((chaine1.size()>chaine2.size()) ?chaine2.size():chaine1.size() ) << " caractères." << std::endl;

    return 0;
}
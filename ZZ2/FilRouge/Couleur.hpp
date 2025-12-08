#ifndef FILROUGE_COULEUR_HPP
#define FILROUGE_COULEUR_HPP

#include <string>
enum class COULEURS{
    BLANC,
    NOIR,
    BLEU,
    VERT,
    ROUGE,
    JAUNE};

std::string chaineCouleur(COULEURS couleur);

#endif //FILROUGE_COULEUR_HPP
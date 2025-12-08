#include "Couleur.hpp"

std::string chaineCouleur(COULEURS couleur)
{
    std::string chaine;
    switch (couleur)
    {
    case COULEURS::BLANC:
        chaine = "BLANC";
        break;
    case COULEURS::NOIR:
        chaine = "NOIR";
        break;
    case COULEURS::BLEU:
        chaine = "BLEU";
        break;
    case COULEURS::VERT:
        chaine = "VERT";
        break;
    case COULEURS::ROUGE:
        chaine = "ROUGE";
        break;
    case COULEURS::JAUNE:
        chaine = "JAUNE";
        break;
    default:
        chaine = "";
        break;
    }
    return chaine;
}
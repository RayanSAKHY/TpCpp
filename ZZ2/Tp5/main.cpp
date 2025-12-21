// fichier cpp pour l'utilisation officielle de la classe Chaine
// pas pour les tests
#include <iostream>
#include "Chaine.hpp"

int main(int, char**) {
	Chaine c("une petite chaine");

	afficherParValeur(c);
	std::cout << std::endl;

	afficherParReference(c);
	std::cout << std::endl;


	return 0;
}
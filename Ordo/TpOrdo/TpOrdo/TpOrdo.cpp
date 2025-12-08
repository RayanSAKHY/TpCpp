// TpOrdo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "graphe.h"

int main()
{
    srand(2);
    int origine = 1;
    int destintion = 6;
    int destination2 = 341;
   /*t_graphe mon_graphe = lire_fichier("graphe.txt");

    t_solution sol = plusCourtChemin(mon_graphe, origine, destintion);


    std::cout << "Longueur du plus court chemin Djikstra : " << sol.cout << endl;

    mon_graphe = genererOrdre(mon_graphe, origine, destintion);
    sol = BellMan(mon_graphe, origine, destintion);

    std::cout << "Longueur du plus court chemin BellMan : " << sol.cout << endl;*/

    /*t_graphe grosGraphe = lire_fichier("grosGraphe.txt");

    grosGraphe = genererOrdre(grosGraphe, origine, destination2);
    t_solution sol2 = BellMan(grosGraphe, origine, destination2);
    std::cout << "Longueur du plus court chemin BellMan : " << sol2.cout << endl;

    sol2 = plusCourtChemin(grosGraphe, origine, destination2);
    std::cout << "Longueur du plus court chemin Djikstra : " << sol2.cout << endl;*/

    t_graphe graphOrdo = lire_fichier("Ordo.txt");
    t_solution sol3 = plusLongChemin(graphOrdo, 1, 14);
    std::cout << "Longueur du plus long chemin : " << sol3.cout << endl;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

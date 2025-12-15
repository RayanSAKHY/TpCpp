// Tp3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Source.h"
#include <cstdlib>
#include <random>

int main()
{

    srand(42);

    //std::cout << "Hello World!\n";

    auto * PTR = new t_probleme{};
    auto * SLT = new t_solution{};
    t_probleme& prob = *PTR;
    t_solution& sol  = *SLT;


    lire_instance("Ex.txt", prob);

    afficherInstance(prob);
    afficherQte(prob);

    plusProcheVoisin(prob, sol);
    std::cout << "Vecteur avec le plus proche voisin : ";
    afficherVecteur(sol, prob);

    plusProcheVoisinRandom(sol, prob);
    std::cout << "Vecteur avec le plus proche voisin randomisé : ";
    afficherVecteur(sol, prob);

    patateHeuristique(sol, prob);
    std::cout << "Vecteur avec la patate heuristique : ";
    afficherVecteur(sol, prob);

    std::cout <<"Excecution d'un split avec un nombre illimité de camion : ";
    if (splitVRPunlimited(prob,sol)) {
        afficherTournees(sol);
    }
    std::cout << "Ameilloration des résultats avec la méthode GRASP : ";
    vndImprove(sol, prob);
    afficherTournees(sol);

    std::cout <<"Excecution d'un split avec un nombre limité de camion : ";
     if (splitVRPLimited(prob,sol)){
            afficherTournees(sol);
    }
    std::cout << "Ameilloration des résultats avec la méthode GRASP : ";
    vndImprove(sol, prob);
    afficherTournees(sol);

    delete PTR;
    delete SLT;
    return 0;
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

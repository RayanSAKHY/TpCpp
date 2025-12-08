// PbOrdo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Source.h"
#include <iostream>
#include <string>
#include <ctime>   
using namespace std;

int main()
{
    srand(1);

    t_probleme prob = {};
    t_solution sol{};

    //Test avec exemple du cours
    /*sol.V[1] = 1;
    sol.V[2] = 1;
    sol.V[3] = 3;
    sol.V[4] = 2;
    sol.V[5] = 3;
    sol.V[6] = 3;
    sol.V[7] = 1;
    sol.V[8] = 2;
    sol.V[9] = 2;*/

    lire_probleme("exCours.txt", prob);
    cout << "Affichage sans recherche locale\n ";
    cout << "Vecteur de solution : ";
    generer_vect(sol, prob);
    afficherVecteur(prob, sol);
    cout << endl;
    evaluer(sol, prob);
    afficherResultat(sol, prob);

    cout << "Affichage avec recherche locale\n ";
    rechercheLocal(sol, prob, 100);
    cout << "Vecteur de solution : ";
    afficherVecteur(prob, sol);
    cout << endl;
    afficherResultat(sol, prob);


    ////Application avec les la...
    //lire_probleme("la01.txt", prob);
    //generer_vect(sol, prob);
    //evaluer(sol, prob);
    //cout << "Test fonction GRASP\n ";
    //GRASP(sol, prob, 100, 100);
    //afficherResultat(sol, prob);

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

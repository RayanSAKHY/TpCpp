#pragma once

#include <fstream>
#include <iostream>
using namespace std;

const int nMax = 342;
const int nSmax = 9;

typedef struct t_graphe {
	int nbNoeud;
	long nbSuccesseur[nMax];
	long listeSuccesseur[nMax][nSmax];
	double ValeurArc[nMax][nSmax];
	long Ordre[nMax];
} t_graphe;

struct t_solution {
	double cout;
	long chemin[nMax];
};

t_graphe grapheInit();

t_solution solInit();

t_graphe lire_fichier(std::string nom);

t_solution plusCourtChemin(t_graphe& le_graphe, long origine, long destination);

t_solution BellMan(t_graphe& le_graphe, long origine, long destination);

t_graphe genererOrdre(t_graphe& graphe,long origine,long destination);

t_solution plusLongChemin(t_graphe& le_graphe, long origine, long destination);
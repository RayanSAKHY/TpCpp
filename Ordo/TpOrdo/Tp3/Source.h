#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <random>



using namespace std;

const int nMax = 175;

typedef struct t_probleme {
	double qte[nMax];
	double distance[nMax][nMax];
	int capa;
	int nbCamion;
	int nbClient;

}t_probleme;

//a utiliser pour le split avec un nombre limité de camion
typedef struct t_label {
	int cout;
	int nbVehiculRestant;
}t_label;

typedef struct t_tournee {
	double cout;
	int liste[nMax];
	double vol;
	int taille;
}t_tournee;

typedef struct t_solution {
	int vecteur[nMax];
	int nbTournee;
	double cout;
	t_tournee listeTournee[nMax];
}t_solution;


void lire_instance(const std::string & nom, t_probleme& un_pb);
void afficherInstance(const t_probleme & prob);
void afficherDistance(const t_probleme & prob);
void afficherQte(const t_probleme & prob);

void plusProcheVoisin(const t_probleme & prob,t_solution& sol);
void plusProcheVoisinRandom(t_solution& sol, const t_probleme& pro);
void patateHeuristique(t_solution& sol, const t_probleme & prob);
void afficherVecteur(const t_solution & sol, const t_probleme & prob);

double coutTournee(const t_probleme& prob, const int * seq,int taille);
void calculeCoutSolution(const t_probleme& prob, t_solution& sol);
void afficherTournees(const t_solution& sol);

bool twoOptRoute(t_tournee& r, const t_probleme& prob, int maxIter);
bool relocateOneCustomer(t_solution& sol, const t_probleme& prob,int& nbMoves, int maxMoves, double EPS);
bool swapTwoCustomers(t_solution& sol, const t_probleme& prob,int& nbSwap, int maxSwap,double EPS);void vndImprove(t_solution& sol, const t_probleme& prob,
				int maxVNDIter = 2000,
				int maxOptIter = 200,
				int maxMoves=5000,
				int maxSwap = 3000,
				int stallLimit = 300,
				int EPS=0);


// ----- Garde-fous / recalculs -----
void recomputeRoute(const t_probleme& prob, t_tournee& r);
void normalizeSolution(const t_probleme& prob, t_solution& sol);
bool checkFeasibility(const t_probleme& prob, const t_solution& sol);


bool splitVRPunlimited(const t_probleme & prob, t_solution & sol);
bool splitVRPLimited(const t_probleme& prob, t_solution& sol);

bool checkCoverage(const t_probleme& prob, const t_solution& sol, bool verbose = false);
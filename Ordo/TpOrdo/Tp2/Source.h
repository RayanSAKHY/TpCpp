#include <iostream>
#include<fstream>
#include <string>
using namespace std;

const int pMax = 21;
const int mMax = 11;
const int K = 4999;


typedef struct t_probleme {
	int nbPiece; 
	int nbMachine; 
	int processing[pMax][pMax];
	int machine[pMax][pMax];

}t_probleme;

typedef struct t_couple {
	int i;
	int j;
}t_couple;

typedef struct t_solution {
	int V[pMax * mMax];
	int cout;
	int date[pMax][pMax]; 
	t_couple pred[pMax][pMax]; 
}t_solution;


void lire_probleme(std::string nom, t_probleme& un_pb);
void generer_vect(t_solution& une_sol, t_probleme un_pb);
void afficherVecteur(t_probleme graphe, t_solution solution);
void evaluer(t_solution& une_sol, t_probleme un_pb);
void afficherResultat(const t_solution& sol, const t_probleme& pb);

t_couple trouverDernierSommet(t_solution une_sol, t_probleme un_pb);
int trouverPositionCouple(t_solution une_sol, t_couple couple, t_probleme un_pb);
void rechercheLocal(t_solution& une_sol, t_probleme un_pb, int itermax);
void genererVoisin(const t_solution& sol, t_solution& voisin, const t_probleme& pb);
void GRASP(t_solution& une_sol, t_probleme un_pb, int nbVoi, int nbCas);
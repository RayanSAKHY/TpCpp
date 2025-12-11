#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "graphe.h"


t_graphe grapheInit() {
	t_graphe le_graphe = {0,};
	int i = 0, j = 0;
	le_graphe.nbNoeud = 0;
	le_graphe.nbSuccesseur[0] = 0;
	for (i = 1;i < nMax;i++) {
		le_graphe.nbSuccesseur[i] = 0;
		le_graphe.Ordre[0] = 0;
		le_graphe.Ordre[i] = 0;
		for (j = 1;j <nSmax;j++) {
			le_graphe.listeSuccesseur[0][j] = 0;
			le_graphe.ValeurArc[0][j] = 9999;
			le_graphe.listeSuccesseur[i][j] = 0;
			le_graphe.ValeurArc[i][j] = 9999;
		}
	}
	return le_graphe;
}

t_solution solInit() {
	t_solution sol = { 0, };
	int i = 0;
	sol.cout = 0;
	for (i = 0;i < nMax;i++) {
		sol.chemin[i] = 0;
	}
	return sol;
}

t_graphe 
lire_fichier(std::string nom) {
	ifstream fichier(nom, ios::in);

	t_graphe le_graphe=grapheInit();
	if ( !fichier.is_open() ) {
		std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
	}
	int i = 0;
	int j = 0;
	int valeur=0;
	long nb_succ_du_sommet_i=0;
	long dest=0;
	double cout_arc = 0;
	fichier >> valeur;
	//cout << "valeur lue : " << valeur << endl;
	if (valeur < nMax) {
		le_graphe.nbNoeud = valeur;
		for (i = 1;i <= valeur;i++) {
			fichier >> nb_succ_du_sommet_i;
			le_graphe.nbSuccesseur[i] = nb_succ_du_sommet_i;
			for (j = 1; j <= nb_succ_du_sommet_i; j++) {
				fichier >> dest;
				fichier >> cout_arc;
				le_graphe.listeSuccesseur[i][j] = dest;
				le_graphe.ValeurArc[i][dest] = cout_arc;
			}
		}
	}
	else {
		std::cout << "Le graphe " << nom << " est trop gros" << endl;
	}
	fichier.close();
	//std::cout << "Lecture fini" << endl;
	return le_graphe;
}

t_solution plusCourtChemin(t_graphe& le_graphe, long origine, long destination) {
	double marque[nMax]{};
	long visite[nMax]{};
	long pere[nMax]{};
	int i = 1,j = 1;
	double valMin = 9999.;
	long noeudMin = origine;
	long nbSucc=0;
	long succ=-1;
	double cout_arc = 0.0;
	t_solution solus = solInit();
	for (i = 0;i < nMax;i++) {
		marque[i] = 9999.;
		visite[i] = 0;
		pere[i] = 0;
	}

	marque[origine] = 0;
	//std::cout << "Debut de la recherche de chemin" << endl;
	solus.chemin[0] = origine;
	for (i = 1;i <= le_graphe.nbNoeud;i++) {

		for (j = 1;j <= le_graphe.nbNoeud;j++) {
			if ((visite[j] == 0) && (marque[j] < valMin)) {
				valMin = marque[j];
				noeudMin = j;
			}
		}

		nbSucc = le_graphe.nbSuccesseur[noeudMin];
		for (j = 1;j <= nbSucc;j++) {
			succ = le_graphe.listeSuccesseur[noeudMin][j];
			cout_arc = le_graphe.ValeurArc[noeudMin][succ];
			if (marque[noeudMin] + cout_arc < marque[succ]) {
				marque[succ] = marque[noeudMin] + cout_arc;
				pere[succ] = noeudMin;
			}
		}
		visite[noeudMin] = 1;
		noeudMin++;
		//std::cout << "val noeud min " << marque[noeudMin] << endl;
	}

	solus.cout = marque[destination];
	//std::cout << "cout trouve : " << solus.cout << endl;
	i = destination;
	j = 0;
	std::cout << "Chemin : ";
	while (pere[i] != 0) {
		solus.chemin[j] = i;
		std::cout << i << " ";
		j++;
		i = pere[i];
	}
	std::cout << i << " ";
	std::cout << endl;
	return solus;
}

t_solution BellMan(t_graphe& le_graphe, long origine, long destination) {
	double marque[nMax]{};
	long pere[nMax]{};
	int i = 1, j = 1;
	long valMin = 9999;
	long noeudMin = origine;
	long nbSucc = 0;
	long succ = -1;
	double cout_arc = 0;
	int stop = 0;
	int nbNoeud = le_graphe.nbNoeud;
	int temp=0;
	int nbTour = 0;
	t_solution solus = solInit();
	for (i = 0;i < nMax;i++) {
		marque[i] = 9999.;
		pere[i] = 0;
	}

	

	marque[origine] = 0;
	solus.chemin[0] = origine;
	while (stop==0){
		stop = 1;
		for (i = 1;i <= nbNoeud;i++) {
			noeudMin = le_graphe.Ordre[i - 1];
			nbSucc = le_graphe.nbSuccesseur[noeudMin];
			for (j = 1;j <= nbSucc;j++) {
				succ = le_graphe.listeSuccesseur[noeudMin][j];
				cout_arc = le_graphe.ValeurArc[noeudMin][succ];
				if (marque[noeudMin] + cout_arc < marque[succ]) {
					marque[succ] = marque[noeudMin] + cout_arc;
					pere[succ] = noeudMin;
					stop = 0;
				}
			}
			noeudMin=le_graphe.Ordre[i-1];
			//std::cout << "val noeud min " << marque[noeudMin] << endl;
		}
		nbTour++;

	}

	std::cout << "Nombre de tour de boucle : " << nbTour << endl;
	solus.cout = marque[destination];
	//std::cout << "cout trouve : " << solus.cout << endl;
	i = destination;
	j = 0;
	std::cout << "Chemin : ";
	while (pere[i] != 0) {
		solus.chemin[j] = i;
		std::cout << i << " ";
		j++;
		i = pere[i];
	}
	std::cout << i << " ";
	std::cout << endl;
	return solus;
}

t_graphe genererOrdre(t_graphe& graphe,long origine,long destination) {
	long visite[nMax]{};
	int i = 1;
	int nbNoeud = graphe.nbNoeud;
	int temp=0;
	visite[1] = 1;
	visite[nbNoeud] = 1;
	graphe.Ordre[0] = origine;
	graphe.Ordre[nbNoeud-1] = destination;
	for (i = 1;i < nbNoeud - 1;i++) {
		temp = rand() % (nbNoeud - 1) + 1;
		while (visite[temp] != 0) {
			temp = rand() % (nbNoeud - 1) + 1;
		}
		graphe.Ordre[i] = temp;
		visite[temp] = 1;
	}
	return graphe;
}

t_solution plusLongChemin(t_graphe& le_graphe, long origine, long destination) {
	double marque[nMax]{};
	long visite[nMax]{};
	long pere[nMax]{};
	int i = 1, j = 1;
	double valMax = 0.;
	long noeudMax = origine;
	long nbSucc = 0;
	long succ = -1;
	double cout_arc = 0.0;
	t_solution solus = solInit();
	for (i = 0;i < nMax;i++) {
		marque[i] = 0.;
		visite[i] = 0;
		pere[i] = 0;
	}

	marque[origine] = 0;
	//std::cout << "Debut de la recherche de chemin" << endl;
	solus.chemin[0] = origine;
	for (i = 1;i <= le_graphe.nbNoeud;i++) {

		for (j = 1;j <= le_graphe.nbNoeud;j++) {
			if ((visite[j] == 0) && (marque[j] > valMax)) {
				valMax = marque[j];
				noeudMax = j;
			}
		}

		nbSucc = le_graphe.nbSuccesseur[noeudMax];

		for (j = 1;j <= nbSucc;j++) {
			succ = le_graphe.listeSuccesseur[noeudMax][j];
			cout_arc = le_graphe.ValeurArc[noeudMax][succ];
			if (marque[noeudMax] + cout_arc > marque[succ]) {
				marque[succ] = marque[noeudMax] + cout_arc;
				pere[succ] = noeudMax;
			}
		}
		visite[noeudMax] = 1;
		noeudMax++;
		//std::cout << "val noeud min " << marque[noeudMin] << endl;
	}

	solus.cout = marque[destination];
	//std::cout << "cout trouve : " << solus.cout << endl;
	i = destination;
	j = 0;
	std::cout << "Chemin : ";
	while (pere[i] != 0) {
		solus.chemin[j] = i;
		std::cout << i << " ";
		j++;
		i = pere[i];
	}
	std::cout << i << " ";
	std::cout << endl;
	return solus;
}
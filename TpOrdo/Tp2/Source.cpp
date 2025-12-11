#include "Source.h"
#include <vector>


void lire_probleme(std::string nom, t_probleme& prob) {

	ifstream fichier(nom, ios::in);
	if (!fichier.is_open()) {
		std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
		return;
	}

	int valeur = 0;
	int machine = 0;
	int time = 0;
	int i = 0;
	int j = 0;
	fichier >> valeur;
	prob.nbPiece = valeur;
	fichier >> valeur;
	prob.nbMachine = valeur;

	for (i = 1; i <= prob.nbPiece; i++) {
		for (j = 1; j <= prob.nbMachine;j++) {
			fichier >> machine;
			fichier >> time;
			prob.processing[i][j] = time;
			prob.machine[i][j] = machine + 1;
		}
	}
	cout << endl;
	fichier.close();
}

void generer_vect(t_solution& sol, t_probleme prob) {
	int T[pMax]{}; //nb de fois qu'il reste a placer le nombre
	int N[pMax]{}; //chiffre possible à placer
	int t_vect = prob.nbPiece * prob.nbMachine;
	int nl = prob.nbPiece;
	int j = 0;
	int i = 0;
	int k = 0;

	for (j = 1; j <= prob.nbPiece; j++) {
		T[j] = prob.nbMachine;
		N[j] = j;
	}
	for (k = 1; k <= t_vect; k++) {
		i = rand() % nl + 1;
		sol.V[k] = N[i];
		T[i] -= 1;
		if (T[i] == 0) {
			T[i] = T[nl];
			N[i] = N[nl];
			nl -= 1;
		}
	}
}


void evaluer(t_solution& sol, t_probleme prob) {
	int np[pMax]{ 0 };
	int num_mach[mMax]{ 0 };
	t_couple pm[mMax]{};
	int i = 0;
	int j = 0;
	int t_vect = prob.nbPiece * prob.nbMachine;
	int rg_pr = 0;
	int d = 0;
	int machine = 0;
	int k = 0;
	int u = 0;

	for (i = 1; i <= prob.nbPiece; i++) {
		for (j = 1; j <= prob.nbMachine; j++) {
			sol.date[i][j] = 0;
			sol.pred[i][j].i = 0;
			sol.pred[i][j].j = 0;
		}
	}
	sol.cout = 0;

	

	for (i = 1; i <= t_vect; i++) {
		j = sol.V[i];
		np[j]++;
		if (np[j] > 1) {

			rg_pr = np[j] - 1;
			d = sol.date[j][rg_pr] + prob.processing[j][rg_pr];
			if (d > sol.date[j][np[j]]) {
				sol.date[j][np[j]] = d;
				sol.pred[j][np[j]].i = j;
				sol.pred[j][np[j]].j = np[j] - 1;
			}

		}

		machine = prob.machine[j][np[j]];
		num_mach[machine]++;
		if (num_mach[machine] > 1) {
			k = pm[machine].i;
			u = pm[machine].j;
			if (sol.date[k][u] + prob.processing[k][u] > sol.date[j][np[j]]) {
				sol.date[j][np[j]] = sol.date[k][u] + prob.processing[k][u];
				sol.pred[j][np[j]].i = k;
				sol.pred[j][np[j]].j = u;
			}
		}
		pm[machine].i = j;
		pm[machine].j = np[j];

	}
	for (k = 1; k <= prob.nbPiece; k++) {
		if (sol.date[k][prob.nbMachine] + prob.processing[k][prob.nbMachine] > sol.cout) {
			sol.cout = sol.date[k][prob.nbMachine] + prob.processing[k][prob.nbMachine];
			sol.pred[prob.nbPiece][prob.nbMachine].i = k;
			sol.pred[prob.nbPiece][prob.nbMachine].j = prob.nbMachine;
		}
	}
}


void afficherVecteur(t_probleme graphe, t_solution solution) {
	int i = 0;

	for (i = 1; i <= graphe.nbPiece * graphe.nbMachine; i++) {
		cout << solution.V[i] << " ";
	}
}

void afficherResultat(const t_solution& sol, const t_probleme& prob) {
	int i = 0, j = 0;
	std::cout << "\nCout total : " << sol.cout << std::endl;
	std::cout << "Dates d'achevement : \n";

	for (i = 1; i <= prob.nbPiece; i++) {
		cout << "Job " << i << " : ";
		for (j = 1; j <= prob.nbMachine; j++) {
			cout << sol.date[i][j] << " ";
			if (j < prob.nbMachine) cout << " | ";
		}
		cout << endl;
	}

	cout << endl;
}


t_couple trouverDernierSommet(t_solution sol, t_probleme prob) {
	t_couple dernier{};
	dernier.i = 0;
	dernier.j = 0;
	int i = 0;
	int j = 0;
	int fin = 0;

	int max_fin = -1;

	for (i = 1; i <= prob.nbPiece; i++) {
		for (j = 1; j <= prob.nbMachine; j++) {
			fin = sol.date[i][j] + prob.processing[i][j];
			if (fin > max_fin) {
				max_fin = fin;
				dernier.i = i;
				dernier.j = j;
			}
		}
	}

	return dernier;
}


int trouverPositionCouple(t_solution sol, t_couple couple, t_probleme prob) {
	int compteur = 0;
	int t_vect = prob.nbPiece * prob.nbMachine;
	int k = 0;

	for (k = 1; k <= t_vect; k++) {
		if (sol.V[k] == couple.i) { // même pièce
			compteur++;
			if (compteur == couple.j) {
				return k; // trouvé : la j-ième opération de cette pièce
			}
		}
	}
	return -1;
}


void rechercheLocal(t_solution& sol, t_probleme prob, int itermax) {
	evaluer(sol, prob);
	t_solution temp{};
	temp = sol;
	int posj = 0;
	int posk = 0;
	int tmp = 0;

	int iter = 0;
	t_couple j = trouverDernierSommet(sol, prob);
	t_couple k = sol.pred[j.i][j.j];

	while ((k.i != 0 || k.j != 0) && (iter < itermax)) {
		if (prob.machine[j.i][j.j] != prob.machine[k.i][k.j]) {
			j = k;
			k = sol.pred[j.i][j.j];
		}
		else {
			posk = trouverPositionCouple(sol, k, prob);
			posj = trouverPositionCouple(sol, j, prob);
			tmp = temp.V[posj];
			temp.V[posj] = temp.V[posk];
			temp.V[posk] = tmp;
			evaluer(temp, prob);
			if (temp.cout < sol.cout) {
				sol = temp;
				j = trouverDernierSommet(sol, prob);
				k = sol.pred[j.i][j.j];
			}
			else {
				j = k;
				k = sol.pred[j.i][j.j];
			}
		}
		iter++;
		/*cout << "New vecteur :" << endl;
		afficherVecteur(prob, sol);*/
	}
}


void genererVoisin(const t_solution& sol, t_solution& voisin, const t_probleme& prob) {
	voisin = sol;
	int t_vect = prob.nbPiece * prob.nbMachine;

	// choisir deux positions aléatoires différentes
	int a = rand() % t_vect + 1;
	int b = rand() % t_vect + 1;
	while (b == a) b = rand() % t_vect + 1;

	// échanger les deux opérations
	int tmp = voisin.V[a];
	voisin.V[a] = voisin.V[b];
	voisin.V[b] = tmp;
}

int hashage(t_solution sol,t_probleme prob) {
	int somme = 0;
	int i = 0, j = 0;

	for (i = 1;i <= prob.nbPiece;i++) {
		for (j = 1; j <= prob.nbMachine; j++) {
			somme += sol.date[i][j] *sol.date[i][j];
		}
	}
	return somme % K;
}

void GRASP(t_solution& sol, t_probleme prob, int nbVoisin, int nbCas) {
	rechercheLocal(sol, prob, 100);
	int i = 0;
	t_solution courant{}, voisin{}, bestVoisin{};
	int T[K] = {};
	courant = sol;
	int v = 0;

	while (i < nbCas) {
		genererVoisin(courant, voisin, prob);
		rechercheLocal(voisin, prob, 100);
		bestVoisin = voisin;
		for (v = 1; v < nbVoisin; v++) {
			genererVoisin(courant, voisin, prob);
			rechercheLocal(voisin, prob, 100);
			if (voisin.cout < bestVoisin.cout) bestVoisin = voisin;
		}
		courant = bestVoisin;
		i++;
	}
	sol = courant;
}
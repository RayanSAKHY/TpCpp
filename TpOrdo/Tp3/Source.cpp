#include "Source.h"
#include <utility>
#include <fstream>

void lire_instance(const std::string & nom, t_probleme& un_pb) {
	int i,j;
	ifstream fichier(nom);
	if (!fichier.is_open()) {
		cerr << "Erreur d'ouverture: " << nom << endl;
		return;
	}

	// Lire taille flotte et capacité
	fichier >> un_pb.nbClient >> un_pb.nbCamion >> un_pb.capa;


	// Sécuriser
	if (un_pb.nbClient >= nMax) {
		cerr << "nbClient > nMax (" << nMax << "), réduisez l'instance.\n";
		return;
	}



	// Init
	for (i = 0; i < nMax; ++i) un_pb.qte[i] = 0;
	for (i = 0; i < nMax; ++i)
		for (j = 0; j < nMax; ++j)
			un_pb.distance[i][j] = (i == j ? 0 : 999999);



	// Matrice des distances : 0..nbClient
	for (i = 0; i <= un_pb.nbClient; ++i)
		for (j = 0; j <= un_pb.nbClient; ++j)
			fichier >> un_pb.distance[i][j];

	// Demandes : 1..nbClient
	for (i = 1; i <= un_pb.nbClient; ++i) {
		fichier >> un_pb.qte[i];
	}

	fichier.close();

}

void afficherInstance(const t_probleme& prob) {
	std::cout << "Nombre de ville : " << prob.nbClient << std::endl;
	std::cout << "Nombre de camion : " << prob.nbCamion << std::endl;
	std::cout << "Capacité des camions : " << prob.capa << std::endl;
}

void afficherDistance(const t_probleme & prob) {
	std::cout << "Tableau des distances : " << std::endl;
	for (int i = 0;i <= prob.nbClient;i++) {
		for (int j = 0;j <= prob.nbClient;j++) {
			std::cout << prob.distance[i][j] << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void afficherQte(const t_probleme & prob) {
	std::cout << "Tableau des quantités par ville : " << std::endl;
	for (int i = 1;i <= prob.nbClient;i++) {
		std::cout <<"Ville : " << i << " Qte : " << prob.qte[i] << std::endl;
	}
	std::cout << std::endl;

}

void afficherVecteur(const t_solution & sol, const t_probleme & prob) {

	for (int i = 1;i <= prob.nbClient;i++) {
		std::cout << sol.vecteur[i] << " ";
	}std::cout << std::endl;
}

void plusProcheVoisin(const t_probleme& prob, t_solution& sol) {
	// Visités
	bool vis[nMax] = {false};
	sol.vecteur[0] = 0;
	vis[0] = true;


	for (int i = 1; i <= prob.nbClient; ++i) {
		const int prev = sol.vecteur[i - 1];
		int best = -1;
		double bestDist = 999999;

		for (int j = 1; j <= prob.nbClient; ++j) {
			if (!vis[j] && prob.distance[prev][j] < bestDist) {
				bestDist = prob.distance[prev][j];
				best = j;
			}
		}
		sol.vecteur[i] = best;
		vis[best] = true;
	}
}

void plusProcheVoisinRandom(t_solution& sol, const t_probleme & prob) {
	int L[nMax]{};
	const int nbElt = prob.nbClient;
	int nbEltL = nbElt;
	sol.vecteur[0] = 0;


	for (int i = 1;i <= nbElt;i++) {
		L[i] = i;
	}

	for (int i = 1;i <= nbElt; i++) {
		const int x = sol.vecteur[i - 1];


		// Taille effective de la RCL : min(nb, nbEltL), au moins 1
		int rclSize = 4;
		if (rclSize > nbEltL) rclSize = nbEltL;
		if (rclSize < 1)      rclSize = 1;

		int c = 0;
		int EPos[4];
		double EDist[4];

		for (int t = 0;t < 4;t++) {
			EDist[t] = 9999;
			EPos[t]=-1;
		}

		//rechercher nb minimum
		for (int k = 1;k <= nbEltL;k++) {
			const double d = prob.distance[x][L[k]];


			int pos;
			if (c < rclSize) {
				// RCL pas pleine : ajouter puis remonter par insertion
				pos = c;
				EDist[pos] = d;
				EPos[pos]  = k;   // position dans L
				++c;
			} else if (d < EDist[rclSize - 1]) {
				// RCL pleine : meilleur que le pire -> remplacer le dernier
				pos = rclSize - 1;
				EDist[pos] = d;
				EPos[pos]  = k;
			} else {
				continue; // trop mauvais pour entrer dans le top-k
			}

			// Tri par insertion local (maintenir ordre croissant EDist/EPos)
			while (pos > 0 && EDist[pos] < EDist[pos - 1]) {
				const double td = EDist[pos - 1];
				const int tp = EPos[pos - 1];
				EDist[pos - 1] = EDist[pos];
				EPos[pos - 1]  = EPos[pos];
				EDist[pos] = td;
				EPos[pos]  = tp;
				--pos;
			}
		}

		// Sécurité : si pour une raison étrange la RCL est vide
		if (c == 0) {
			// choisir le premier restant
			sol.vecteur[i] = L[1];
			L[1] = L[nbEltL];
			--nbEltL;
			continue;
		}

		const int nbAlea = rand() % c;


		// Position réelle dans L et client choisi
		const int posInL = EPos[nbAlea];        // 1..nbEltL
		const int chosen = L[posInL];

		sol.vecteur[i] = chosen;

		// Retirer le client de L (swap avec le dernier)
		if (posInL != nbEltL) {
			L[posInL] = L[nbEltL];
		}
		--nbEltL;
	}
}

void patateHeuristique(t_solution& sol, const t_probleme& prob) {
    const int nbElt = prob.nbClient;
    sol.vecteur[0] = 0; // départ dépôt

    // Liste des clients restants : L[1..nbLeft]
    int L[nMax]{};
    int nbLeft = nbElt;

    for (int i = 1; i <= nbElt; ++i) {
	    L[i] = i;
    }
    // Paramètres de RCL (tu peux ajuster)

    for (int i = 1; i <= nbElt; ++i) {
        const int x = sol.vecteur[i - 1];

        // Construire les buffers distances/positions pour les restants
        // distBuf[1..nbLeft], posBuf[1..nbLeft]
        double distBuf[nMax];
        int posBuf[nMax];
        for (int t = 1; t <= nbLeft; ++t) {
            distBuf[t] = prob.distance[x][L[t]];
            posBuf[t]  = t; // position dans L
        }

        // Tri insertion ascendant sur (distBuf, posBuf)
        for (int a = 2; a <= nbLeft; ++a) {
            const double kd = distBuf[a];
            const int kp = posBuf[a];
            int b = a - 1;
            while (b >= 1 && distBuf[b] > kd) {
                distBuf[b + 1] = distBuf[b];
                posBuf[b + 1]  = posBuf[b];
                --b;
            }
            distBuf[b + 1] = kd;
            posBuf[b + 1]  = kp;
        }

        // Choix du mode : première moitié → proches, seconde moitié → éloignés
        const bool chooseClose = (i <= nbElt / 2);

        // Construire la RCL : positions dans L (pas les clients)
        int rclPos[nMax];
        int rclCount = 0;

        if (chooseClose) {
	        constexpr int kClose = 4;
	        // Prendre les kClose premiers (les plus proches)
            const int take = (kClose < nbLeft ? kClose : nbLeft);
            for (int idx = 1; idx <= take; ++idx) rclPos[rclCount++] = posBuf[idx];
        } else {
	        constexpr int kFar   = 4;
	        // Prendre les kFar derniers (les plus éloignés)
            const int take = (kFar < nbLeft ? kFar : nbLeft);
            for (int idx = nbLeft - take + 1; idx <= nbLeft; ++idx) rclPos[rclCount++] = posBuf[idx];
        }
        if (rclCount == 0) { // garde-fou
            rclPos[rclCount++] = posBuf[1];
        }

        // Tirage uniforme d'un indice dans la RCL
        const int nbAlea = rand() % rclCount;
        // Si tu utilises mt19937 :
        // std::uniform_int_distribution<int> dist(0, rclCount - 1);
        // int idx = dist(rng);

        // Position réelle dans L et client choisi
        const int posInL = rclPos[nbAlea];  // 1..nbLeft
        const int chosen = L[posInL];

        // Écrire dans le vecteur
        sol.vecteur[i] = chosen;

        // Retirer chosen de L (swap avec le dernier)
        if (posInL != nbLeft) L[posInL] = L[nbLeft];
        --nbLeft;
    }
}


double coutTournee(const t_probleme& prob, const int * seq,int taille) {
	if (taille <= 0) return 0;
	double c = 0.0;
	// dépôt -> premier
	c += prob.distance[0][seq[0]];
	// liens internes
	for (int i = 0; i < taille - 1; ++i) {
		c += prob.distance[seq[i]][seq[i + 1]];
	}
	// dernier -> dépôt
	c += prob.distance[seq[taille - 1]][0];
	return c;
}

void calculeCoutSolution(const t_probleme& prob, t_solution& sol) {
	double total = 0;
	for (int k = 0; k < sol.nbTournee; ++k) {
		t_tournee& r = sol.listeTournee[k];
		r.cout = coutTournee(prob, r.liste,r.taille);
		total += r.cout;
	}
	sol.cout = total;
}


// Recalcule vol et cout pour UNE tournée à partir de sa liste.
// Si taille==0, vol=0 et cout=0 (mais c'est à l'appelant de SUPPRIMER la tournée pour respecter l'invariant A)
void recomputeRoute(const t_probleme& prob, t_tournee& r) {
    // Recalcul du volume
    double vol = 0;
    for (int i = 0; i < r.taille; ++i) {
        vol += prob.qte[ r.liste[i] ];
    }
    r.vol = vol;

    // Recalcul du coût
    if (r.taille <= 0) {
        r.cout = 0;
        return;
    }
    double c = 0;
    c += prob.distance[0][ r.liste[0] ];
    for (int i = 0; i < r.taille - 1; ++i) c += prob.distance[ r.liste[i] ][ r.liste[i+1] ];
    c += prob.distance[ r.liste[r.taille - 1] ][0];
    r.cout = c;
}


// Supprime TOUTES les tournées vides et compacte la solution.
// Recalcule aussi vol & cout de chaque tournée restante, et met à jour sol.cout.
void normalizeSolution(const t_probleme& prob, t_solution& sol) {
    // 1) supprimer tournées vides
    int write = 0;
    for (int read = 0; read < sol.nbTournee; ++read) {
        const t_tournee& r = sol.listeTournee[read];
        if (r.taille > 0) {
            // recopier si besoin
            if (write != read) sol.listeTournee[write] = r;
            ++write;
        }
    }
    sol.nbTournee = write;

    // 2) recompute vol/cout pour toutes les tournées restantes
    double total = 0;
    for (int k = 0; k < sol.nbTournee; ++k) {
        recomputeRoute(prob, sol.listeTournee[k]);
        total += sol.listeTournee[k].cout;
    }
    sol.cout = (double)total;
}

// Garde-fou : vérifie la faisabilité
bool checkFeasibility(const t_probleme& prob, const t_solution& sol) {
    // pas de tournée vide
    for (int k = 0; k < sol.nbTournee; ++k) {
        const t_tournee& r = sol.listeTournee[k];
        if (r.taille <= 0) return false;
    }
    // capacité
    for (int k = 0; k < sol.nbTournee; ++k) {
        const t_tournee& r = sol.listeTournee[k];
        double vol = 0;
        for (int i = 0; i < r.taille; ++i) vol += prob.qte[ r.liste[i] ];
        if (vol != r.vol) return false;
        if (vol > prob.capa) return false;
    }
    // coût non négatif
    for (int k = 0; k < sol.nbTournee; ++k) {
        const t_tournee& r = sol.listeTournee[k];
        if (r.cout < 0) return false;
    }
    // nbTournee cohérent
    if (sol.nbTournee < 1) return false;
    return true;
}


void afficherTournees(const t_solution& sol) {
	std::cout << "Nb tournées = " << sol.nbTournee
			  << ", coût total = " << std::fixed << sol.cout << "\n";
	for (int k = 0; k < sol.nbTournee; ++k) {
		const t_tournee& r = sol.listeTournee[k];
		if (r.taille <= 0) continue; // ignorer toute tournée vide
		std::cout << "  T" << (k+1)
				  << " (vol=" << r.vol << ", cout=" << r.cout << "): 0 -> ";
		for (int i = 0; i < r.taille; ++i) std::cout << r.liste[i] << " -> ";
		std::cout << "0\n";
	}
	std::cout << std::endl;
}


bool splitVRPunlimited(const t_probleme & prob, t_solution & sol) {

	const int n = prob.nbClient;

	constexpr int INF = 10000000;

	if (n <= 0) return false;


	// 1) ORD : ordre des clients sans le dépôt (indices 1..n)
	int ord[nMax];
	for (int i = 1; i <= n; ++i) ord[i] = sol.vecteur[i];

	// 2) PREF : préfixes de demandes (indices 0..n)
	double pref[nMax];
	pref[0] = 0;
	for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + prob.qte[ ord[i] ];

	// 3) COST[i][j] (indices 1..n) — coût du segment i..j (dépôt -> ORD[i] ... ORD[j] -> dépôt)
	double cost[nMax][nMax];
	for (int i = 0; i < nMax; ++i)
		for (int j = 0; j < nMax; ++j)
			cost[i][j] = INF;

	for (int i = 1; i <= n; ++i) {
		const double c_depot_to_first = prob.distance[0][ ord[i] ];
		double c_chain = 0.0; // somme des arêtes internes ORD[i]->ORD[i+1]->...

		for (int j = i; j <= n; ++j) {
			const double vol = pref[j] - pref[i - 1];
			if (vol > prob.capa) break; // plus faisable au-delà
			if (j > i) c_chain += prob.distance[ ord[j-1] ][ ord[j] ];
			const double c = c_depot_to_first + c_chain + prob.distance[ ord[j] ][0];
			cost[i][j] = c;

		}
	}

	// 4) DP[j] + PARENT[j] — meilleur coût pour couvrir 1..j
	double dp[nMax];
	int parent[nMax];
	for (int j = 0; j <= n; ++j) { dp[j] = INF; parent[j] = -1; }
	dp[0] = 0;

	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= j; ++i) {
			if (cost[i][j] == INF) continue;
			const double val = dp[i - 1] + cost[i][j];
			if (val < dp[j]) {
				dp[j] = val;
				parent[j] = i;
			}
		}
		if (parent[j] == -1) {
			// impossible (demande > capacité d'un seul véhicule)
			return false;
		}
	}


	// Reconstruction des tournées
	int k = 0;
	int j = n;
	while (j > 0) {
		int i = parent[j];
		t_tournee& r = sol.listeTournee[k];
		r.taille = 0;
		r.vol = 0;
		for (int u = i; u <= j; ++u) {
			r.liste[r.taille++] = ord[u];
			r.vol += prob.qte[ord[u]];
		}
		r.cout = coutTournee(prob, r.liste, r.taille);
		++k;
		j = i - 1;
	}



	// Remettre les tournées dans l'ordre (on les a créées de la fin vers le début)
	for (int a = 0, b = k - 1; a < b; ++a, --b) {
		const t_tournee tmp = sol.listeTournee[a];
		sol.listeTournee[a] = sol.listeTournee[b];
		sol.listeTournee[b] = tmp;
	}


	sol.nbTournee = k;
	sol.cout = dp[n];
	return true;
}


bool splitVRPLimited(const t_probleme& prob, t_solution& sol) {

	const int n   = prob.nbClient;
	const int K   = prob.nbCamion;   // flotte limitée
	constexpr int INF = 10000000;

	if (n <= 0 || K <= 0) return false;

	// 1) ORD
	int ord[nMax];
	for (int i = 1; i <= n; ++i) ord[i] = sol.vecteur[i];

	// 2) PREF
	double pref[nMax];
	pref[0] = 0;
	for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + prob.qte[ ord[i] ];

	// 3) COST[i][j]
    double cost[nMax][nMax];
    for (int i = 0; i < nMax; ++i)
        for (int j = 0; j < nMax; ++j)
            cost[i][j] = INF;

	for (int i = 1; i <= n; ++i) {
		const double c_depot_to_first = prob.distance[0][ ord[i] ];
		double c_chain = 0;
		for (int j = i; j <= n; ++j) {
			const double vol = pref[j] - pref[i - 1];
			if (vol > prob.capa) break;
			if (j > i) c_chain += prob.distance[ ord[j-1] ][ ord[j] ];
			const double c = c_depot_to_first + c_chain + prob.distance[ ord[j] ][0];
			cost[i][j] = c;
		}
	}

	// 4) DP[k][j] et PARENT[k][j]
	double dp[nMax][nMax];
	int parent[nMax][nMax];
	for (int k = 0; k <= K; ++k)
		for (int j = 0; j <= n; ++j) {
			dp[k][j]     = INF;
			parent[k][j] = -1;
		}
	dp[0][0] = 0; parent[0][0] = 0;

	for (int k = 1; k <= K; ++k) {
		dp[k][0] = 0;
		parent[k][0] = 0;
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= j; ++i) {
				if (cost[i][j] == INF || dp[k-1][i-1] == INF) continue;
				const double val = dp[k-1][i-1] + cost[i][j];
				if (val < dp[k][j]) {
					dp[k][j] = val;
					parent[k][j] = i;
				}
			}
		}
	}

	// 5) Choisir le meilleur k ≤ K qui couvre j=n
	int bestK = -1;
	double bestCost = INF;
	for (int k = 1; k <= K; ++k) {
		if (dp[k][n] < bestCost) {
			bestCost = dp[k][n];
			bestK = k;
		}
	}
	if (bestK == -1) return false; // infeasible

	// 6) Reconstruction depuis (bestK, n)
	int j = n, k = bestK, idx = 0;
	while (j > 0 && k >= 1) {
		const int i = parent[k][j];
		if (i <= 0) return false;
		t_tournee& R = sol.listeTournee[idx];
		R.taille = 0; R.vol = 0;
		for (int u = i; u <= j; ++u) {
			R.liste[R.taille++] = ord[u];
			R.vol += prob.qte[ ord[u] ];
		}
		R.cout = coutTournee(prob, R.liste, R.taille);
		++idx;
		j = i - 1;
		--k;
	}

	// Remise en ordre
	for (int a = 0, b = idx - 1; a < b; ++a, --b) {
		const t_tournee tmp = sol.listeTournee[a];
		sol.listeTournee[a] = sol.listeTournee[b];
		sol.listeTournee[b] = tmp;
	}

	sol.nbTournee = idx;
	sol.cout      = (double)bestCost;
	return true;
}


bool twoOptRoute(t_tournee& r, const t_probleme& prob, int maxOptIter) {
	const int n = r.taille;
	if (n < 2) return false;

	bool improved = false;
	int iter = 0;

	// On itère jusqu'à ne plus trouver d'amélioration
	while (iter < maxOptIter) {
		bool changed = false;
		for (int i = 0; i < n - 1; ++i) {
			const int a = (i == 0) ? 0 : r.liste[i - 1];
			const int u = r.liste[i];
			for (int j = i + 1; j < n; ++j) {
				const int v = r.liste[j];
				const int b = (j == n - 1) ? 0 : r.liste[j + 1];

				// Δ-cost (positive => amélioration si on RETIRE anciennes arêtes et AJOUTE les nouvelles)
				// Δ = (a-u) + (v-b) - (a-v) - (u-b)
				const double delta = prob.distance[a][u]+ prob.distance[v][b]
						  - prob.distance[a][v] - prob.distance[u][b];

				if (delta > 0) {
					// Inversion du segment [i..j]
					for (int p = i, q = j; p < q; ++p, --q) {
						const int tmp = r.liste[p];
						r.liste[p] = r.liste[q];
						r.liste[q] = tmp;
					}
					r.cout = coutTournee(prob, r.liste, r.taille);
					changed = true;
					improved = true;
					break; // on redémarre la recherche
				}
			}
			if (changed) break;
		}
		if (!changed) break;
		iter++;
	}
	recomputeRoute(prob, r);
	return improved;
}


bool relocateOneCustomer(t_solution& sol, const t_probleme& prob,int& nbMoves, const int maxMoves, double EPS) {

	if (nbMoves >= maxMoves) return false;

	for (int r1 = 0; r1 < sol.nbTournee; ++r1) {
		t_tournee& R1 = sol.listeTournee[r1];
		for (int i = 0; i < R1.taille; ++i) {
			const int u   = R1.liste[i];
			const double q_u = prob.qte[u];



			// Δ coût pour enlever u de R1
			const int pre  = (i == 0) ? 0 : R1.liste[i - 1];
			const int post = (i == R1.taille - 1) ? 0 : R1.liste[i + 1];
			const double delta_remove = prob.distance[pre][u] + prob.distance[u][post] - prob.distance[pre][post];


			for (int r2 = 0; r2 < sol.nbTournee; ++r2) {
				t_tournee& R2 = sol.listeTournee[r2];

				// Capacité si R2 != R1
				if (r1 != r2 && R2.vol + q_u > prob.capa) continue;

				// Parcours des positions d'insertion dans R2 (0..taille)
				for (int j = 0; j <= R2.taille; ++j) {

					// Cas même tournée
					int jj = j;
					if (r1 == r2) {
						if (j == i || j == i + 1) continue; // pas un vrai mouvement
						if (j > i) jj = j - 1; // après retrait de i, les indices > i décrémentent
					}

					const int w = (jj == 0) ? 0 : R2.liste[jj - 1];
					const int z = (jj == R2.taille ) ? 0 : R2.liste[jj] ;

					// Δ coût pour insérer u dans R2 en position jj
					const double delta_insert = prob.distance[w][u] + prob.distance[u][z] - prob.distance[w][z];

					const double total_delta = delta_insert - delta_remove; // < 0 : amélioration

					if (total_delta < -EPS) {
						// --- Appliquer le mouvement ---
						// 1) Retirer u de R1 (shift à gauche)
						for (int t = i; t < R1.taille - 1; ++t) R1.liste[t] = R1.liste[t + 1];
						R1.taille--;
						R1.vol -= q_u;


						// 2) Insérer u dans R2 en jj (shift à droite)
						for (int t = R2.taille; t > jj; --t) R2.liste[t] = R2.liste[t - 1];
						R2.liste[jj] = u;
						R2.taille++;
						R2.vol += q_u;


						R1.cout = coutTournee(prob, R1.liste, R1.taille);
						R2.cout = coutTournee(prob, R2.liste, R2.taille);

						normalizeSolution(prob, sol);
						// Si R1 est devenue vide, on supprime la tournée (compactage)

						nbMoves++;

						return true; // first-improvement
					}
				}
			}
		}
	}
	return false;
}


bool swapTwoCustomers(t_solution& sol, const t_probleme& prob,int& nbSwap, const int maxSwap,double EPS) {

	if (nbSwap >= maxSwap) return false;

    for (int r1 = 0; r1 < sol.nbTournee; ++r1) {
        t_tournee& R1 = sol.listeTournee[r1];
        for (int r2 = r1 + 1; r2 < sol.nbTournee; ++r2) {
            t_tournee& R2 = sol.listeTournee[r2];

            for (int i = 0; i < R1.taille; ++i) {
                const int u   = R1.liste[i];
                const double q_u = prob.qte[u];
                const int a = (i == 0) ? 0 : R1.liste[i - 1];
                const int b = (i == R1.taille - 1) ? 0 : R1.liste[i + 1];

                for (int j = 0; j < R2.taille; ++j) {
                    const int v   = R2.liste[j];
                    const double q_v = prob.qte[v];
                    const int c = (j == 0) ? 0 : R2.liste[j - 1];
                    const int d = (j == R2.taille - 1) ? 0 : R2.liste[j + 1];

                    // Capacités après swap
                    const double newVolR1 = R1.vol - q_u + q_v;
                    const double newVolR2 = R2.vol - q_v + q_u;
                    if (newVolR1 > prob.capa || newVolR2 > prob.capa) continue;

                    // Δ coût R1 si on remplace u par v à la position i
                    // Attention aux cas où voisins = v (pas possible ici, r2 > r1), donc safe
                    const double deltaR1 = prob.distance[a][v] + prob.distance[v][b]
                                - prob.distance[a][u] - prob.distance[u][b];

                    // Δ coût R2 si on remplace v par u à la position j
                    const double deltaR2 = prob.distance[c][u] + prob.distance[u][d]
                                - prob.distance[c][v] - prob.distance[v][d];

                    const double total_delta = deltaR1 + deltaR2; // < 0 : amélioration

                    if (total_delta < -EPS) {
                        // Appliquer l'échange
                        R1.liste[i] = v;
                        R2.liste[j] = u;

                        R1.vol = newVolR1;
                        R2.vol = newVolR2;

                    	R1.cout = coutTournee(prob, R1.liste, R1.taille);
                    	R2.cout = coutTournee(prob, R2.liste, R2.taille);

                    	normalizeSolution(prob, sol);

                    	nbSwap++;
                        return true; // first-improvement
                    }
                }
            }
        }
    }
    return false;
}


void vndImprove(t_solution& sol, const t_probleme& prob,
				const int maxVNDIter,
				const int maxOptIter,
				const int maxMoves,
				const int maxSwap,
				const int stallLimit,
				const double EPS) {

	int vndIters = 0;
	int stall    = 0;
	int relocApplied = 0;
	int swapApplied  = 0;

	while (vndIters < maxVNDIter) {

		bool improvedThisRound = false;

		// 1) 2-OPT sur chaque tournée
		bool any2Opt = false;
		for (int k = 0; k < sol.nbTournee; ++k) {
			if (twoOptRoute(sol.listeTournee[k], prob,maxOptIter)) {
				any2Opt = true;
				improvedThisRound = true;
			}
		}
		if (any2Opt){
			normalizeSolution(prob, sol);
			stall = 0;
			vndIters++;
			continue;
		}

		// 2) Relocate (une seule amélioration à la fois)
		if (relocateOneCustomer(sol, prob,relocApplied,maxMoves,EPS)){
			normalizeSolution(prob, sol);
			improvedThisRound = true;
			stall = 0;
			vndIters++;
			continue; // repartir au début (2-OPT à nouveau possible)
		}

		// 3) Swap inter-tournées
		if (swapTwoCustomers(sol, prob,swapApplied,maxSwap,EPS)) {
			normalizeSolution(prob, sol);
			improvedThisRound = true;
			stall = 0;
			vndIters++;
			continue; // repartir au début
		}

		if (!improvedThisRound) {
			stall++;
			vndIters++;
			if (stall >=stallLimit) break;
		}
	}
	normalizeSolution(prob, sol);
}


bool checkCoverage(const t_probleme& prob, const t_solution& sol, bool verbose) {
	static int seen[nMax];
	for (int i = 0; i < nMax; ++i) seen[i] = 0;

	// compter
	for (int k = 0; k < sol.nbTournee; ++k) {
		const t_tournee& r = sol.listeTournee[k];
		for (int i = 0; i < r.taille; ++i) {
			const int u = r.liste[i];
			if (u < 1 || u > prob.nbClient) {
				if (verbose) std::cerr << "[Coverage] client index invalide: " << u << "\n";
				return false;
			}
			seen[u]++;
		}
	}

	// valider
	bool ok = true;
	for (int u = 1; u <= prob.nbClient; ++u) {
		if (seen[u] != 1) {
			ok = false;
			if (verbose) std::cerr << "[Coverage] client " << u << " vu " << seen[u] << " fois\n";
		}
	}
	return ok;
}

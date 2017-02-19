#include "Generator/Generator.hpp"
#include "Algorithmes/A1.hpp"
#include "Algorithmes/A2.hpp"
#include "Algorithmes/A3.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

bool testExhaustif(int n, int algo) {
	int cpt = 0;
	string S(n, 'A');
	string T(n, 'A');
	string res;

	clock_t debut, fin, meilleur, pire, somme;
	meilleur -1;
	pire = -1;

	int iT, iS = 0;
	bool comparer;
	somme = 0;
	do  {
		iT = n-1;

		++cpt;
		if (algo == 1) {
			debut = clock();
			res = A1(S, T);
			fin = clock();
		} else if (algo == 2) {
			debut = clock();
			res = A2(S, T);
			fin = clock();
		} else {
			debut = clock();
			res = A3(S, T);
			fin = clock();
		}
		somme += fin-debut;
		if (((fin-debut) < meilleur) || (meilleur == -1)) {
			meilleur = fin-debut;
		} else if ((fin-debut) > pire) {
			pire = fin-debut;
		}

		do {
			if (T[iT] == 'A') {
				T[iT] = 'C';
				if (iT < n-1) {
					++iT;
				}
				comparer = true;
			} else if (T[iT] == 'C') {
				T[iT] = 'G';
				if (iT < n-1) {
					++iT;
				}
				comparer = true;
			} else if (T[iT] == 'G') {
				T[iT] = 'T';
				if (iT < n-1) {
					++iT;
				}
				comparer = true;
			} else {
				T[iT] = 'A';
				--iT;
				comparer = false;
			}
			if (comparer) {
				++cpt;
				if (algo == 1) {
					debut = clock();
					res = A1(S, T);
					fin = clock();
				} else if (algo == 2) {
					debut = clock();
					res = A2(S, T);
					fin = clock();
				} else {
					debut = clock();
					res = A3(S, T);
					fin = clock();
				}
				somme += fin-debut;
				if (((fin-debut) < meilleur) || (meilleur == -1)) {
					meilleur = fin-debut;
				} else if ((fin-debut) > pire) {
					pire = fin-debut;
				}
			}
		} while (iT != -1);

		if (S[iS] == 'A') {
			S[iS] = 'C';
			if (iS < n-1) {
				++iS;
			}
		} else if (S[iS] == 'C') {
			S[iS] = 'G';
			if (iS < n-1) {
				++iS;
			}
		} else if (S[iS] == 'G') {
			S[iS] = 'T';
			if (iS < n-1) {
				++iS;
			}
		} else {
			S[iS] = 'A';
			--iS;
		}
	} while (iS != -1);

	double bestT = (double)meilleur/CLOCKS_PER_SEC;
	double pireT = (double)pire/CLOCKS_PER_SEC;
	double tMoy = (double)(somme/CLOCKS_PER_SEC)/cpt;
	cout << n << " & oui & " << setprecision(3) << cpt << " & " << setprecision(3) << bestT << " & " << setprecision(3) << tMoy << " & " << setprecision(3) << pireT << " \\\\hline" << endl;

	return (somme/CLOCKS_PER_SEC) < 180;
}

bool testAleatoire(int n, int algo) {
	string S, T, res;

	clock_t debut, fin, somme, meilleur, pire, tps;
	int cpt = 0;

	meilleur = -1;
	pire = -1;

	somme = 0;

	do {
		S = generationAleatoire(n);
		T = generationAleatoire(n);

		if (algo == 1) {
			debut = clock();
			res = A1(S, T);
			fin = clock();
			tps = fin-debut;
		} else if (algo == 2) {
			debut = clock();
			res = A2(S, T);
			fin = clock();
			tps = fin-debut;
		} else {
			debut = clock();
			res = A3(S, T);
			fin = clock();
			tps = fin-debut;
		}

		++cpt;
		somme += (fin-debut);

		if ((tps < meilleur) || (meilleur == -1)) {
			meilleur = tps;
		}
		if (tps > pire) {
			pire = tps;
		}
	} while (somme/CLOCKS_PER_SEC < 180);

	double bestT = (double)meilleur/CLOCKS_PER_SEC;
	double pireT = (double)pire/CLOCKS_PER_SEC;
	double tMoy = (double)(somme/CLOCKS_PER_SEC)/cpt;
	cout << n << " & " << cpt << " & non & " << setprecision(3) << bestT << " & " << setprecision(3) << tMoy << " & " << setprecision(3) << pireT << " \\\\hline" << endl;

	return ((somme/cpt)/CLOCKS_PER_SEC) < 180;
}

int main(int argc, char *argv[]) {	
	/*srand(time(NULL));
	time_t DEBUT, debut, fin, FIN, meilleur, pire;

	string s, t;
	string choix;
	int n, algo;
	bool ok = true;
	string res;
	int nbBoucle = 1000;

	do {
		cout << "Entrée manuelle ou génération aléatoire ? (m/a) : ";
		cin >> choix;
	} while ((choix != "m") && (choix != "M") && (choix != "a") && (choix != "A"));

	if (choix == "a") {
		do {
			cout << "Taille des chaînes : ";
			cin >> n;
		} while (n < 1);
		s = generationAleatoire(n);
		t = generationAleatoire(n);
	} else {
		s = selectionUtilisateur();
		t = selectionUtilisateur();
		if (s.size() == t.size()) {
		} else {
			ok = false;
			cout << "Les deux chaînes n'ont pas la même taille" << endl;
		}
	}

	cout << endl;
	
	if (ok) {
		do {
			cout << "Algorithme de résolution : 1,2,3 (4 pour tous) ";
			cin >> algo;
		} while ((algo < 1) && (algo > 4));

		cout << endl;

		if ((algo == 1) || (algo == 4)) {
			debut = clock();
			res = A1(s, t);
			fin = clock();
			cout << "max A1 = " << res.size() << " : (" << res << ")" << endl;
			cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
		}

		if ((algo == 2) || (algo == 4)) {
			debut = clock();
			res = A2(s, t);
			fin = clock();
			cout << "max A2 = " << res.size() << " : (" << res << ")" << endl;
			cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
		}

		if ((algo == 3) || (algo == 4)) {
			debut = clock();
			res = A3(s, t);
			fin = clock();
			cout << "max A3 = " << res.size() << " : (" << res << ")" << endl;
			cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
		}
	}*/

	int i;
	int palier;

	cout << "tests algo 1" << endl;
	i = 1;
	palier = 1;
	while (testExhaustif(i,1)) {
		if (i == 10*palier) {
			palier *= 10;
		}
		i += palier;
	}

	//test aleatoire algo 1
	while (testAleatoire(i,1)) {
		if (i == 10*palier) {
			palier *= 10;
		}
		i += palier;
	}

	cout << "tests algo 2" << endl;
	i = 1;
	palier = 1;
	while (testExhaustif(i,2)) {
		if (i == 10*palier) {
			palier *= 10;
		}
		i += palier;
	}

	//test aleatoire algo 2
	// TODO

	cout << "tests algo 3" << endl;
	i = 1;
	palier = 1;
	while (testExhaustif(i,2)) {
		if (i == 10*palier) {
			palier *= 10;
		}
		i += palier;
	}

	//test aleatoire algo 2
	// TODO
	
	return 0;
}
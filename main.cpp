#include "Generator/Generator.hpp"
#include "Algorithmes/A1.hpp"
#include "Algorithmes/A2.hpp"
#include "Algorithmes/A3.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {	
	srand(time(NULL));
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

		meilleur = -1;
		pire = 0;
		DEBUT = clock();
		for (int j = 0; j < nbBoucle; ++j) {
			if ((algo == 1) || (algo == 4)) {
				debut = clock();
				res = A1(s, t);
				fin = clock();

				if (fin-debut > pire) {
					pire = fin-debut;
				}
				if ((fin-debut < meilleur) || (meilleur == -1)) {
					meilleur = fin-debut;
				}


				//cout << "max A1 = " << res.size() << " : (" << res << ")" << endl;
				//cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
			}

			if ((algo == 2) || (algo == 4)) {
				debut = clock();
				res = A2(s, t);
				fin = clock();

				if (fin-debut > pire) {
					pire = fin-debut;
				}
				if ((fin-debut < meilleur) || (meilleur == -1)) {
					meilleur = fin-debut;
				}

				//cout << "max A2 = " << res.size() << " : (" << res << ")" << endl;
				//cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
			}

			if ((algo == 3) || (algo == 4)) {
				debut = clock();
				res = A3(s, t);
				fin = clock();

				if (fin-debut > pire) {
					pire = fin-debut;
				}
				if ((fin-debut < meilleur) || (meilleur == -1)) {
					meilleur = fin-debut;
				}

				//cout << "max A3 = " << res.size() << " : (" << res << ")" << endl;
				//cout << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
			}
		}
		FIN = clock();

		cout << "temps moyen : " << (double)(FIN-DEBUT)*1000/CLOCKS_PER_SEC/nbBoucle << "s" << endl;
		cout << "temps au pire : " << (double)(pire)*1000/CLOCKS_PER_SEC << "s" << endl;
		cout << "temps au mieux : " << (double)(meilleur)*1000/CLOCKS_PER_SEC << "s" << endl;
	}
	
	return 0;
}
#include "Generator.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

string selectionUtilisateur() {
	string resultat;
	cin >> resultat;
	return resultat;
}

string generationAleatoire(const int n) {
	string resultat(n, 'A');
	int randN;
	
	for (int i = 0; i < n; ++i) {
		randN = rand() % 40;
		if (randN < 10) {
			resultat[i] = 'C';
		} else if (randN < 20) {
			resultat[i] = 'G';
		} else if (randN < 30) {
			resultat[i] = 'T';
		}
	}
	return resultat;
}
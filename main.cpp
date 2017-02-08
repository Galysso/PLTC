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
	//~ srand(5);
	time_t debut, fin;

	string s, t;
	s = generationAleatoire(20);
	t = generationAleatoire(20);
	//s = selectionUtilisateur();
	//t = selectionUtilisateur();
	
	cout << endl << "S : " << s << endl << endl;
	
	cout << "T : " << t << endl << endl;
	
	debut = clock();

	cout << "max A1 = " << A1(s, t) << endl;
	cout << "max A2 = " << A2(s, t) << endl;
	cout << "max A3 = " << A3(s, t) << endl << endl;

	fin = clock();

	cout << "temps : " << (fin-debut)/CLOCKS_PER_SEC << "s" << endl << endl;
	
	return 0;
}

#include "Generator/Generator.hpp"
#include "Algorithmes/A1.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {	
	srand(time(NULL));
	//~ srand(5);
	
	string s, t;
	s = generationAleatoire(20);
	t = generationAleatoire(20);
	//~ s = selectionUtilisateur();
	//~ t = selectionUtilisateur();
	
	cout << endl << "S : " << s << endl << endl;
	
	cout << "T : " << t << endl << endl;
	
	cout << "max = " << A1(s, t) << endl << endl;
	
	return 0;
}

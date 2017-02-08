#include "A3.hpp"

#include <iostream>
#include <string>

string A3(string s, string t) {
	int n = s.size();
	int i, j, a, b;
	int *PMK = new int[n];
	int imax = 0;
	int max = 0;

	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {

			// REMPLISSAGE DU TABLEAU
			a = 0;
			b = -1;
			PMK[0] = -1;
			
			while (a < j-i+1) {
				while ((b > -1) && (s[i+a] != s[i+b])) {
					b = PMK[i+b];
				}
				++a;
				++b;
					if ((a < i-j+1) && (s[i+a] != s[i+b])) {
					PMK[i+a] = PMK[i+b];
				} else {
					PMK[i+a] = b;
				}
			}
		
			// ALGORITHME
			bool res = false;
			a = 0;

			for (int k = 0; k < n; ++k) {
				cout << PMK[k] << endl;
			}
			
			for (b = 0; b < n; ++b) {
				while ((a > -1) && (s[i+a] != t[b])) {
					cout << "a=" << a << endl;
					cout << "i=" << i << endl;
					cout << "PMK[" << i+1 << "]=" << PMK[i+a] << endl;
					a = PMK[i+a];
					cout << "a=" << a << endl << endl;
				}

				a = a +1;
				
				if (a >= j-i+1) {
					a = PMK[i+a];
					if (max < j-i+1) {
						max = j-i+1;
						imax = i;
					}
				}
			}
		}
	}

	return s.substr(imax, max);
}
#include "A2.hpp"

#include <iostream>
#include <string>

string A2(string s, string t) {
	int max = 0;
	int imax = 0;
	int l, a, i1, b, i2, p, q;
	bool valide;
	const int n = s.size();
	
	for (l = 1; l <= n; ++l) {
		for (a = 0; a < n-l; ++a) {
			b = l+a-1;
			for (p = 0; p < n-l; ++p) {
				i1 = a;
				i2 = p;
				q = l+p-1;
				valide = true;

				while (valide && (i1 <= b)) {
					valide = (s[i1] == t[i2]);
					++i1;
					++i2;
				}
				if (valide) {
					imax = a;
					max = l;
				}
			}
		}
	}
	
	return s.substr(imax, max);
}
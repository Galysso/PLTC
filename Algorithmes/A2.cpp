#include "A2.hpp"

#include <iostream>
#include <string>

string A2(string s, string t) {
	int max = 0;
	int imax = 0;
	const int n = s.size();
	
	for (int l = 1; l <= n; ++l) {
		for (int a = 0; a < n-l; ++a) {
			for (int p = 0; p < n-l; ++p) {
				if (s.substr(a, l) == t.substr(p, l)) {
					imax = a;
					max = l;
				}
			}
		}
	}
	
	return s.substr(imax, max);
}

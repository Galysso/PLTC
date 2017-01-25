#include "A1.hpp"

#include <iostream>
#include <string>

int pls(const string s, const string t, const int i, const int j) {
	int val = 0;
	if (s[i] == t[j]) {
		if ((i == 0) || (j == 0)) {
			val = 1;
		} else {
			val = pls(s, t, i-1, j-1) + 1;
		}
	}
	return val;
}

string A1(string s, string t) {
	const int n = s.size();
	int M[n][n];
	int max = 0;
	int imax = 0;
	
	int i, j;
	
	for (i = 0; i < n; ++i) {
		M[i][0] = pls(s, t, i, 0);
	}
	for (j = 1; j < n; ++j) {
		M[0][j] = pls(s, t, 0, j);
	}
	for (i = 1; i < n; ++i) {
		for (j = 1; j < n; ++j) {
			M[i][j] = pls(s, t, i, j);
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (M[i][j] > max) {
				max = M[i][j];
				imax = i;
			}
		}
	}
	
	return s.substr(imax-max+1, max);
}

#include "A1.hpp"

#include <iostream>
#include <string>

short pls(const string s, const string t, const int i, const int j) {
	if (s[i] == t[j]) {
		if ((i == 0) || (j == 0)) {
			return 1;
		} else {
			return pls(s, t, i-1, j-1) + 1;
		}
	}
}

string A1(string s, string t) {
	const int n = s.size();
	short **M = new short * [n];
	int max = 0;
	int imax = 0;
	
	int i, j;
	
	for (i = 0; i < n; ++i) {
		M[i] = new short [n];
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

	for (i = 0; i < n; ++i) {
		delete [] M[i];
	}
	delete [] M;
	
	return s.substr(imax-max+1, max);
}

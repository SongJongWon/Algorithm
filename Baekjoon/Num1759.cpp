#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
/*
char vowel[5] = {'a','e', 'i', 'o', 'u'};
char input[15];
char result[15];
int num_L;
int num_C;

void search(int i_tmp, int r_tmp, int num_Vow, int num_Con) {

	result[r_tmp] = input[i_tmp];
	if (result[r_tmp] == vowel[0] || result[r_tmp] == vowel[1] || result[r_tmp] == vowel[2] || result[r_tmp] == vowel[3] || result[r_tmp] == vowel[4]) {
		num_Vow += 1;
	}
	else {
		num_Con += 1;
	}


	if (r_tmp == num_L-1) {
		if (num_Vow > 0 && num_Con > 1) cout << result << endl;
		return;
	}
	
	for (int i = i_tmp+1; i < num_C; i++) {
		search(i, r_tmp + 1, num_Vow, num_Con);
	}
	
}
*/
/*
int main() {
	char alp;
	
	cin >> num_L >> num_C;

	for (int i = 0; i < num_C; i++) {
		cin >> alp;
		input[i] = alp;
	}

	sort(input, input + num_C);

	for (int i = 0; i < num_C - 3; i++) {
		search(i, 0, 0, 0);
	}

	return 0;
}
*/
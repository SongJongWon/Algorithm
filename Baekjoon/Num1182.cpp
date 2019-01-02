#include "pch.h"
#include <iostream>

using namespace std;

int n, s;
int input[20];
int result = 0;

void bruteForce(int size, int temp, int sum) {
	int temp_sum;
	int j;

	for (int i = temp; i < n + 1 - size; i++) {
		temp_sum = sum;
		temp_sum += input[i];
		//cout << temp << " : " << i << " : " << temp_sum << " : " << size << endl;
		if (size > 1) {
			bruteForce(size-1, i+1, temp_sum);
		}
		else {
			//cout << temp_sum << endl;
			if (temp_sum == s) {
				result += 1;
			}
		}
	}
	
	/*
	for (int i = 0; i < n + 1 - size; i++) {
		sum = 0;
		for (int z = 0; z < n; z++) {

		}
		j = i;

		temp_size = size;
		while (temp_size != 0) {
			sum += input[j];
			j += 1;
			temp_size -= 1;
		}
		cout << i << " : " << size << " - " << sum << endl;
		if (sum == s) {
			cout << sum << " == "<< s << endl;
			result += 1;
		}
	}
	*/
}

int main() {
	
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 1; i < n+1; i++) {
		bruteForce(i, 0, 0);
	}
	
	cout << result;
}
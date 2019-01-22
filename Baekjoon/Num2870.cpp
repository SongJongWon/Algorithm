#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string input[100];
vector<string> result;

bool pashing(string a, string b) {
	if(a.size() > b.size()) return true;
	else if (a.size() < b.size()) return false;
	else {
		return a > b;
	}
}

string convert(string temp) {
	string conv_temp;
	int size = temp.size();
	bool check = false;
	for (int i = 0; i < size; i++) {
		if (temp[i] != '0') check = true;
		if (check) conv_temp.push_back(temp[i]);
	}

	if (check) return conv_temp;
	else return "0";
}


void search() {
	string temp;
	int size;

	for (int i = 0; i < n; i++) {
		size = input[i].size();
		for (int j = 0; j < size; j++) {
			if (input[i][j] < 58) {
				temp.push_back(input[i][j]);
			}
			else {
				if (!temp.empty()) {
					if (temp[0] == '0') {
						temp = convert(temp);
					}
					result.push_back(temp);
					temp.clear();
				}
			}
		}
		if (!temp.empty()) {
			if (temp[0] == '0') {
				temp = convert(temp);
			}
			result.push_back(temp);
			temp.clear();
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	search();

	sort(result.begin(), result.end(), pashing);

	int size = result.size();

	for (int i = size-1; i >= 0; i--) {
		cout << result[i] << "\n";
	}

	return 0;
}
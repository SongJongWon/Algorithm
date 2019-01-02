#include "pch.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> envelopes) {
	int answer = 0;
	int temp_x, temp_y;
	int grid_x, grid_y;
	int grid_pos;
	vector<int> group;
	int check = 0;

	for (int i = 0; i < envelopes.size(); i++) {
		group.push_back(0); 
	}

	for (int i = 0; i < envelopes.size(); i++) {
		temp_x = envelopes[i][0];
		temp_y = envelopes[i][1];

		grid_pos = i;
		grid_x = 20000; // infi
		grid_y = 20000; // infi

		for (int j = 0; j < envelopes.size(); j++) {
			if (temp_x < envelopes[j][0] && temp_y < envelopes[j][1]) {
				if (envelopes[j][0] <= grid_x && envelopes[j][1] <= grid_y) {
					if (group[i] == 0 || group[j] == 0) {
						grid_x = envelopes[j][0];
						grid_y = envelopes[j][1];
						grid_pos = j;
					}
				}
			}
		}
		
		if (i == grid_pos) {
			continue;
		}

		if (group[grid_pos] == 0 && group[i] == 0) {
			answer += 1;
			group[i] = answer;
			group[grid_pos] = answer;
		}
		else if(group[grid_pos] == 0){
			group[grid_pos] = group[i];
		}
		else if (group[i] == 0) {
			group[i] = group[grid_pos];
		}		
	}

	for (int i = 0; i < group.size(); i++) {
		if (group[i] == 0) answer += 1;
	}

	return answer;
}

int main() {
	int n;
	int input[2];
	vector<vector<int>> envelopes;

	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> s;
		cin >> input[0] >> input[1];
		s.push_back(input[0]);
		s.push_back(input[1]);

		envelopes.push_back(s);
	}

	cout << solution(envelopes);

	return 0;

}
#include "pch.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 브루트포스 : 모든 경우를 이중 for문을 통하여 계산
int solution(vector<vector<int>> envelopes) {
	int answer = 0;
	int temp_x, temp_y;		// 현재 봉투의 x 길이와 y 길이
	int grid_x, grid_y;		// grid의 x 길이와 y 길이
	int grid_pos;			// temp를 안에 넣을 수 있는 봉투 중 가장 작은 봉투의 index
	vector<int> group;
	int check = 0;

	for (int i = 0; i < envelopes.size(); i++) {
		group.push_back(0); 
	}

	// 모든 봉투를 for문으로 순회
	for (int i = 0; i < envelopes.size(); i++) {
		temp_x = envelopes[i][0];
		temp_y = envelopes[i][1];

		grid_pos = i;
		grid_x = 20000; // infi
		grid_y = 20000; // infi
		//모든 봉투 중 temp를 안에 넣을 수 있는 가장 작은 봉투를 찾기 위한 for문
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
		// i == grid_pos 일 경우는 temp를 포함할 수 있는 봉투가 없는 것
		if (i == grid_pos) {
			continue;
		}

		if (group[grid_pos] == 0 && group[i] == 0) {	// 두 봉투 모두 group이 정해지지 않은 경우
			answer += 1;
			group[i] = answer;
			group[grid_pos] = answer;
		}
		else if(group[grid_pos] == 0){					// 두 봉투 중 하나가 group이 정해진 경우
			group[grid_pos] = group[i];
		}
		else if (group[i] == 0) {						// 두 봉투 중 하나가 group이 정해진 경우
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
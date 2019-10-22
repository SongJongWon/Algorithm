#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) return a[1] < b[1];
	else return a[0] < b[0];
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	bool check1, check2;
	int start_index, start_index_up, start_index_down;
	int start_x, start_y, up_x, up_y, prev_up_y, up_start_x, down_y;

	sort(data.begin(), data.end(), compare);

	for (int i = 0; i < n; i++) {
		start_x = data[i][0];
		start_y = data[i][1];
		check1 = false;
		check2 = false;

		for (int j = i+1; j < n; j++) {
			if (data[j][0] == start_x) continue;
			if (!check1 && data[j][1] > start_y) {
				up_x = data[j][0];
				up_y = data[j][1];
				start_index_up = j;
				check1 = true;
			}
			else if (!check2 && data[j][1] < start_y){
				down_y = data[j][1];
				start_index_down = j;
				check2 = true;
			}
			if (check1 && check2) {
				break;
			}
		}

		if (check1 && check2) {
			if (start_index_up < start_index_down) start_index = start_index_up;
			else start_index = start_index_down;
		}
		else if (check1) start_index = start_index_up;
		else if (check2) start_index = start_index_down;
		else continue;

		prev_up_y = INT_MAX;
		for (int j = start_index; j < n; j++) {
			if (data[j][1] > start_y) {
				if (data[j][1] <= up_y) {
					if (data[j][1] != up_y) {
						prev_up_y = up_y;
						up_x = data[j][0];
					}
					up_y = data[j][1];
					answer += 1;
				}
				else {
					if (data[j][0] == up_x && prev_up_y >= data[j][1]) answer += 1;
				}
			}
			else if (data[j][1] < start_y) {
				if (data[j][1] >= down_y) {
					down_y = data[j][1];
					answer += 1;
				}
			}
		}
	}

	return answer;
}

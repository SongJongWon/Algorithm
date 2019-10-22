#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, l, r;
int map[50][50] = { 0, };
bool map_sub[50][50][4] = { 0, };
int group[50][50] = { 0, };
int group_sub[2500][2] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void group_set(int x, int y, int* temp, int group_num) {
	int next_y, next_x;

	group[y][x] = group_num;
	temp[0] += map[y][x];
	temp[1] += 1;

	for (int i = 0; i < 4; i++) {
		next_y = y + dy[i];
		next_x = x + dx[i];
		if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > n - 1) continue;
		if (map_sub[y][x][i] && group[next_y][next_x] == 0) group_set(next_x, next_y, temp, group_num);
	}
}

int solution() {
	int answer = 0;
	int check1 = 0, check2 = 0, group_num = 0;
	bool finish = true;

	while (1) {
		finish = true;
		
		//init
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				group[i][j] = 0;
				for (int z = 0; z < 4; z++) {
					map_sub[i][j][z] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i >= n - 1) check1 = 0;
				else check1 = abs(map[i][j] - map[i + 1][j]);

				if (j >= n - 1) check2 = 0;
				else check2 = abs(map[i][j] - map[i][j + 1]);
				
				if (check1 != 0 && check1 >= l && check1 <= r) {
					map_sub[i][j][1] = true;
					map_sub[i + 1][j][3] = true;
					finish = false;
				}
				if (check2 != 0 && check2 >= l && check2 <= r) {
					map_sub[i][j][0] = true;
					map_sub[i][j + 1][2] = true;
					finish = false;
				}
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < 4; z++) {
					cout << map_sub[i][j][z] << " ";
				}
				cout << endl;
			}
		}
		cout << "-----------------" << endl;
		*/

		if (finish) break;

		group_num = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == 0) {
					group_sub[group_num][0] = 0;
					group_sub[group_num][1] = 0;
					group_set(j, i, group_sub[group_num], group_num);
					group_num += 1;
				}
			}
		}

		//change_population
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] != 0) {
					map[i][j] = group_sub[group[i][j]][0] / group_sub[group[i][j]][1];
				}
			}
		}

		answer += 1;
	}

	return answer;
}

int main() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << solution();

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int a[10][10] = { 0, };
vector<vector<vector<int>>> map;
int add_map[10][10] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution() {
	int answer = 0;
	vector<int> ::iterator iter;

	for (int i = 0; i < k; i++) {
		//init
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {;
				sort(map[j][z].begin() + 1, map[j][z].end());
			}
		}

		//spring
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				iter = map[j][z].begin();
				iter++;
				for (; iter != map[j][z].end();) {
					//cout << map[j][z][0] << "----"<<*iter << "---" << endl;
					if (*iter <= map[j][z][0]) {
						map[j][z][0] -= *iter;
						*iter += 1;
						iter++;
					}
					else {
						add_map[j][z] += *iter / 2;
						iter = map[j][z].erase(iter);
					}
				}
			}
		}

		//summer
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				map[j][z][0] += add_map[j][z];
				add_map[j][z] = 0;
			}
		}

		//fall
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				iter = map[j][z].begin();
				iter++;
				for (; iter != map[j][z].end(); iter++) {
					if ((*iter % 5) == 0) {
						if(j > 0) {
							map[j - 1][z].push_back(1);
							if(z > 0) map[j - 1][z - 1].push_back(1);
							if(z < n-1) map[j - 1][z + 1].push_back(1);
						}
						if (j < n-1) {
							map[j + 1][z].push_back(1);
							if (z > 0) map[j + 1][z - 1].push_back(1);
							if (z < n-1) map[j + 1][z + 1].push_back(1);

						}
						if (z > 0) map[j][z - 1].push_back(1);
						if (z < n-1) map[j][z + 1].push_back(1);
					}
				}
			}
		}

		//winter
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				map[j][z][0] += a[j][z];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += map[i][j].size() - 1;
		}
	}

	return answer;
}

int main() {
	int input_x, input_y, input_age;
	cin >> n >> m >> k;
	
	//init
	map.assign(10, vector<vector<int>>(10, vector<int>(1, 5)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> input_x >> input_y >> input_age;
		map[input_x-1][input_y-1].push_back(input_age);
	}

	cout << solution();

	return 0;
}

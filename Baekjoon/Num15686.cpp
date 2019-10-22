#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<pair<int, int>> home_list;
vector<pair<int, int>> chicken_list;
bool select_chiken[13] = { 0 , };
int map[50][50];
int answer = 1500;

void update() {
	int home_size = home_list.size();
	int distance, comp;
	int total_distance = 0;

	for (int i = 0; i < home_size; i++) {
		distance = 100;
		for (int j = 0; j < 13; j++) {
			if (select_chiken[j]) {
				comp = abs(home_list[i].first - chicken_list[j].first) + abs(home_list[i].second - chicken_list[j].second);
				if (comp < distance) distance = comp;
			}
		}
		total_distance += distance;
	}

	if (total_distance < answer) answer = total_distance;
}

void recur(int temp, int size, int select_size) {
	if (select_size > size) return;
	else if (select_size == size) {
		update();
		return;
	}
	else if (temp >= chicken_list.size()) return;

	select_chiken[temp] = true;
	recur(temp + 1, size, select_size + 1);
	select_chiken[temp] = false;
	recur(temp + 1, size, select_size);
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home_list.push_back({j, i});
			else if(map[i][j] == 2) chicken_list.push_back({ j, i });
		}
	}

	recur(0, m, 0);

	cout << answer;

	return 0;
}

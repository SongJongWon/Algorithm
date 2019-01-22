#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int visited[100][100] = { 0, };
int map[100][100] = { 0, };
int n, m, result;

void bfs(){
	int temp_x;
	int temp_y;

	queue<pair<int, int>> q;

	/* init */
	q.push({0, 0});
	visited[0][0] = 1;

	while (q.size()) {
		temp_x = q.front().first;
		temp_y = q.front().second;
		q.pop();

		if (temp_x == m - 1 && temp_y == n - 1) {
			result = visited[temp_y][temp_x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = temp_x + dx[i];
			int next_y = temp_y + dy[i];

			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

			if (!visited[next_y][next_x] && map[next_y][next_x]) {
				q.push({next_x, next_y});
				visited[next_y][next_x] = visited[temp_y][temp_x] + 1;
			}
		}
	}
}

int main() {
	char input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			map[i][j] = input-'0';
		}
	}

	bfs();

	cout << result;

	return 0;
}
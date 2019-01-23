#include "pch.h"
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[100][100] = { 0, };
int map[100][100] = { 0, };
int n, m;

int bfs() {
	int temp_x;
	int temp_y;
	int size;
	int depth = 1;
	queue<pair<int, int>> q;

	/* init */
	q.push({ 0, 0 });

	while (q.size()) {
		size = q.size();
		for (int i = 0; i < size; i++) {
			temp_x = q.front().first;
			temp_y = q.front().second;
			q.pop();

			if (temp_x == m - 1 && temp_y == n - 1) {
				return depth;
			}

			for (int j = 0; j < 4; j++) {
				int next_x = temp_x + dx[j];
				int next_y = temp_y + dy[j];

				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

				if (!visited[next_y][next_x] && map[next_y][next_x]) {
					q.push({ next_x, next_y });
					visited[next_y][next_x] = 1;
				}
			}
		}
		depth += 1;
	}
	return depth;
}

int main() {
	char input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			map[i][j] = input - '0';
		}
	}

	cout << bfs();

	return 0;
}
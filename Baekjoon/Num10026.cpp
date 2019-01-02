#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
/*
char map[100][100];
int visited[100][100] = { 0, };
int N;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

void search(int pos_y, int pos_x, char color) {
	if (pos_y > N - 1 || pos_y < 0 || pos_x > N - 1 || pos_x < 0) {
		return;
	}

	visited[pos_y][pos_x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = pos_x + dx[i];
		int next_y = pos_y + dy[i];

		if (map[next_y][next_x] == color && visited[next_y][next_x] == 0) {
			search(next_y, next_x, color);
		}
	}

	if (map[pos_y][pos_x] == 'G') {
		map[pos_y][pos_x] = 'R';
	}
}

int main() {
	int result = 0;
	int result1 = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				search(i, j, map[i][j]);
				result += 1;
			}
		}
	}

	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				search(i, j, map[i][j]);
				result1 += 1;
			}
		}
	}
	
	cout << result << ' ' << result1 << endl;

	return 0;
}
*/
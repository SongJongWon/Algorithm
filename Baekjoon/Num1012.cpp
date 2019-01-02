#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int map[50][50];
int visited[50][50];
int row; // ¿­
int col;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void search(int pos_y, int pos_x) {
	
	if (pos_x > row-1 || pos_x < 0 || pos_y > col-1 || pos_y < 0) {
		return;
	}

	visited[pos_y][pos_x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = pos_x + dx[i];
		int next_y = pos_y + dy[i];
		
		if (map[next_y][next_x] == 1 && visited[next_y][next_x] == 0) {
			search(next_y, next_x);
		}
	}
}
int main() {
	int stage;
	int pos_num;
	int pos[2];
	int result = 0;
	
	cin >> stage;

	for (int i = 0; i < stage; i++) {
		init();
		result = 0;
		cin >> row >> col >> pos_num;
		for (int j = 0; j < pos_num; j++) {
			cin >> pos[1] >> pos[0];
			map[pos[0]][pos[1]] = 1;
		}
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (map[k][j] == 1 && visited[k][j] == 0) {
					search(k, j);
					result += 1;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}
*/
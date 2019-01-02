#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;
queue<int> search_Q;
int r, c;
bool finish = false;
char map[50][50];
int visited[50][50] = { 0, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int pos_x, int pos_y, int depth) {
	if (depth != -1) {
		depth = depth + 1;
		if (map[pos_y][pos_x] == 'D') {
			finish = true;
			visited[pos_y][pos_x] = depth;
			return;
		}
	}
	if (visited[pos_y][pos_x] != 0) return;
	visited[pos_y][pos_x] = depth;

	for (int i = 0; i < 4; i++) {
		int next_x = pos_x + dx[i];
		int next_y = pos_y + dy[i];

		if (next_x < 0 || next_x > c-1 || next_y < 0 || next_y > r-1) continue;
		if (depth == -1 && map[next_y][next_x] == 'D') continue;
		if (map[next_y][next_x] == 'X') continue;

		if (visited[next_y][next_x] == 0) {
			search_Q.push(next_x);
			search_Q.push(next_y);
			search_Q.push(depth);
		}
	}
}


int main() {
	char input[50];
	vector<int> v;
	int startpoint[2];
	int endpoint[2];
	int next_x, next_y, depth;
	
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> input[j];
			map[i][j] = input[j];
			if (input[j] == 'S') {
				startpoint[0] = j;
				startpoint[1] = i;
			}
			else if (input[j] == '*') {
				v.push_back(j);
				v.push_back(i);

			}
			else if (input[j] == 'D') {
				endpoint[0] = j;
				endpoint[1] = i;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		search_Q.push(v[i]);
		if (i % 2 == 1) {
			search_Q.push(-1);
		}
	}
	search_Q.push(startpoint[0]);
	search_Q.push(startpoint[1]);
	search_Q.push(0);

	while (search_Q.size() > 0 && !finish) {
		next_x = search_Q.front();
		search_Q.pop();
		next_y = search_Q.front();
		search_Q.pop();
		depth = search_Q.front();
		search_Q.pop();
		bfs(next_x, next_y, depth);
	}

	if (visited[endpoint[1]][endpoint[0]] > 0) cout << visited[endpoint[1]][endpoint[0]] - 1;
	else cout << "KAKTUS";

	return 0;
}
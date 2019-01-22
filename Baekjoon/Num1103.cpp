#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

#define infi 9999999

using namespace std;

char map[50][50];
int visited[50][50] = { 0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int result;

/* version 1
int group[50][50] = { 0, };
bool cycle = false;
struct s {
	int y, x, step, group;
};
*/

/*
	1. bfs로 풀 시, cycle을 찾을 수가 없음. (소모 시간 : 2시간) 
	* 해당 문제를 풀기위해 bit 연산 도입 (실패)
	원인 : 같은 depth가 아닌 정점들끼리의 연산을 하는 방법을 도출하지 못함.
	2. dfs

*/

int dfs(int temp_x, int temp_y, int step) {
	int temp_map = int(map[temp_y][temp_x]) - 48;
	int back1 = 1, back2;
	if (step > result) result = step;

	visited[temp_y][temp_x] = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = temp_x + temp_map * dx[i];
		int next_y = temp_y + temp_map * dy[i];

		if (next_x >= m || next_y >= n || next_y < 0 || next_x < 0) continue;
		if (map[next_y][next_x] == 'H') continue;
		if (visited[next_y][next_x] == 0) {
			result = -2;
			return 0;
		}
		else if (visited[next_y][next_x] != infi) {
			if (visited[next_y][next_x] + step > result) result = visited[next_y][next_x] + step;
			if (visited[next_y][next_x] + 1 > back1) back1 = visited[next_y][next_x] + 1;
			continue;
		}

		back2 = dfs(next_x, next_y, step + 1);
		if (back2 > back1) back1 = back2;

		if (result == -2) return 0;
	}

	visited[temp_y][temp_x] = back1;

	return back1 + 1;
}

/*
bool compare(int a, int b, int step) {
	int i = 0;
	int compare_a, compare_b;
	if (step > 2) {
		a = a >> 1;
		b = b >> 1;
	}
	for (int i = 0; i < step; i++) {
		compare_a = a >> (4 * i);
		compare_b = b >> (4 * i);
		compare_a &= 7;
		compare_b &= 7;
		//cout << a<<":::::::"<<b<< "  "<<compare_a << ":::::" << compare_b << endl;
		if (compare_a & compare_b) {
			cycle = true;
		}
		else {
			cycle = false;
			break;
		}
	}

	return cycle;
}

int bfs() {
	queue<s> pos;
	
	s temp;
	int temp_map;
	int mask;

	temp.x = 0;
	temp.y = 0;
	temp.step = 1;
	temp.group = 1;

	//init
	pos.push(temp);

	while (pos.size()) {
		temp = pos.front();
		pos.pop();
		temp_map = int(map[temp.y][temp.x]) - 48;
		mask = temp.step >> (4 * (temp.group - group[temp.y][temp.x]));
		
		cout << "step : " << temp.step << " mask : " << mask << " x : " << temp.x << " y : " << temp.y << " val : " << temp_map << " visited : " << visited[temp.y][temp.x] << "group : " << group[temp.y][temp.x] << endl;
		cout << visited[temp.y][temp.x] << endl;
		cout << mask << endl;
		int a = visited[temp.y][temp.x] & mask;
		cout << a << endl;
		
		if (compare(visited[temp.y][temp.x] ,mask, group[temp.y][temp.x])) return -1;
		else if (visited[temp.y][temp.x] != 0) {
			visited[temp.y][temp.x] |= mask;
		}

		visited[temp.y][temp.x] = temp.step;
		group[temp.y][temp.x] = temp.group;

		temp.step = temp.step << 4;

		for (int i = 0; i < 4; i++) {
			s next;
			next.x = temp.x + temp_map * dx[i];
			next.y = temp.y + temp_map * dy[i];

			if (next.x >= m || next.y >= n || next.y < 0 || next.x < 0) continue;
			if (map[next.y][next.x] == 'H') continue;

			next.step = temp.step | (1 << i);
			next.group = temp.group + 1;
			pos.push(next);
		}
	}

	return temp.group;
}
*/

int main() {
	char input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			map[i][j] = input;
			visited[i][j] = infi;
			//group[i][j] = 1;
		}
	}
	dfs(0, 0, 0);
	cout << result + 1;

	return 0;
}
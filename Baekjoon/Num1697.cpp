#include "pch.h"
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

int bfs(int n, int k) {
	queue<pair<int, int>> q;
	bitset<100000> visited;
	int step = 0;
	int temp, temp_step;

	// init
	q.push({ 0, n });
	visited.reset();

	while (q.size()) {
		temp_step = q.front().first;
		temp = q.front().second;
		q.pop();
		visited[temp] = 1;

		if (temp == k) {
			step = temp_step;
			break;
		}

		if(!visited[temp + 1] && temp + 1 <= 100000) q.push({ (temp_step + 1) , temp + 1 });
		if(!visited[temp - 1] && temp - 1 >= 0) q.push({ (temp_step + 1) , temp - 1 });
		if(!visited[temp * 2] && temp * 2 <= 100000) q.push({ (temp_step + 1) , temp * 2 });
	}

	return step;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}
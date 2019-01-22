#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int infi = 999999;

vector<pair<int, int>> map[20000];
int visited[20000] = { 0, };
int result[20000] = { 0, };
priority_queue< pair<int, int> > pq;
queue<int> q;
int v, e, s;

void dijkstra() {
	int temp;
	int t_size;
	int t_result;
	int min, check_pos;

//	q.push(s);
	pq.push({ 0, s });

	while (pq.size()) {
		min = infi;

		temp = pq.top().second;
		t_result = -1 * pq.top().first;
		pq.pop();
		/*
		temp = q.front();
		q.pop();
		t_result = result[temp];
		*/
		t_size = map[temp].size();

		for (int i = 0; i < t_size; i++) {
			int new_val = t_result + map[temp][i].second;
			int before_val = result[map[temp][i].first];

			if (new_val < before_val) {
				result[map[temp][i].first] = t_result + map[temp][i].second;
				pq.push({ -1 * new_val, map[temp][i].first });
			}
		}
		/*
		visited[temp] = 1;

		for (int i = 0; i < v; i++) {
			if (visited[i] == 0 && result[i] < min) {
				min = result[i];
				check_pos = i;
			}
		}

		if (min != infi) q.push(check_pos);
		*/
	}

}

void init() {
	s -= 1;

	for (int i = 0; i < v; i++) {
		if (i == s) continue;
		result[i] = infi;
	}
}

int main() {
	int input[3];
	int size, x, y;
	bool check;

	cin >> v >> e;

	cin >> s;

	for (int i = 0; i < e; i++) {
		cin >> input[0] >> input[1] >> input[2];
		
		check = false;
		input[0] -= 1;
		input[1] -= 1;
		size = map[input[0]].size();

		for (int j = 0; j < size; j++) {
			if (map[input[0]][j].first == input[1]) {
				check = true;
				if (map[input[0]][j].second > input[2]) map[input[0]][j].second = input[2];
			}
		}
		if(!check) map[input[0]].push_back(make_pair(input[1], input[2]));
	}

	init();

	dijkstra();

	for (int i = 0; i < v; i++) {
		if (result[i] == infi) cout << "INF" << "\n";
		else cout << result[i] << "\n";
	}
	return 0;
}
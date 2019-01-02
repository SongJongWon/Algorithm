#include "pch.h"
#include <iostream>
#include <vector>
//#include <string.h>

using namespace std;

/*	version2
int **map;
*/
vector<int> graph[20000];
int visited[20000] = { 0, };
bool result;

/*
1. using int[20000][20000] <- Memory exceeded
2. using int** (Dynamic allocation) <- Memory exceeded
3. using STL vector class
4. add logic for not a the connection graph
5. change logic because It is possible to have a half-graph without a connection graph.
*/

void dfs(int temp, int label) {
	visited[temp] = label;

	// set used value
	int size = graph[temp].size();
	int next;
	int next_label;

	// set next label
	if (label == 1) next_label = 2;
	else next_label = 1;

	for (int i = 0; i < size; i++) {
		next = graph[temp][i];
		if (visited[next] == 0) {
			dfs(next, next_label);
		}
		else if (visited[next] != next_label) {
			result = false;
			break;
		}
	}
	/* version 2
	for (int i = 0; i < v; i++) {
		if (map[temp][i] == 1) {
			if (visited[i] == 0) {
				if (check == 1) check = 2;
				else check = 1;

				dfs(i, check);
			}
			else if(visited[i] == check) {
				result = 1;
			}
		}
	}
	*/
}

void init(int v) {
	/* version 2
	map = new int*[v];
	for (int i = 0; i < v; ++i) {
		map[i] = new int[v]; 
		memset(map[i], 0, sizeof(int)*v);
	}
	*/
	result = true;

	for (int i = 0; i < v; i++) {
		graph[i].clear();
		visited[i] = 0;
	}
}

/* delete in version 5
bool checkVertex(int v) {
	bool check = true;

	for (int i = 0; i < v; i++) {
		if (visited[i] == 0) {
			check = false;
			break;
		}
	}

	return check;
}
*/

int main() {
	int k, v, e;
	int input[2];
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> v >> e;

		// init
		init(v);

		for (int j = 0; j < e; j++) {
			cin >> input[0] >> input[1];
			/* version 2
			map[input[0] - 1][input[1] - 1] = 1;
			map[input[1] - 1][input[0] - 1] = 1;
			*/
			graph[input[0] - 1].push_back(input[1] - 1);
			graph[input[1] - 1].push_back(input[0] - 1);
		}
		
		/* version 4
		dfs(input[1]-1, 1);
		*/

		// version 5
		for (int j = 0; j < v; j++) {
			if (visited[j] == 0) dfs(j, 1);
			
		}

		if (result) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		/* version 2
		for (int i = 0; i < v; ++i) { 
			delete[] map[i]; 
		}
		delete[] map;
		*/
	}

	return 0;
}
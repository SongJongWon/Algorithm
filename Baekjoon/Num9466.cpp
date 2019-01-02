#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int student[100000];
int check[2];

int dfs(int visited[], int groud_mark[], int tmp, int start) {
	int circle_start;

	if (visited[tmp] && !groud_mark[tmp]) {
		visited[tmp] = 1;
		return tmp;
	}
	else if(groud_mark[tmp]) {
		check[1] = 1;
		return tmp;
	}

	visited[tmp] = 1;

	circle_start = dfs(visited, groud_mark, student[tmp] - 1, start);

	if (check[1]) {
		check[0] += 1;
		groud_mark[tmp] = -1;
	}
	else if (circle_start == tmp) {
		check[1] = 1;
		groud_mark[tmp] = 1;
	}
	else {
		groud_mark[tmp] = 1;
	}
	
	return circle_start;
}
/*
int main() {
	ios::sync_with_stdio(false);

	int testNum;
	int studentNum;
	int result;
	cin >> testNum;

	for (int i = 0; i < testNum; i++) {
		cin >> studentNum;
		result = 0;
		for (int j = 0; j < studentNum; j++) {
			cin >> student[j];
		}
		int visited[100000] = { 0, };
		int groud_mark[100000] = { 0, };
		for (int j = 0; j < studentNum; j++) {
			check[0] = 0;
			check[1] = 0;
			if (!visited[j]) {
				dfs(visited, groud_mark, j, j);
				result += check[0];
			}
		}
		cout << result << endl;

	}
	return 0;
}
*/
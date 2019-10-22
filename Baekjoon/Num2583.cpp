#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100] = {0,};
int visited[100][100] = {0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int n, int m) {
	int result = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		if (map[ny][nx] || visited[ny][nx]) {
			continue;
		}

		visited[ny][nx] = 1;
		result += dfs(nx, ny, n, m);
	}
	
	return result;
}

int main()
{
	int m, n, k;
	int x1, y1, x2, y2;
	int result;
	vector<int> answer;

	cin >> m >> n >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				map[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				result = dfs(j, i, n, m);
				answer.push_back(result);
			}
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}

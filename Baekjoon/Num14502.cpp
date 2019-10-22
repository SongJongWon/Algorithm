#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> virus;
vector<vector<int>> map;

int bfs(vector<pair<int, int>> list) {
	int answer = 0;
	queue<pair<int, int>> q;
	vector<vector<int>> copy_map;
	int l_size = list.size();
	int size = virus.size();
	int temp_x, temp_y;
	int next_x, next_y;

	//init
	copy_map.assign(map.begin(), map.end());
	for (int i = 0; i < l_size; i++) {
		copy_map[list[i].second][list[i].first] = 1;
	}

	for (int i = 0; i < size; i++) {
		q.push({virus[i].first, virus[i].second});
	}

	while (!q.empty()) {
		temp_x = q.front().first;
		temp_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_x = temp_x + dx[i];
			next_y = temp_y + dy[i];

			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
			if (copy_map[next_y][next_x] != 0) continue;

			copy_map[next_y][next_x] = 2;
			q.push({ next_x, next_y });
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_map[i][j] == 0) answer += 1;
		}
	}

	return answer;
}

int solution() {
	int answer = 0, comp;
	int size = n*m;
	vector<pair<int, int>> list;
	
	for (int i = 0; i < 3; i++) {
		list.push_back({});
	}

	for (int i = 0; i < size-2; i++) {
		if (map[i / m][i % m] != 0) continue;
		list[0].first = i % m;
		list[0].second = i / m;
		for (int j = i+1; j < size-1; j++) {
			if (map[j / m][j % m] != 0) continue;
			list[1].first = j % m;
			list[1].second = j / m;
			for (int z = j+1; z < size; z++) {
				if (map[z / m][z % m] != 0) continue;
				list[2].first = z % m;
				list[2].second = z / m;

				comp = bfs(list);
				if(answer < comp) answer = comp;
			}
		}
	}

	return answer;
}


int main() {

	map.assign(8, vector<int>(8, 0));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ j, i });
		}
	}

	cout << solution();
}

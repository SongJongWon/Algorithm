#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][100];
bool visited[100][100][4] = { 0, };
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int start_inf[3];
int end_inf[3];

int change(int dir) {
	int answer;

	switch (dir) {
	case 1:
		answer = 0;
		break;
	case 2:
		answer = 2;
		break;
	case 3:
		answer = 1;
		break;
	case 4:
		answer = 3;
		break;
	}

	return answer;
}

int solution() {
	int answer = 0, size;
	int temp_x, temp_y, temp_dir;
	int next_x, next_y;
	int left_dir, right_dir;

	queue<vector<int>> q;

	q.push({ start_inf[0], start_inf[1], start_inf[2] });
	visited[start_inf[1]][start_inf[0]][start_inf[2]] = 1;

	while (!q.empty()) {
		size = q.size();

		for (int j = 0; j < size; j++) {
			temp_x = q.front()[0];
			temp_y = q.front()[1];
			temp_dir = q.front()[2];
			q.pop();

			if (temp_x == end_inf[0] && temp_y == end_inf[1] && temp_dir == end_inf[2]) return answer;

			for (int i = 1; i < 4; i++) {
				next_x = temp_x + (dx[temp_dir] * i);
				next_y = temp_y + (dy[temp_dir] * i);

				if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1) continue;
				if (visited[next_y][next_x][temp_dir]) continue;
				if (map[next_y][next_x] == 1) break;

				visited[next_y][next_x][temp_dir] = 1;

				q.push({ next_x , next_y, temp_dir });
			}

			right_dir = (temp_dir + 1) % 4;
			left_dir = temp_dir - 1;
			if (left_dir < 0) left_dir += 4;

			if (!visited[temp_y][temp_x][right_dir]) {
				visited[temp_y][temp_x][right_dir] = 1;
				q.push({ temp_x , temp_y, right_dir });
			}
			if (!visited[temp_y][temp_x][left_dir]) {
				visited[temp_y][temp_x][left_dir] = 1;
				q.push({ temp_x , temp_y, left_dir });
			}
		}
		answer += 1;
	}

	return -1;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> start_inf[1] >> start_inf[0] >> start_inf[2];
	cin >> end_inf[1] >> end_inf[0] >> end_inf[2];

	start_inf[0] -= 1;
	start_inf[1] -= 1;
	start_inf[2] = change(start_inf[2]);
	end_inf[0] -= 1;
	end_inf[1] -= 1;
	end_inf[2] = change(end_inf[2]);

	cout << solution();

	return 0;
}

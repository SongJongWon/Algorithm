#include <iostream>
#include <queue>

using namespace std;

int n;
int map[20][20] = { 0, };
bool visited[20][20] = { 0, };
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
int shark[4]; // 0 : x, 1 : y, 2 : size, 3 : eaten_num

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		} 
	}
}

int solution() {
	int answer = 0, q_size = 0, step = 0;
	int temp_x, temp_y, next_x, next_y;
	int check_x = n, check_y = n;
	bool con = true;
	queue<pair<int, int>> q;

	q.push({ shark[0], shark[1] });
	visited[shark[1]][shark[0]] = true;

	while (!q.empty()) {
		q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			temp_x = q.front().first;
			temp_y = q.front().second;
			q.pop();

			if (map[temp_y][temp_x] != 0 && map[temp_y][temp_x] < shark[2] && (temp_y < check_y || (temp_y == check_y && temp_x < check_x))) {
				check_x = temp_x;
				check_y = temp_y;
				con = false;
			}

			if(con) {
				for (int j = 0; j < 4; j++) {
					next_x = temp_x + dx[j];
					next_y = temp_y + dy[j];

					if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > n - 1) continue;
					if (map[next_y][next_x] > shark[2]) continue;
					if (visited[next_y][next_x]) continue;

					visited[next_y][next_x] = true;
				
					q.push({ next_x, next_y });
				}
			}
		}

		if (!con) {
			map[check_y][check_x] = 0;
			answer += step;

			shark[0] = check_x;
			shark[1] = check_y;
			shark[3] += 1;
			if (shark[3] == shark[2]) {
				shark[2] += 1;
				shark[3] = 0;
			}

			init();

			while (!q.empty()) q.pop();

			q.push({ check_x, check_y });

			visited[check_y][check_x] = true;

			step = 0;
			check_x = n;
			check_y = n;
			con = true;

		}
		else step += 1;
	}

	return answer;
}

int main() {
	int input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == 9) {
				shark[0] = j;
				shark[1] = i;
				shark[2] = 2;
				shark[3] = 0;
				input = 0;
			}
			map[i][j] = input;
		}
	}

	cout << solution();

	return 0;
}

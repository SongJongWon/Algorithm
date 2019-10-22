#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> board;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int red_state[2] = { 0, }; // 0 : x / 1 : y
int blue_state[2] = { 0, };
int answer = 11;

void move(vector<vector<char>> prev_board, int dir, int count, int red_temp_x, int red_temp_y, int blue_temp_x, int blue_temp_y){
	int next_x, next_y, next_dir;
	bool color_check = false; // 0 : red / 1 : blue
	bool finish = false;
	int queue_x, queue_y;
	queue<vector<int>> q;
	vector<vector<char>> copy_board;
	copy_board.assign(prev_board.begin(), prev_board.end());

	switch (dir) {
	case 0:
		if (red_temp_y == blue_temp_y && blue_temp_x > red_temp_x) {
			color_check = true;
		}
		break;
	case 1:
		if (red_temp_y == blue_temp_y && blue_temp_x < red_temp_x) {
			color_check = true;
		}
		break;
	case 2:
		if (red_temp_x == blue_temp_x && blue_temp_y > red_temp_y) {
			color_check = true;
		}
		break;
	case 3:
		if (red_temp_x == blue_temp_x && blue_temp_y < red_temp_y) {
			color_check = true;
		}
		break;
	}

	if (!color_check) {
		q.push({ color_check, red_temp_x, red_temp_y });
		q.push({ !color_check, blue_temp_x, blue_temp_y });
	}
	else {
		q.push({ color_check, blue_temp_x, blue_temp_y });
		q.push({ !color_check, red_temp_x, red_temp_y });
	}

	while(!q.empty()) {
		color_check = q.front()[0];
		queue_x = q.front()[1];
		queue_y = q.front()[2];
		q.pop();

		copy_board[queue_y][queue_x] = '.';

		while (1) {
			next_x = queue_x + dx[dir];
			next_y = queue_y + dy[dir];

			if (copy_board[next_y][next_x] == 'O') {
				if (!q.empty()) {
					if (!color_check) {
						finish = true;
						break;
					}
				}
				else {
					if (!color_check && answer > count) answer = count;
					return;
				}
				
				return;
			}

			if (copy_board[next_y][next_x] != '.') {
				if (!color_check) {
					red_temp_x = queue_x;
					red_temp_y = queue_y;
					copy_board[queue_y][queue_x] = 'R';
				}
				else {
					blue_temp_x = queue_x;
					blue_temp_y = queue_y;
					copy_board[queue_y][queue_x] = 'B';
				}
				break;
			}

			queue_x = next_x;
			queue_y = next_y;
		}
	}

	if (finish && count < answer) {
		answer = count;
		return;
	}

	if (dir > 1) next_dir = 0;
	else next_dir = 2;

	if (count == 10) return;

	move(copy_board, next_dir, count + 1, red_temp_x, red_temp_y, blue_temp_x, blue_temp_y);
	move(copy_board, next_dir+1, count + 1, red_temp_x, red_temp_y, blue_temp_x, blue_temp_y);
}

void solution() {
	for (int i = 0; i < 4; i++) {
		move(board, i, 1, red_state[0], red_state[1], blue_state[0], blue_state[1]);
	}
}

int main() {
	board.assign(10, vector<char>(10, '.'));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B') {
				blue_state[0] = j;
				blue_state[1] = i;
			}
			else if (board[i][j] == 'R') {
				red_state[0] = j;
				red_state[1] = i;
			}
		}
	}

	solution();

	if (answer == 11) cout << "-1";
	else cout << answer;

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c;
int start_pos[2];
int end_pos[2];
int answer[2];
char answer_char;

char map[25][25];
int total_num = 0;

void solution() {
	int temp_x, temp_y, next_x, next_y, dir = -1, temp_num = 0;
	vector<char> list;
	int check_dir, check_num = 0;
	bool first = true, change = false;
	queue<char> q;

	//check
	for (int i = 0; i < 4; i++) {
		next_x = start_pos[0] + dx[i];
		next_y = start_pos[1] + dy[i];

		if (next_x >= c || next_x < 0 || next_y < 0 || next_y >= r) continue;
		if (map[next_y][next_x] == '.') continue;

		switch (i) {
		case 0:
			if(map[next_y][next_x] == '-' || map[next_y][next_x] == '+' || map[next_y][next_x] == '3' || map[next_y][next_x] == '4') dir = i;
			break;
		case 1:
			if (map[next_y][next_x] == '|' || map[next_y][next_x] == '+' || map[next_y][next_x] == '2' || map[next_y][next_x] == '3') dir = i;
			break;
		case 2:
			if (map[next_y][next_x] == '-' || map[next_y][next_x] == '+' || map[next_y][next_x] == '1' || map[next_y][next_x] == '2') dir = i;
			break;
		case 3:
			if (map[next_y][next_x] == '|' || map[next_y][next_x] == '+' || map[next_y][next_x] == '1' || map[next_y][next_x] == '4') dir = i;
			break;
		}

		if (dir != -1) break;
	}

	while (true) {
		temp_x = next_x;
		temp_y = next_y;

		if (map[temp_y][temp_x] == 'Z') {
			//break;
			if (total_num + 1 == temp_num) break;
			else change = true;
		}

		if (map[temp_y][temp_x] == '.') {
			if (first) {
				answer[0] = temp_x;
				answer[1] = temp_y;

				switch (dir) {
				case 0:
					q.push('-');
					q.push('3');
					q.push('4');
					q.push('+');
					break;
				case 1:
					q.push('|');
					q.push('2');
					q.push('3');
					q.push('+');
					break;
				case 2:
					q.push('-');
					q.push('1');
					q.push('2');
					q.push('+');
					break;
				case 3:
					q.push('|');
					q.push('1');
					q.push('4');
					q.push('+');
					break;
				}
				check_dir = dir;
				check_num = temp_num;
				temp_num -= 1;
				first = false;
			}
			else change = true;
		}

		if (change) {
			temp_x = answer[0];
			temp_y = answer[1];
			map[temp_y][temp_x] = q.front();
			q.pop();
			dir = check_dir;
			temp_num = check_num;

			answer_char = map[temp_y][temp_x];
			if (answer_char == '+') total_num += 1;
			change = false;
		}

		switch (dir) {
		case 0:
			if (map[temp_y][temp_x] == '-' || map[temp_y][temp_x] == '+') {
				dir = 0;
			}
			else if (map[temp_y][temp_x] == '3') {
				dir = 3	;
			}
			else if (map[temp_y][temp_x] == '4') {
				dir += 1;
			}
			else change = true;
			break;
		case 1:
			if (map[temp_y][temp_x] == '|' || map[temp_y][temp_x] == '+') {
				dir = 1;
			}
			else if (map[temp_y][temp_x] == '2') {
				dir -= 1;
			}
			else if (map[temp_y][temp_x] == '3') {
				dir += 1;
			}
			else change = true;
			break;
		case 2:
			if (map[temp_y][temp_x] == '-' || map[temp_y][temp_x] == '+') {
				dir = 2;
			}
			else if (map[temp_y][temp_x] == '1') {
				dir -= 1;
			}
			else if (map[temp_y][temp_x] == '2') {
				dir += 1;
			}
			else change = true;
			break;
		case 3:
			if (map[temp_y][temp_x] == '|' || map[temp_y][temp_x] == '+') {
				dir = 3;
			}
			else if (map[temp_y][temp_x] == '1') {
				dir = 0;
			}
			else if (map[temp_y][temp_x] == '4') {
				dir -= 1;
			}
			else change = true;
			break;
		}

		next_x = temp_x + dx[dir];
		next_y = temp_y + dy[dir];

		temp_num += 1;

		if (next_x >= c || next_x < 0 || next_y < 0 || next_y >= r) {
			change = true;
		}
	}

	return;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				start_pos[0] = j;
				start_pos[1] = i;
			}
			else if (map[i][j] == 'Z') {
				end_pos[0] = j;
				end_pos[1] = i;
			}
			else if (map[i][j] == '+') total_num += 2;
			else if (map[i][j] != '.') total_num += 1;
		}
	}

	solution();

	cout << answer[1]+1 << " " << answer[0]+1 << " " << answer_char << endl;
	

	return 0;
}

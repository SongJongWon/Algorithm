#include <iostream>
#include <vector>

using namespace std;

int map[20][20] = { 0, };
int n, m; // n : 세로, m : 가로
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int hor[4] = { 0 ,2, 5, 3 };
int hor_index = 0; 
int ver[4] = { 0, 4, 5, 1 };
int ver_index = 0;
int dice_x, dice_y;
int dice[6] = { 0, };

int solution(int command) {
	int answer = 0;

	//cout << command << " : " << hor_index << " " << ver_index << endl;

	int next_x = dice_x + dx[command];
	int next_y = dice_y + dy[command];

	if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) return -1;
	
	//dice_index updete
	switch (command) {
	case 0:
		hor_index -= 1;
		if (hor_index < 0) hor_index += 4;
		ver[ver_index] = hor[hor_index];
		ver[(ver_index + 2) % 4] = hor[(hor_index + 2) % 4];
		break;
	case 1:
		hor_index = (hor_index + 1) % 4;
		ver[ver_index] = hor[hor_index];
		ver[(ver_index + 2) % 4] = hor[(hor_index + 2) % 4];
		break;
	case 2:
		ver_index = (ver_index + 1) % 4;
		hor[hor_index] = ver[ver_index];
		hor[(hor_index + 2) % 4] = ver[(ver_index + 2) % 4];
		break;
	case 3:
		ver_index -= 1;
		if (ver_index < 0) ver_index += 4;
		hor[hor_index] = ver[ver_index];
		hor[(hor_index + 2) % 4] = ver[(ver_index + 2) % 4];
		break;
	}

	if (map[next_y][next_x] != 0) {
		dice[ver[(ver_index + 2) % 4]] = map[next_y][next_x];
		map[next_y][next_x] = 0;
	}
	else {
		map[next_y][next_x] = dice[ver[(ver_index + 2) % 4]];
	}
	/*
	for (int i = 0; i < 6; i++) {
		cout << dice[i] << " ";
	}
	cout << "-------" << endl;
	cout << dice_index_bottom << " " << ver[ver_index] << endl;
	*/
	dice_x = next_x;
	dice_y = next_y;
	/*
	cout << "----" << ver_index << " : "<< ver[ver_index] << "------" << hor_index << " : "<< hor[hor_index] << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == dice_y && j == dice_x) cout << "A";
			else cout << map[i][j];
		}
		cout << endl;
	}
	*/
	answer = dice[ver[ver_index]];

	return answer;
}

int main() {
	int k;
	int command;
	int answer;

	cin >> n >> m >> dice_y >> dice_x >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> command;
		answer = solution(command - 1);
		if (answer != -1) {
			cout << answer << '\n';
		}
	}

	return 0;
}

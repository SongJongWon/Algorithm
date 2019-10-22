#include <iostream>
#include <vector>

using namespace std;
int n, m;
char map[8][8];
char visited[8][8];
vector<vector<int>> cctv_list;
vector<vector<int>> dict_list;
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };
int answer = 999999;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = map[i][j];
		}
	}
}

void update() {
	int comp = 0;
	int size = dict_list.size();
	int temp_dict, temp_x, temp_y;
	init();

	for (int i = 0; i < size; i++) {
		temp_dict = dict_list[i][0];
		temp_x = dict_list[i][1];
		temp_y = dict_list[i][2];
		while (true) {
			temp_x = temp_x + dx[temp_dict];
			temp_y = temp_y + dy[temp_dict];

			if (temp_x < 0 || temp_x > 7 || temp_y < 0 || temp_y > 7) break;
			if (visited[temp_y][temp_x] == '6') break;
			if (visited[temp_y][temp_x] == '0') visited[temp_y][temp_x] = '#';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << visited[i][j];
			if (visited[i][j] == '0') comp += 1;
		}
		//cout << endl;
	}
	//cout << "----------------------" << endl;
	
	if (comp < answer) answer = comp;
}

void recur(int temp, int size) {
	if (temp == size) {
		update();
		return;
	}

	switch (cctv_list[temp][0]) {
		case 1:
			for (int i = 0; i < 4; i++) {
				dict_list.push_back({ i, cctv_list[temp][1], cctv_list[temp][2] });
				recur(temp + 1, size);
				dict_list.pop_back();
			}
			break;
		case 2:
			for (int i = 0; i < 2; i++) {
				dict_list.push_back({ i, cctv_list[temp][1], cctv_list[temp][2] });
				dict_list.push_back({ i + 2, cctv_list[temp][1], cctv_list[temp][2] });
				recur(temp + 1, size);
				dict_list.pop_back();
				dict_list.pop_back();
			}
			break;
		case 3:
			for (int i = 0; i < 4; i++) {
				dict_list.push_back({ i%4, cctv_list[temp][1], cctv_list[temp][2] });
				dict_list.push_back({ (i + 1) % 4, cctv_list[temp][1], cctv_list[temp][2] });
				recur(temp + 1, size);
				dict_list.pop_back();
				dict_list.pop_back();
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++) {
				dict_list.push_back({ i%4, cctv_list[temp][1], cctv_list[temp][2] });
				dict_list.push_back({ (i + 1)%4, cctv_list[temp][1], cctv_list[temp][2] });
				dict_list.push_back({ (i + 2)%4, cctv_list[temp][1], cctv_list[temp][2] });
				recur(temp + 1, size);
				dict_list.pop_back();
				dict_list.pop_back();
				dict_list.pop_back();
			}
			break;
		case 5:
			for (int i = 0; i < 4; i++) {
				dict_list.push_back({ i, cctv_list[temp][1], cctv_list[temp][2] });
			}
			recur(temp + 1, size);
			for (int i = 0; i < 4; i++) {
				dict_list.pop_back();
			}
			break;
	}
}

void solution() {
	
}

int main() {
	int test_case = 1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != '0' && map[i][j] != '6') {
				cctv_list.push_back({map[i][j]-48, j, i});
			}
			/*
			if (map[i][j] == '1' || map[i][j] == '3' || map[i][j] == '4') test_case *= 4;
			else if (map[i][j] == '2') test_case *= 2;
			*/
		}
	}
	//cout << cctv_list.size() << endl;
	recur(0, cctv_list.size());
	//solution(test_case);

	cout << answer;

	return 0;
}

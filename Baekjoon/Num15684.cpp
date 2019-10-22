#include <iostream>
#include <vector>

using namespace std;

int n, m, h;
bool map[32][12] = { 0, };

void print() {
	cout << "---------------------" << endl;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}


bool check() {
	int temp_x = 0;
	//cout << "==================================" << endl;
	for (int i = 1; i <= n; i++) {
		temp_x = i;
		for (int j = 1; j <= h; j++) {
			//cout << temp_x << "->";
			if (map[j][temp_x]) temp_x += 1;
			else if (map[j][temp_x - 1]) temp_x -= 1;
		}
		//cout << endl;
		if (temp_x == i) continue;
		return false;
	}

	return true;
}

bool recur(int select, int temp_x, int temp_y) {
	bool first = true;

	if (select == 0) {
		if(check()) return true;
		else return false;
	}

	if (temp_y > h) {
		temp_x += 1;
		temp_y = 1;
	}

	for (int i = temp_x; i < n; i++) {
		for (int j = 1; j <= h; j++) {
			if (first) {
				j = temp_y;
				first = false;
			}

			if (map[j][i] == 0 && map[j][i + 1] == 0 && map[j][i - 1] == 0) {
				map[j][i] = 1;
				if (recur(select - 1, i, j + 1)) return true;
				map[j][i] = 0;
			}
		}
	}

	return false;
}

int solution() {
	int answer = -1;

	if (check()) {
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		if (recur(i + 1, 1, 1)) {
			answer = i + 1;
			break;
		}
	}


	return answer;
}

int main() {
	cin >> n >> m >> h;
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}

	cout << solution();

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int visited[101][101] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solution(int x, int y, int d, int g) {
	int size;
	int temp_x, temp_y;
	int dict, cal;
	vector<int> list;
	
	list.push_back(d);
	temp_x = x + dx[d];
	temp_y = y + dy[d];
	visited[y][x] = 1;
	visited[temp_y][temp_x] = 1;

	for (int i = 1; i <= g; i++) {
		size = list.size();
		dict = list.back();
		dict += 1;
		if (dict > 3) dict -= 4;
		temp_x = temp_x + dx[dict];
		temp_y = temp_y + dy[dict];

		visited[temp_y][temp_x] = 1;
		list.push_back(dict);
		
		for (int j = size - 1; j > 0; j--) {
			cal = list[j] - list[j - 1];
			if (cal == -3) cal = 1;
			if (cal == 3) cal = -1;
			cal *= -1;

			dict += cal;
			if (dict > 3) dict -= 4;
			else if (dict < 0) dict += 4;
			temp_x = temp_x + dx[dict];
			temp_y = temp_y + dy[dict];
			
			visited[temp_y][temp_x] = 1;
			list.push_back(dict);
		}
	}

}

int check() {
	int answer = 0;
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] == 1) {
				if (visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) answer += 1;
			}
		}
	}
	return answer;
}

int main() {
	int N;
	int x, y, d, g;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		solution(x, y, d, g);
	}

	cout << check();

	return 0;
}

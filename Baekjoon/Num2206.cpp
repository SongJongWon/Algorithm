#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;
char map[1000][1000];
int visited[1000][1000] = { 0, };

string change_xy(int x, int y, int route) {
	string sx, sy, sroute;
	int x_size, y_size, route_size;

	sx = to_string(x);
	sy = to_string(y);
	sroute = to_string(route);

	x_size = sx.size();
	y_size = sy.size();
	route_size = sroute.size();

	x_size = 4 - x_size;
	y_size = 4 - y_size;
	route_size = 4 - route_size;

	while (x_size--) {
		sx = '0' + sx;
	}

	while (y_size--) {
		sy = '0' + sy;
	}

	while (route_size--) {
		sroute = '0' + sroute;
	}

	return sx + sy + sroute;
}

int solution() {
	queue<pair<int, string>> q;
	int temp_x, temp_y, route;
	string temp_sx, temp_sy, sroute;
	int next_x, next_y;
	string next_xy;
	string xy;
	bool breakWall;
	int q_size;
	int depth = 1;

	q.push({ true, "000000000000" });
	visited[0][0] = true;

	while (!q.empty()) {
		q_size = q.size();

		while (q_size--) {
			breakWall = q.front().first;
			xy = q.front().second;
			q.pop();

			temp_sx = xy.substr(0, 4);
			temp_sy = xy.substr(4, 4);
			sroute = xy.substr(8, 4);

			temp_x = stoi(temp_sx);
			temp_y = stoi(temp_sy);
			route = stoi(sroute);

			//cout << "depth : " << depth << " " << temp_sx << " " << temp_sy << " " << sroute << endl;

			if (temp_x == m-1 && temp_y == n-1) {
				return depth;
			}
			
			for (int i = 0; i < 4; i++) {
				next_x = temp_x + dx[i];
				next_y = temp_y + dy[i];

				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

				if (visited[next_y][next_x] == 1) continue;
				else if (visited[next_y][next_x] == 2 && route != 0) continue;

				if (map[next_y][next_x] == '0') {
					next_xy = change_xy(next_x, next_y, route);
					//cout << "1 " << depth << " " << next_x << " " << next_y << " : " << next_xy << endl;
					if (breakWall) visited[next_y][next_x] = 1;
					else visited[next_y][next_x] = 2;
					q.push({ breakWall, next_xy });
				}
				else if(breakWall){
					next_xy = change_xy(next_x, next_y, route + 1);
					//cout << "2 " << depth << " " << next_x << " " << next_y << " : " << next_xy << endl;
					visited[next_y][next_x] = 2;
					q.push({ false, next_xy });
				}
			}
		}
		depth += 1;
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << solution();

	return 0;
}

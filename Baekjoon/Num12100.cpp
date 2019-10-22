#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> map;
int n, answer;

void recur(int size, int temp, int rotation, vector<vector<int>> prev) {
	if (size == temp) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//cout << prev[i][j];
				if (answer < prev[i][j]) answer = prev[i][j];
			}
			//cout << endl;
		}
		//cout << "--------------" << endl;
		return;
	}
	
	vector<vector<int>> con;
	//copy
	switch (rotation) {
	case 0:
		con.assign(prev.begin(), prev.end());
		break;
	case 1:
		for (int i = 0; i < n; i++) {
			con.push_back({});
			for (int j = 0; j < n; j++) {
				con[i].push_back(prev[n - 1 - j][i]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			con.push_back({});
			for (int j = 0; j < n; j++) {
				con[i].push_back(prev[n - 1 - i][n - 1 - j]);
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			con.push_back({});
			for (int j = 0; j < n; j++) {
				con[i].push_back(prev[j][n - 1 - i]);
			}
		}
		break;
	}

	int temp_value, prev_value, temp_x;
	for (int i = 0; i < n; i++) {
		temp_value = 0; 
		prev_value = 0;
		temp_x = n - 1;
		
		for (int j = n - 1; j >= 0; j--) {
			if (con[i][j] != 0) {
				if (prev_value == 0) prev_value = con[i][j];
				else {
					temp_value = con[i][j];
					if (temp_value == prev_value) {
						con[i][temp_x] = temp_value + prev_value;
						prev_value = 0;
					}
					else {
						con[i][temp_x] = prev_value;
						prev_value = temp_value;
					}
					//cout << con[i][temp_x] << " : test" << temp_x << endl;
					temp_x -= 1;
				}
			}
		}
		if (prev_value != 0) {
			con[i][temp_x] = prev_value;
			temp_x -= 1;
		}
		for (int j = temp_x; j >= 0; j--) {
			con[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		//recursive
		recur(size, temp + 1, i, con);
	}

}

/*
void solution() {
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> con;
		switch (i) {
		case 0:
			con.assign(map.begin(), map.end());
			break;
		case 1:
			for (int i = 0; i < n; i++) {
				con.push_back({});
				for (int j = 0; j < n; j++) {
					con[i].push_back(map[n - 1 - j][i]);
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				con.push_back({});
				for (int j = 0; j < n; j++) {
					con[i].push_back(map[n - 1 - i][n - 1 - j]);
				}
			}
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				con.push_back({});
				for (int j = 0; j < n; j++) {
					con[i].push_back(map[j][n - 1 - i]);
				}
			}
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << con[i][j] << " ";
			}
			cout << endl;
		}
		cout << "--------------" << endl;
		recur(5, 0, 0, con);
	}
}
*/

int main() {
	int input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		map.push_back({});
		for (int j = 0; j < n; j++) {
			cin >> input;
			map[i].push_back(input);
		}
	}
	for (int i = 0; i < 4; i++) {
		//recursive
		recur(5, 0, i, map);
	}
	
	cout << answer;

	return 0;
}

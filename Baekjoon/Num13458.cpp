#include <iostream>
#include <vector>

using namespace std;

int n, b, c;
int map[1000000];

unsigned long long int solution() {
	unsigned long long int answer = 0;

	for (int i = 0; i < n; i++) {
		map[i] -= b;
		answer += 1;

		if (map[i] > 0) {
			answer += map[i] / c;
			if (map[i] % c != 0) answer += 1;
		}
	}

	return answer;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	cin >> b >> c;

	cout << solution();

	return 0;
}

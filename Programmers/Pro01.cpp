#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int size = name.size();

	char joyStick_temp;
	int min_leftright = size - 1;
	int next_temp;

	// 상하 계산
	for (int i = 0; i < size; i++) {
		if (name[i] - 'A' > 'Z' - name[i] + 1) answer += 'Z' - name[i] + 1;
		else answer += name[i] - 'A';
	}

	// 좌우 계산 : brute force
	for (int temp = 0; temp < size; temp++) {
		next_temp = temp + 1;
		while (true) {
			if (name[next_temp] != 'A' || next_temp == size - 1) break;
			next_temp += 1;
		}
		min_leftright = min(min_leftright, temp + temp + size - next_temp);
	}

	answer += min_leftright;

	return answer;
}

int main() {
	string name;

	cin >> name;

	cout << solution(name);

	return 0;
}
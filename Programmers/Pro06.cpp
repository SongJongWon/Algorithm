#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <climits>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int size = rocks.size();
	int min;
	list<int> ls;
	list<int>::iterator iter, check, check_next, check_prev;

	rocks.push_back(0);
	rocks.push_back(distance);

	sort(rocks.begin(), rocks.end());

	for (int i = 0; i < size + 1; i++) {
		ls.push_back(rocks[i + 1] - rocks[i]);
	}

	for (int i = 0; i < n; i++) {
		min = INT_MAX;

		for (iter = ls.begin(); iter != ls.end(); iter++) {
			if (*iter <= min) {
				min = *iter;
				check = iter;
			}
		}

		if (check == ls.begin()) {
			check_next = ++check;
			check--;
			*check_next += *check;
		}
		else if (check == --ls.end()) {
			check_prev = --check;
			check++;
			*check_prev += *check;
		}
		else {
			check_next = ++check;
			check--;
			check_prev = --check;
			check++;
			if (*check_next >= *check_prev) {
				*check_prev += *check;
			}
			else {
				*check_next += *check;
			}
		}
		ls.erase(check);
	}

	answer = INT_MAX;
	for (iter = ls.begin(); iter != ls.end(); iter++) {
		if (*iter < answer) {
			answer = *iter;
		}
	}

	return answer;
}

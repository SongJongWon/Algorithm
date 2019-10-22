#include <vector>
#include <algorithm>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

bool comp2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int index = 0;
	long long size = food_times.size();
	bool check = false;
	int i;
	long long food_size, f_size;
	long long total_sub = 0;

	vector<pair<int, int>> food_info;

	for (i = 0; i < size; i++) {
		food_info.push_back(make_pair(food_times[i], i));
	}

	sort(food_info.begin(), food_info.end(), comp1);

	while (!check) {
		food_size = food_info[index].first - total_sub;
		f_size = size - index;

		for (i = food_size; i > 0; i--) {
			if (k - f_size * i >= 0) {
				k -= f_size * i;
				break;
			}
		}

		if (i != food_size || k == 0) {
			check = true;
		}

		total_sub += i;

		for (int j = index; j < size; j++) {
			if (food_info[j].first <= total_sub) {
				index += 1;
			}
			else break;
		}

		if (index == size) return -1;
	}

	sort(food_info.begin() + index, food_info.end(), comp2);

	answer = food_info[index + k].second + 1;

	return answer;
}

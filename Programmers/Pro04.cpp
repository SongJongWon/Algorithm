#include <iostream>
#include <vector>
#include <string>

using namespace std;
int index_num[19];
int diff, result = 0;

int pow(int n) {
	int answer = 2;
	for (int i = 0; i < n; i++) {
		answer *= 3;
	}
	return answer;
}

int checklength(int n) {
	long long temp = 1;
	long long next;
	int result;
	for (int i = 1; i < 20; i++) {
		index_num[i - 1] = pow(i-1);
		next = temp * 3 + 2;
		if (n > temp && n <= next) {
			result = i;
			break;
		}
		temp = next;
	}

	return result;
}

int checkmin(int size) {
	int answer = 1;
	for (int i = 0; i < size; i++) {
		answer *= 3;
	}
	return answer + size * 2;
}

void bruteForce(int index_temp, int size, int sum, int min) {
	int check = sum;
	int checksize = size;
	for (int i = index_temp; i >= 0; i--) {
		check += index_num[i] * checksize;
		checksize += 2;
	}

	for (int i = min; i <= size; i++) {
		int newsum = sum + i * index_num[index_temp];
		if (newsum > diff) break;
		if (check > 0 && check < diff) break;
		if (index_temp == 0) {
			if (diff == newsum) result += 1;
			continue;
		}
		bruteForce(index_temp - 1, size + 2, newsum, i);
	}
}

int solution(int n) {
	int answer = 0;
	long long min;
	int temp = 0, length;
	int size, max_index;
	length = checklength(n);
	min = checkmin(length);

	diff = n - min;
	max_index = length;
	result = 0;
	if (length == 1) {
		if (diff == 0) result = 1;
	}
	else bruteForce(length - 2, 2, 0, 0);

	answer = result;

	return answer;
}

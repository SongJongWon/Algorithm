#include "pch.h"
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	n = n - 1;
	int quotient = n / 3;
	int remainder = n % 3;
	string tempAnswer;
	string answer = "";

	if (quotient > 0) answer = solution(quotient);
	if (remainder == 0) tempAnswer = "1";
	else if (remainder == 1) tempAnswer = "2";
	else tempAnswer = "4";
	answer += tempAnswer;
	return answer;
}
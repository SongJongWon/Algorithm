#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
1. (규칙 1) 특정 단어를 선택하여 글자 사이마다 같은 기호를 넣는다. 
2. (규칙 2) 특정 단어를 선택하여 단어 앞뒤에 같은 기호를 넣는다.
3. (규칙 3) 마지막으로 원래 문구에 있던 공백을 제거한다.
*/
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	priority_queue<pair<int, string>> result_vec; // string : slice , int : pos
	string slice = "";
	string answer = "";
	int slice_pos;
	int i, j;
	bool logic1, logic2;
	char check;
	int size = sentence.size();
	int alp[26][3] = { 0, }; // first = pos_start, second = pos_end, third = count
	

	for (i = 0; i < size; i++) {
		if (sentence[i] > 96 && sentence[i] < 123) {
			if (alp[sentence[i] - 97][2] == 0) alp[sentence[i] - 97][0] = i;
			alp[sentence[i] - 97][1] = i;
			alp[sentence[i] - 97][2] += 1;
		}
		else if(sentence[i] > 90 || sentence[i] < 65) return "invalid";
	}

	//logic 1
	for (i = 0; i < 26; i++) {
		if (alp[i][2] == 0) continue;
		if (alp[i][2] == 2) {
			if (alp[i][0] < 2 || alp[i][1] > size - 3) continue;
			else if (sentence[alp[i][0] - 2] < 97 || (sentence[alp[i][0] - 2] != sentence[alp[i][1] + 2])) continue;
		}
		logic1 = true;
		slice = "";
		for (j = alp[i][0] - 1; j < alp[i][1] + 2; j++) {
			if(j < 0 || j >= size) return "invalid";
			if (logic1) {
				if (sentence[j] > 90 || sentence[j] < 65) return "invalid";
				slice += sentence[j];
				logic1 = false;
			}
			else {
				if (sentence[j] != char(i + 97)) return "invalid";
				logic1 = true;
			}
			sentence[j] = char(i + 97);
		}

		result_vec.push({ -alp[i][0] , slice });
		alp[i][1] = 0;
		alp[i][2] = 0;
	}

	//cout << "1 : "<< sentence << endl;

	for (i = 0; i < 26; i++) {
		slice = "";
		logic2 = false;
		if (alp[i][2] != 2) continue;
		if (alp[i][0] + 1 == alp[i][1]) return "invalid";
		for (j = alp[i][0]; j < alp[i][1] + 1; j++) {
			if (sentence[j] < 91 && sentence[j] > 64) {
				if(logic2) return "invalid";
				slice += sentence[j];
			}
			else if(sentence[j] == '{') return "invalid";
			else if (sentence[j] != char(i + 97) && sentence[j] > 96 && sentence[j] < 123) {
				if (!logic2) check = sentence[j];
				if (logic2 && check != sentence[j]) return "invalid";
				if(!slice.empty()) return "invalid";
				logic2 = true;
			}
			sentence[j] = '{';
		}
		if (!slice.empty()) result_vec.push({ -alp[i][0] , slice });
	}

	//cout << "2 : " << sentence << endl;

	slice = "";
	for (i = 0; i < size; i++) {
		if (sentence[i] < 91 && sentence[i] > 64) {
			if (slice.empty()) {
				slice_pos = i;
			}
			slice += sentence[i];
		}
		else {
			if (!slice.empty()) {
				result_vec.push({ -slice_pos , slice });
				slice = "";
			}
		}
	}
	if (!slice.empty()) {
		result_vec.push({ -slice_pos , slice });
	}

	while (result_vec.size()) {
		answer += result_vec.top().second;
		result_vec.pop();
		answer.push_back(' ');
	}
	answer.pop_back();
	
	return answer;
}

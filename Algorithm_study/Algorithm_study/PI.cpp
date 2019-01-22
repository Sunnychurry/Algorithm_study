#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

string num;
int cache[10000];


int levelCheck(int start, int end) {
	string temp = num.substr(start, end - start + 1);													// start부터 end-start+1크기만큼 string 뽑아냄

	if (temp == string(temp.size(), temp[0])) return 1;												// 첫글자로 같게한것과 string 같으면 level 1

	bool progressive = true;
	for (int i = 0; i < temp.size() - 1; i++) {
		if (temp[i + 1] - temp[i] != temp[1] - temp[0]) progressive = false;						// 처음 등차와 나중 등차가 모두같은경우 확인(등차수열인지)
	}
	if (progressive && abs(temp[1] - temp[0]) == 1) return 2;										// 등차가 1인경우 level 2

	bool alternating = true;
	for (int i = 0; i < temp.size(); i++) if (temp[i] != temp[i % 2]) alternating = false;			// 짝수는 짝수랑 홀수는 홀수랑 같은경우 확인 (번갈아등장level)

	if (alternating) return 4;																		// 번갈아등장 level 4
	if (progressive) return 5;																		// 등차 1아닌 수열 level 5
	return 10;
}

int recursive(int pos) {
	if (pos == num.size()) return 0;										// base case
	else if (pos > num.size()) return 9999;									// 1이나 2개의 숫자가 마지막에 남는경우 처리

	int &ret = cache[pos];
	if (ret != -1) return ret;

	ret = recursive(pos + 3) + levelCheck(pos, pos + 2);					// 3개 분할
	ret = min(ret, recursive(pos + 4) + levelCheck(pos, pos + 3));			// 4개 분할
	ret = min(ret, recursive(pos + 5) + levelCheck(pos, pos + 4));			// 5개 분할

	return ret;
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> num;
		cout << recursive(0) << endl;
	}
	return 0;
}
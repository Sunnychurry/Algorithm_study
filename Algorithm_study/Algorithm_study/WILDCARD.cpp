#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cache[101][101];							// 메모이제이션,  -1은 계산되지않음, 1은 해당입력이 일치함, 0은 일치하지않음
string pattern;
string filename;
vector<string> result;

bool compare(string a, string b)
{
	return a < b;
}


bool matchMemoized(int patt_pos, int name_pos) {											//	O(n^2)
	int& ret = cache[patt_pos][name_pos];													// 메모이제이션
	if (ret != -1) return ret;

	while (name_pos < filename.length() && patt_pos < pattern.length() && (pattern[patt_pos] == '?' || pattern[patt_pos] == filename[name_pos]))	// ?거나 같거나
	{
		return ret = matchMemoized(patt_pos + 1, name_pos + 1);																			// 다음 글자부터 일치하는지확인
	}

	if (patt_pos == pattern.length()) return ret = (name_pos == filename.length());					// 패턴이 끝까지 도달한 경우 name도 끝까지 도달하면 일치

	if (pattern[patt_pos] == '*') {				// 패턴이 별일 경우 패턴 다음글자가 현재 name pos부터 있는지 재귀 or 다음 name pos부터 현재 패턴(*부터시작)이 있는지 재귀 -> 모든경우 cache저장
		if (matchMemoized(patt_pos + 1, name_pos) || ((name_pos < filename.length()) && matchMemoized(patt_pos, name_pos + 1))) return ret = 1;
	}

	return ret = 0;
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> pattern;
		cin >> n;
		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> filename;
			if (matchMemoized(0, 0)) result.push_back(filename);					// 일치하는 것들 vector에 담음
		}

		sort(result.begin(), result.end(), compare);								// string 비교로 정렬
		for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
		result.clear();
	}
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cache[101][101];							// �޸������̼�,  -1�� ����������, 1�� �ش��Է��� ��ġ��, 0�� ��ġ��������
string pattern;
string filename;
vector<string> result;

bool compare(string a, string b)
{
	return a < b;
}


bool matchMemoized(int patt_pos, int name_pos) {											//	O(n^2)
	int& ret = cache[patt_pos][name_pos];													// �޸������̼�
	if (ret != -1) return ret;

	while (name_pos < filename.length() && patt_pos < pattern.length() && (pattern[patt_pos] == '?' || pattern[patt_pos] == filename[name_pos]))	// ?�ų� ���ų�
	{
		return ret = matchMemoized(patt_pos + 1, name_pos + 1);																			// ���� ���ں��� ��ġ�ϴ���Ȯ��
	}

	if (patt_pos == pattern.length()) return ret = (name_pos == filename.length());					// ������ ������ ������ ��� name�� ������ �����ϸ� ��ġ

	if (pattern[patt_pos] == '*') {				// ������ ���� ��� ���� �������ڰ� ���� name pos���� �ִ��� ��� or ���� name pos���� ���� ����(*���ͽ���)�� �ִ��� ��� -> ����� cache����
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
			if (matchMemoized(0, 0)) result.push_back(filename);					// ��ġ�ϴ� �͵� vector�� ����
		}

		sort(result.begin(), result.end(), compare);								// string �񱳷� ����
		for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
		result.clear();
	}
	return 0;
}


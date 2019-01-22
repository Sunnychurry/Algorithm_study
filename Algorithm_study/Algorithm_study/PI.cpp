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
	string temp = num.substr(start, end - start + 1);													// start���� end-start+1ũ�⸸ŭ string �̾Ƴ�

	if (temp == string(temp.size(), temp[0])) return 1;												// ù���ڷ� �����ѰͰ� string ������ level 1

	bool progressive = true;
	for (int i = 0; i < temp.size() - 1; i++) {
		if (temp[i + 1] - temp[i] != temp[1] - temp[0]) progressive = false;						// ó�� ������ ���� ������ ��ΰ������ Ȯ��(������������)
	}
	if (progressive && abs(temp[1] - temp[0]) == 1) return 2;										// ������ 1�ΰ�� level 2

	bool alternating = true;
	for (int i = 0; i < temp.size(); i++) if (temp[i] != temp[i % 2]) alternating = false;			// ¦���� ¦���� Ȧ���� Ȧ���� ������� Ȯ�� (�����Ƶ���level)

	if (alternating) return 4;																		// �����Ƶ��� level 4
	if (progressive) return 5;																		// ���� 1�ƴ� ���� level 5
	return 10;
}

int recursive(int pos) {
	if (pos == num.size()) return 0;										// base case
	else if (pos > num.size()) return 9999;									// 1�̳� 2���� ���ڰ� �������� ���°�� ó��

	int &ret = cache[pos];
	if (ret != -1) return ret;

	ret = recursive(pos + 3) + levelCheck(pos, pos + 2);					// 3�� ����
	ret = min(ret, recursive(pos + 4) + levelCheck(pos, pos + 3));			// 4�� ����
	ret = min(ret, recursive(pos + 5) + levelCheck(pos, pos + 4));			// 5�� ����

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
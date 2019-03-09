#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, p, l;

const int MAX = 1000000000 + 1;
int length[51];

void precalc() {												// ���뺰 skip�� ���� �̸� ���
	length[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);			// XLength(n) = xLength(n-1) + yLength(n-1) + 2  ���̸� ���
	}
}

char func(string str, int gen, int skip) {							// gen���븸ŭ �������� skip��ŭ ���� ��ġ�� ���� ���
	if (gen == 0) {
		return str[skip];											// ���븸ŭ �� ������ skip��ġ�� �������
	}

	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == 'X' || str[i] == 'Y') {
			if (skip >= length[gen]) skip -= length[gen];					// x,y �϶� skip�� ������̺��� Ŭ��� �׳� skip���� ���� ���ְ� ����ħ
			else if (str[i] == 'X') return func("X+YF", gen - 1, skip);		// x���� �ϳ� ���� ���� ġȯ�� ����ġ���� ����
			else return func("FX-Y", gen - 1, skip);						// y���� �ϳ� ���� ���� ġȯ�� ����ġ���� ����
		}
		else if (skip > 0) --skip;									// x, y �ƴѵ� skip�� ���������� ����ħ
		else return str[i];											// x,y �ƴѵ� skip ������ ����ġ ���
	}
	return '#';
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d", &n, &p, &l);
		precalc();
		for (int i = 0; i < l; i++)	cout << func("FX", n, p - 1 + i);			// l�� ���̸�ŭ ���
		printf("\n");
	}

	return 0;
}

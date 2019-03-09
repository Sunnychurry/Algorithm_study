#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>

using namespace std;

const int M = 1000000000 + 100;
int bino[201][201];

void calcBino() {																	// ���װ�� ���� �Լ�
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);			// nCr = n-1Cr-1 + n-1Cr
		}
	}
}

string generate(int n, int m, int skip) {										// '-' n�� , 'o' m�� �϶� skip��ġ������ ��ȣ ���
	if (n == 0) return string(m, 'o');												// n�� �� ������� m���� 'o' ���

	if (skip <= bino[n + m - 1][n - 1]) return "-" + generate(n - 1, m, skip);
	else return "o" + generate(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		calcBino();
		cout << generate(n, m, k) << endl;
	}

	return 0;
}

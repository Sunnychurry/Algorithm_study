#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;

#define INF 987654321;
int cache[101][11];
int num[101], pSum[101], pSqSum[101];
int n, s;

void precalc() {													// ���� ���� �� �κ��� ��� �Լ�
	sort(num, num + n);												// ���� (����ȭ ��ų�� a<b �̸� ����ȭ �� ���� a<=b �����Ѵ�.)
	pSum[0] = num[0];
	pSqSum[0] = num[0] * num[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + num[i];								// �� �κб����� �ñ׸� n
		pSqSum[i] = pSqSum[i - 1] + num[i] * num[i];				// �� �κб����� �ñ׸� n^2
	}
}

int minError(int lo, int hi) {											// ���� ��� �Լ� 
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));

	int ret = sqSum - 2 * m*sum + m * m*(hi - lo + 1);
	return ret;
}


int quantize(int from, int parts) {						// from : ������ġ  , parts : ����Ƚ��	  ������ġ���� ����Ƚ���� �������� ���� ��ȯ
	if (from == n) return 0;
	if (parts == 0) return INF;

	int& ret = cache[from][parts];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 1; from + i <= n; ++i) {
		ret = min(ret, minError(from, from + i - 1) + quantize(from + i, parts - 1));		//  ���繭�� ��������� + �����κ� �����ϳ� ���̰� ���
	}
	return ret;
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(cache, -1, sizeof(cache));
		memset(pSum, 0, sizeof(pSum));
		memset(pSqSum, 0, sizeof(pSqSum));
		scanf("%d %d", &n, &s);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		precalc();													// �κ��� �̸����
		printf("%d\n", quantize(0, s));								// 0��° ���ں��� s�������� �������� ������ ���
	}
	return 0;
}


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

void precalc() {													// 사전 소팅 및 부분합 계산 함수
	sort(num, num + n);												// 소팅 (양자화 시킬때 a<b 이면 양자화 된 수도 a<=b 여야한다.)
	pSum[0] = num[0];
	pSqSum[0] = num[0] * num[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + num[i];								// 각 부분까지의 시그마 n
		pSqSum[i] = pSqSum[i - 1] + num[i] * num[i];				// 각 부분까지의 시그마 n^2
	}
}

int minError(int lo, int hi) {											// 오류 계산 함수 
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));

	int ret = sqSum - 2 * m*sum + m * m*(hi - lo + 1);
	return ret;
}


int quantize(int from, int parts) {						// from : 시작위치  , parts : 묶음횟수	  시작위치부터 묶음횟수로 묶었을때 오차 반환
	if (from == n) return 0;
	if (parts == 0) return INF;

	int& ret = cache[from][parts];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 1; from + i <= n; ++i) {
		ret = min(ret, minError(from, from + i - 1) + quantize(from + i, parts - 1));		//  현재묶음 오류값계산 + 남은부분 묶음하나 줄이고 재귀
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
		precalc();													// 부분합 미리계산
		printf("%d\n", quantize(0, s));								// 0번째 숫자부터 s묶음으로 묶었을때 오차값 출력
	}
	return 0;
}


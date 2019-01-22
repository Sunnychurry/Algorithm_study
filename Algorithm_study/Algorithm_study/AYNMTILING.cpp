#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MOD 1000000007
int cache[101];

int tiling(int length) {											// tiling 갯수 세는 함수
	if (length <= 1) return 1;

	int& ret = cache[length];
	if (ret != -1) return ret;

	ret = (tiling(length - 1) + tiling(length - 2)) % MOD;			// n-2에서와 n-1 에서의 합 (마지막은 = or |)

	return ret;
}

int asyncCount(int length) {												// 비대칭 tiling 갯수 세는 함수
	int ret = 0;
	if (length % 2) ret = (tiling(length) - tiling(length / 2) + MOD) % MOD;	// 홀수의 경우 절반을 빼주면됨.(중앙만 |인 경우)
	else {																	// %연산한것끼리 -해주기 때문에 음수가 나올 수 있음. MOD를 더해준 후 다시 %연산해준다
		ret = (tiling(length) - tiling(length / 2) + MOD) % MOD;			// 짝수의 경우 절반의 갯수빼주고 (절반절반 따로 대칭인경우)
		ret = (ret - tiling((length / 2) - 1) + MOD) % MOD;						// 절반-1의 갯수도 빼준다.(중앙에 = 가 걸쳐있는 경우)
	}

	return ret;
}

int main() {
	int tc, n;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		printf("%d\n", asyncCount(n));
	}
	return 0;
}
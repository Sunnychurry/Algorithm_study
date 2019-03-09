#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define MOD 10000000
using namespace std;

int cache[101][101];
int n;

int poly(int n, int first) {								// n개로 첫줄에 first개를 사용하고 만들수 있는 폴리오미노의 수
	int& ret = cache[n][first];
	if (ret != -1) return ret;

	if (n == first) return ret = 1;							// 첫줄에 모두 사용하는 경우 1반환 
	ret = 0;

	for (int i = 1; i <= n - first; i++) {						// 첫줄에 사용한 사각형 빼고 밑에 생길수 있는 경우의수 계산 (i는 두번째줄에 놓을 사각형)
		ret += ((i + first - 1) * poly(n - first, i)) % MOD;	// 옮겨가며 붙일수 있는 경우의수 (i+first-1) * 남은 사각형으로 만들 수 있는 경우의수(1~n-first) 까지 계산후 다 더함
		ret %= MOD;
	}

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);

		int res = 0;
		for (int i = 1; i <= n; i++) {					// 첫째줄에 1~n 개 까지 놓을수 있으므로 다 계산후 합구함.
			res += (poly(n, i)) % MOD;
			res %= MOD;
		}
		cout << res << endl;
	}

	return 0;
}
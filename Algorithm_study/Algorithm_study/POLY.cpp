#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define MOD 10000000
using namespace std;

int cache[101][101];
int n;

int poly(int n, int first) {								// n���� ù�ٿ� first���� ����ϰ� ����� �ִ� �������̳��� ��
	int& ret = cache[n][first];
	if (ret != -1) return ret;

	if (n == first) return ret = 1;							// ù�ٿ� ��� ����ϴ� ��� 1��ȯ 
	ret = 0;

	for (int i = 1; i <= n - first; i++) {						// ù�ٿ� ����� �簢�� ���� �ؿ� ����� �ִ� ����Ǽ� ��� (i�� �ι�°�ٿ� ���� �簢��)
		ret += ((i + first - 1) * poly(n - first, i)) % MOD;	// �Űܰ��� ���ϼ� �ִ� ����Ǽ� (i+first-1) * ���� �簢������ ���� �� �ִ� ����Ǽ�(1~n-first) ���� ����� �� ����
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
		for (int i = 1; i <= n; i++) {					// ù°�ٿ� 1~n �� ���� ������ �����Ƿ� �� ����� �ձ���.
			res += (poly(n, i)) % MOD;
			res %= MOD;
		}
		cout << res << endl;
	}

	return 0;
}
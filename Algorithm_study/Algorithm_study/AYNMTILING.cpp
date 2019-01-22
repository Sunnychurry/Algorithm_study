#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MOD 1000000007
int cache[101];

int tiling(int length) {											// tiling ���� ���� �Լ�
	if (length <= 1) return 1;

	int& ret = cache[length];
	if (ret != -1) return ret;

	ret = (tiling(length - 1) + tiling(length - 2)) % MOD;			// n-2������ n-1 ������ �� (�������� = or |)

	return ret;
}

int asyncCount(int length) {												// ���Ī tiling ���� ���� �Լ�
	int ret = 0;
	if (length % 2) ret = (tiling(length) - tiling(length / 2) + MOD) % MOD;	// Ȧ���� ��� ������ ���ָ��.(�߾Ӹ� |�� ���)
	else {																	// %�����Ѱͳ��� -���ֱ� ������ ������ ���� �� ����. MOD�� ������ �� �ٽ� %�������ش�
		ret = (tiling(length) - tiling(length / 2) + MOD) % MOD;			// ¦���� ��� ������ �������ְ� (�������� ���� ��Ī�ΰ��)
		ret = (ret - tiling((length / 2) - 1) + MOD) % MOD;						// ����-1�� ������ ���ش�.(�߾ӿ� = �� �����ִ� ���)
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int num[500];
int cache[500];
int n;

int lis(int start) {										// start���� ������ �ִ������κм��� ���� ��ȯ�ϴ� �Լ�
	int &ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = start + 1; i < n; i++) {					// start�� �����ϴ� ������ �����κм����� ã�� ���س���
		if (num[start] < num[i]) ret = max(ret, lis(i) + 1);		// i��° ���� ���� ���� ��ư��鼭 �ִ밪�� üũ�س���
	}

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int result = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < n; i++) {
			result = max(result, lis(i));				// 0��°���� n��°���� ����� ������ �������� �� Ȯ�� �� �ִ밪 ���
		}

		printf("%d\n", result);
	}
	return 0;
}


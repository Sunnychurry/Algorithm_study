#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int height[20000];
int n;

int func() {
	int ret = 0;
	int width = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {								// ��������� ���ϸ鼭 ����ġ i ���� ���̰� ũ�ų������� ����ũ�� 1����
			if (i + j == n - 1 || height[i] > height[i + j]) break;
			else width++;
		}
		for (int j = 1; j < n; j++) {								// ��������� ��
			if (i - j == 0 || height[i] > height[i - j]) break;
			else width++;
		}
		ret = max(ret, height[i] * width);							// �� ��ġ i ���� �����ؼ�(����ġ�ǳ���) ���� ū ���簢�� ���� ����  (�� ���븦 ����ϸ� �ִ���� ���Ҽ�����)
		width = 1;
	}

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &height[i]);
		printf("%d\n", func());
	}

}

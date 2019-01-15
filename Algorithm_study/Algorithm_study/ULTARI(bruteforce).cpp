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
		for (int j = 1; j < n; j++) {								// 우측막대와 비교하면서 현위치 i 보다 높이가 크거나같으면 가로크기 1증가
			if (i + j == n - 1 || height[i] > height[i + j]) break;
			else width++;
		}
		for (int j = 1; j < n; j++) {								// 좌측막대와 비교
			if (i - j == 0 || height[i] > height[i - j]) break;
			else width++;
		}
		ret = max(ret, height[i] * width);							// 현 위치 i 에서 시작해서(현위치의높이) 가장 큰 직사각형 넓이 저장  (각 막대를 모두하면 최대넓이 구할수있음)
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

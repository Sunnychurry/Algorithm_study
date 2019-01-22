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

int lis(int start) {										// start부터 수열의 최대증가부분수열 길이 반환하는 함수
	int &ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = start + 1; i < n; i++) {					// start로 시작하는 수열중 증가부분수열을 찾아 더해나감
		if (num[start] < num[i]) ret = max(ret, lis(i) + 1);		// i번째 수를 다음 수로 잡아가면서 최대값을 체크해나감
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
			result = max(result, lis(i));				// 0번째부터 n번째까지 어떤수로 수열을 시작할지 다 확인 후 최대값 출력
		}

		printf("%d\n", result);
	}
	return 0;
}


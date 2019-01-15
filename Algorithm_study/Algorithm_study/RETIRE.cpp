#include <stdio.h>
#include <stdlib.h>

using namespace std;

int term[16];
int price[16];
int checkday[16];
int sum = 0;
int maxsum = 0;

int dfs(int day, int now) {
	int fail = 0;
	int ret = 0;

	if (now == day + 1) return sum;				// base case. 퇴사날까지 도달한 경우 return

	for (int i = now; i <= day; i++) {			// 마지막 상담 끝난 날짜에서부터 퇴사날까지 확인

		if (!checkday[i]) {
			for (int j = 0; j < term[i]; j++) {					// 상담 기간이 퇴사날 이후가 되는 경우를 찾아냄
				if (i + j > day || checkday[i + j]) fail = 1;
			}
			if (fail) fail = 0;
			else {												// 퇴사전 상담이 가능한 경우
				for (int j = 0; j < term[i]; j++) {
					checkday[i + j] = 1;
				}
				sum += price[i];
				ret = dfs(day, i + 1);							// 비용 더해주고 다음날 부터 find
				if (ret > maxsum) maxsum = ret;					// 모두 끝냈을때 max값 비교
				sum -= price[i];
				for (int j = 0; j < term[i]; j++) {
					checkday[i + j] = 0;
				}

			}
		}
	}
	return sum;
}


int main() {
	int day;
	scanf("%d", &day);
	for (int i = 1; i <= day; i++) {
		scanf("%d %d", &term[i], &price[i]);
	}
	dfs(day, 1);

	printf("%d", maxsum);
}

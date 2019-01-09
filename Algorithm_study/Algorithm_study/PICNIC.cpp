#include <stdio.h>
#include <stdlib.h>

using namespace std;

int pair[10][10] = { 0, };
int pickcheck[10] = { 0, };
int cnt = 0;

int dfs(int num, int start) {
	int fail = 0;
	int ret = 0;

	for (int i = 0; i < num; i++) {							// 모두 짝이 되었는지 확인
		if (!pickcheck[i]) fail = 1;
	}

	if (!fail) {											// 모두 짜여지면 카운트 후 탐색 종료
		cnt++;
		return 1;
	}

	for (int i = start; i < num; i++) {
		if (pickcheck[i]) continue;						// 이미 짝이 있으면 패스
		for (int j = i; j < num; j++) {					// i 이후부터 찾아야 짝끼리 순서 바껴서 겹치는 중복 제거 가능
			if (pickcheck[j]) continue;
			if (pair[i][j]) {							// 짝이 없는데 친구인 경우
				pickcheck[i] = pickcheck[j] = 1;		// 짝으로 선택
				dfs(num, i + 1);							// 다음 순번부터 다시 탐색 ( 다음 순번 부터 찾아야 같은 짝의 경우인데 순서 바껴서 생기는 중복 제거 가능)
				pickcheck[i] = pickcheck[j] = 0;		// 탐색이 완료되면 이전 짝 취소 후 다시 탐색
			}
		}
	}

	return 0;
}

int main() {
	int n, m, tc;
	int f1, f2;
	int ret = 0;

	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &f1, &f2);
			pair[f1][f2] = pair[f2][f1] = 1;
		}

		dfs(n, 0);
		printf("%d\n", cnt);

		cnt = 0;												// 다음 test case를 위한 초기화
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) pair[i][j] = 0;
			pickcheck[i] = 0;
		}
	}

}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>

using namespace std;

int n, w;
string name[101];
int siz[101], want[101];
int cache[101][1001];

queue<string> q;

int dp(int start, int carrierW) {								// start부터 부피가 carrierW 남았을때 n까지 최대 절박도 반환
	if (start == n) return 0;									// base case : 끝까지 도달
	int& ret = cache[start][carrierW];
	if (ret != -1) return ret;
	ret = 0;

	ret = dp(start + 1, carrierW);								// start번째 물건 캐리어에 안담음
	if (carrierW - siz[start] >= 0) ret = max(ret, want[start] + dp(start + 1, carrierW - siz[start]));		// start번째 물건 캐리어에 담음(담을수 있는 무게일경우)
																// 담거나 안담았을때 둘중 큰 값 반환
	return ret;
}

void reconstruct(int start, int carrierW) {						// max인 경우의 문자열 queue에 담는 함수
	if (start == n) return;
	if (dp(start, carrierW) == dp(start + 1, carrierW)) {		// 동일무게에서 start번째의 최대절박도와 start+1번째의 최대절박도가 같은경우 start번째를 담는건 max의 경우가 아님.
		reconstruct(start + 1, carrierW);							// 다음 물건으로 이동
	}
	else {
		q.push(name[start]);									// 다른경우 max의 경우이므로 queue에 저장
		reconstruct(start + 1, carrierW - siz[start]);			// 무게 줄이고 다음 측정(dp함수와 똑같이 동작)
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(cache, -1, sizeof(cache));
		memset(siz, -1, sizeof(siz));
		memset(want, -1, sizeof(want));
		scanf("%d %d", &n, &w);

		for (int i = 0; i < n; i++) {
			cin >> name[i];
			scanf("%d %d", &siz[i], &want[i]);
		}

		printf("%d ", dp(0, w));
		reconstruct(0, w);
		printf("%d\n", q.size());

		while (!q.empty()) {
			string temp = q.front();
			q.pop();
			cout << temp << endl;
		}

	}

	return 0;
}


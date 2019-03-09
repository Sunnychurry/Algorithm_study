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

int dp(int start, int carrierW) {								// start���� ���ǰ� carrierW �������� n���� �ִ� ���ڵ� ��ȯ
	if (start == n) return 0;									// base case : ������ ����
	int& ret = cache[start][carrierW];
	if (ret != -1) return ret;
	ret = 0;

	ret = dp(start + 1, carrierW);								// start��° ���� ĳ��� �ȴ���
	if (carrierW - siz[start] >= 0) ret = max(ret, want[start] + dp(start + 1, carrierW - siz[start]));		// start��° ���� ĳ��� ����(������ �ִ� �����ϰ��)
																// ��ų� �ȴ������ ���� ū �� ��ȯ
	return ret;
}

void reconstruct(int start, int carrierW) {						// max�� ����� ���ڿ� queue�� ��� �Լ�
	if (start == n) return;
	if (dp(start, carrierW) == dp(start + 1, carrierW)) {		// ���Ϲ��Կ��� start��°�� �ִ����ڵ��� start+1��°�� �ִ����ڵ��� ������� start��°�� ��°� max�� ��찡 �ƴ�.
		reconstruct(start + 1, carrierW);							// ���� �������� �̵�
	}
	else {
		q.push(name[start]);									// �ٸ���� max�� ����̹Ƿ� queue�� ����
		reconstruct(start + 1, carrierW - siz[start]);			// ���� ���̰� ���� ����(dp�Լ��� �Ȱ��� ����)
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


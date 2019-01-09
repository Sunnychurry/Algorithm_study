#include <stdio.h>
#include <stdlib.h>

using namespace std;

int pair[10][10] = { 0, };
int pickcheck[10] = { 0, };
int cnt = 0;

int dfs(int num, int start) {
	int fail = 0;
	int ret = 0;

	for (int i = 0; i < num; i++) {							// ��� ¦�� �Ǿ����� Ȯ��
		if (!pickcheck[i]) fail = 1;
	}

	if (!fail) {											// ��� ¥������ ī��Ʈ �� Ž�� ����
		cnt++;
		return 1;
	}

	for (int i = start; i < num; i++) {
		if (pickcheck[i]) continue;						// �̹� ¦�� ������ �н�
		for (int j = i; j < num; j++) {					// i ���ĺ��� ã�ƾ� ¦���� ���� �ٲ��� ��ġ�� �ߺ� ���� ����
			if (pickcheck[j]) continue;
			if (pair[i][j]) {							// ¦�� ���µ� ģ���� ���
				pickcheck[i] = pickcheck[j] = 1;		// ¦���� ����
				dfs(num, i + 1);							// ���� �������� �ٽ� Ž�� ( ���� ���� ���� ã�ƾ� ���� ¦�� ����ε� ���� �ٲ��� ����� �ߺ� ���� ����)
				pickcheck[i] = pickcheck[j] = 0;		// Ž���� �Ϸ�Ǹ� ���� ¦ ��� �� �ٽ� Ž��
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

		cnt = 0;												// ���� test case�� ���� �ʱ�ȭ
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) pair[i][j] = 0;
			pickcheck[i] = 0;
		}
	}

}

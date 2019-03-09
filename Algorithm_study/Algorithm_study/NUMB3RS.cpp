#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int road[51][51];
int n;
double cache[101][51][51];

double dp(int day, int start, int dest) {							// day �Ŀ� start���� dest���� ������ Ȯ��
	int cnt = 0;
	if (day == 0) {													// base case ��¥ ���������� Ȯ�� 1 or 0
		if (start == dest) return 1;
		else return 0;
	}

	double& ret = cache[day][start][dest];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < n; i++) {									// ���� start���� �̵��� �� �ִ� �� count
		if (road[start][i]) cnt++;
	}

	for (int i = 0; i < n; i++) {
		if (road[start][i]) ret += (dp(day - 1, i, dest) / (double)cnt);		// ��ΰ� �ִ� ������ �̵��Ͽ� ��� (��¥ �Ϸ� ����) -> ��ü �̵��� �� ��� �����༭ Ȯ���� ���Ѵ�
	}																// �� ��θ����� Ȯ���� �����ش�.(������ġ���� �������� �� �� �ִ� Ȯ�� = �� ��ο��� �������� Ȯ���� ��)

	return ret;														// Ȯ�� ��ȯ
}



int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int d, p, t;
		int town[51];
		scanf("%d %d %d", &n, &d, &p);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &road[i][j]);
			}
		}
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			scanf("%d", &town[i]);
		}

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 51; j++) {
				for (int k = 0; k < 51; k++) cache[i][j][k] = -1;
			}
		}

		for (int i = 0; i < t; i++) {
			printf("%.8lf ", dp(d, p, town[i]));
		}
		printf("\n");
	}

	return 0;
}


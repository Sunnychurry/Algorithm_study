#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int road[51][51];
int n;
double cache[101][51][51];

double dp(int day, int start, int dest) {							// day 후에 start에서 dest까지 도달할 확률
	int cnt = 0;
	if (day == 0) {													// base case 날짜 도달했을때 확률 1 or 0
		if (start == dest) return 1;
		else return 0;
	}

	double& ret = cache[day][start][dest];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < n; i++) {									// 현재 start에서 이동할 수 있는 길 count
		if (road[start][i]) cnt++;
	}

	for (int i = 0; i < n; i++) {
		if (road[start][i]) ret += (dp(day - 1, i, dest) / (double)cnt);		// 경로가 있는 곳으로 이동하여 재귀 (날짜 하루 감소) -> 전체 이동할 수 길로 나눠줘서 확률을 구한다
	}																// 각 경로마다의 확률은 더해준다.(현재위치에서 목적지로 갈 수 있는 확률 = 각 경로에서 목적지갈 확률의 합)

	return ret;														// 확률 반환
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


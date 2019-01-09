#include <stdio.h>
#include <stdlib.h>

using namespace std;

int time[16] = { 0, };
int sw[10][6] = { {0,1,2,-1,-1}, {3,7,9,11,-1}, {4,10,14,15,-1}, {0,4,5,6,7,-1}, {6,7,8,10,12,-1}, {0,2,14,15,-1,-1}, {3,14,15,-1,-1,-1}, {4,5,7,14,15,-1}, {1,2,3,4,5,-1}, {3,4,5,9,13,-1} };
int cnt = 0;

void swPress(int num) {											// ����ġ ������ �Լ�
	for (int i = 0; sw[num][i] != -1; i++) {					// ����ġ�� �ش��ϴ� �ð� Time ����
		time[sw[num][i]] = (time[sw[num][i]] + 3) % 12;
	}
	cnt++;
}

int isTimezero(void) {							// Time SYNC�� ���質 Ȯ��
	for (int i = 0; i < 16; i++) {
		if (time[i] != 0) return 0;
	}
	return 1;
}

int swCycle(int n) {							//  ��� ����Ǽ� ����Ž�� (���)
	int ret = 0;
	if (n == 10) return 0;

	for (int i = 0; i < 4; i++) {			// 4���� ����ġ�� ���� SYNC�� �³� Ȯ��
		ret = swCycle(n + 1);				// ��ͷ� �ϳ��� �����ϸ鼭 ��� ����� ����ġ �ٴ���
		if (ret) return 1;
		swPress(n);
		if (isTimezero()) return 1;
	}
	cnt -= 4;								// 4�� ������ SYNC�� �ȸ����� count �ٽ� ������κ���

	return 0;
}


int main() {
	int tc, ans = 0;

	scanf("%d", &tc);
	for (int k = 0; k < tc; k++) {

		for (int i = 0; i < 16; i++) {
			scanf("%d", &time[i]);
			time[i] = time[i] % 12;
		}

		if (isTimezero()) printf("%d", 0);
		ans = swCycle(0);
		if (ans) {
			printf("%d\n", cnt);
			cnt = 0;
		}
		else printf("%d\n", -1);

	}
}
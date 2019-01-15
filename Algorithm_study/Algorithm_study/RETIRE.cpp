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

	if (now == day + 1) return sum;				// base case. ��糯���� ������ ��� return

	for (int i = now; i <= day; i++) {			// ������ ��� ���� ��¥�������� ��糯���� Ȯ��

		if (!checkday[i]) {
			for (int j = 0; j < term[i]; j++) {					// ��� �Ⱓ�� ��糯 ���İ� �Ǵ� ��츦 ã�Ƴ�
				if (i + j > day || checkday[i + j]) fail = 1;
			}
			if (fail) fail = 0;
			else {												// ����� ����� ������ ���
				for (int j = 0; j < term[i]; j++) {
					checkday[i + j] = 1;
				}
				sum += price[i];
				ret = dfs(day, i + 1);							// ��� �����ְ� ������ ���� find
				if (ret > maxsum) maxsum = ret;					// ��� �������� max�� ��
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

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		string input_idol, input_fan;
		unsigned long long idol = 0, fan = 0;			// input ũ�� ������. GG..
		int cnt = 0;

		cin >> input_idol;
		cin >> input_fan;

		int idol_length = input_idol.length();
		int fan_length = input_fan.length();

		for (int i = 0; i < idol_length; i++) {			// 'M'�� 'F'�� '1'�� '0'���� ġȯ
			if (input_idol[i] == 'M') {
				idol = idol << 1;
				idol += 1;
			}
			else {
				idol = idol << 1;
			}

		}

		for (int i = 0; i < fan_length; i++) {
			if (input_fan[i] == 'M') {
				fan = fan << 1;
				fan += 1;
			}

			else {
				fan = fan << 1;
			}
		}

		if (idol_length > fan_length) return 0;
		else {
			for (int i = 0; i < fan_length - idol_length + 1; i++) {		// for�� �ѹ����� ��Ʈ������ ���� 'M' 'M' ã��.
				if (!(idol & fan)) {
					cnt++;
				}
				idol = idol << 1;
			}
		}

		cout << cnt << endl;
	}

}

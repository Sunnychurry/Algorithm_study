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
		string idol, fan;

		int cnt = 0;
		int flag = 0;

		cin >> idol;
		cin >> fan;

		int idol_length = idol.length();
		int fan_length = fan.length();

		if (idol_length > fan_length) return 0;
		else {
			for (int i = 0; i < fan_length - idol_length + 1; i++) {				// 배열 다 돌면서 완전탐색 - 시간초과 O(100000^2)
				for (int j = 0; j < idol_length; j++) {
					if (idol[j] == 'M' && fan[i + j] == 'M') {
						flag = 1;
						break;
					}
				}
				if (flag) flag = 0;
				else cnt++;
			}
		}

		cout << cnt << endl;
	}

}

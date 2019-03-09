#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, p, l;

const int MAX = 1000000000 + 1;
int length[51];

void precalc() {												// 세대별 skip할 길이 미리 계산
	length[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);			// XLength(n) = xLength(n-1) + yLength(n-1) + 2  길이만 계산
	}
}

char func(string str, int gen, int skip) {							// gen세대만큼 남았을때 skip만큼 뒤의 위치의 문자 출력
	if (gen == 0) {
		return str[skip];											// 세대만큼 다 들어갔을때 skip위치의 문자출력
	}

	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == 'X' || str[i] == 'Y') {
			if (skip >= length[gen]) skip -= length[gen];					// x,y 일때 skip이 세대길이보다 클경우 그냥 skip에서 길이 빼주고 지나침
			else if (str[i] == 'X') return func("X+YF", gen - 1, skip);		// x세대 하나 들어가고 문자 치환후 그위치에서 시작
			else return func("FX-Y", gen - 1, skip);						// y세대 하나 들어가고 문자 치환후 그위치에서 시작
		}
		else if (skip > 0) --skip;									// x, y 아닌데 skip이 남아있으면 지나침
		else return str[i];											// x,y 아닌데 skip 없으면 그위치 출력
	}
	return '#';
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d", &n, &p, &l);
		precalc();
		for (int i = 0; i < l; i++)	cout << func("FX", n, p - 1 + i);			// l번 길이만큼 출력
		printf("\n");
	}

	return 0;
}

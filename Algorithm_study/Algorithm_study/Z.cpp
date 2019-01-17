#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, r, c;

int func(int start_r, int end_r, int start_c, int end_c) {
	int ret;
	int quad = ((end_r - start_r + 1)*(end_c - start_c + 1)) / 4;	// 현 사각형에서 한 사분면의 방문갯수 (넓이/4)

	if (start_r == end_r && start_c == end_c) return 0;				// base case 원하는 r,c도달

	if (r <= start_r + ((end_r - start_r) / 2)) {
		if (c <= start_c + ((end_c - start_c) / 2)) {										// 1사분면
			ret = func(start_r, start_r + ((end_r - start_r) / 2), start_c, start_c + ((end_c - start_c) / 2));
		}
		else {																	// 2사분면
			ret = func(start_r, start_r + ((end_r - start_r) / 2), end_c - ((end_c - start_c) / 2), end_c);
			ret += quad;				// 1사분면 방문갯수+
		}
	}

	else {
		if (c <= start_c + ((end_c - start_c) / 2)) {								// 3사분면
			ret = func(end_r - ((end_r - start_r) / 2), end_r, start_c, start_c + ((end_c - start_c) / 2));
			ret += (quad * 2);			// 1,2사분면 방문갯수+
		}
		else {																	// 4사분면
			ret = func(end_r - ((end_r - start_r) / 2), end_r, end_c - ((end_c - start_c) / 2), end_c);
			ret += (quad * 3);			// 1,2,3사분면 방문갯수+
		}
	}

	return ret;
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	printf("%d\n", func(0, pow(2, n) - 1, 0, pow(2, n) - 1));
}

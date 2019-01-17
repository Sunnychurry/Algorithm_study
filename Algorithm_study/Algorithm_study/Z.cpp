#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, r, c;

int func(int start_r, int end_r, int start_c, int end_c) {
	int ret;
	int quad = ((end_r - start_r + 1)*(end_c - start_c + 1)) / 4;	// �� �簢������ �� ��и��� �湮���� (����/4)

	if (start_r == end_r && start_c == end_c) return 0;				// base case ���ϴ� r,c����

	if (r <= start_r + ((end_r - start_r) / 2)) {
		if (c <= start_c + ((end_c - start_c) / 2)) {										// 1��и�
			ret = func(start_r, start_r + ((end_r - start_r) / 2), start_c, start_c + ((end_c - start_c) / 2));
		}
		else {																	// 2��и�
			ret = func(start_r, start_r + ((end_r - start_r) / 2), end_c - ((end_c - start_c) / 2), end_c);
			ret += quad;				// 1��и� �湮����+
		}
	}

	else {
		if (c <= start_c + ((end_c - start_c) / 2)) {								// 3��и�
			ret = func(end_r - ((end_r - start_r) / 2), end_r, start_c, start_c + ((end_c - start_c) / 2));
			ret += (quad * 2);			// 1,2��и� �湮����+
		}
		else {																	// 4��и�
			ret = func(end_r - ((end_r - start_r) / 2), end_r, end_c - ((end_c - start_c) / 2), end_c);
			ret += (quad * 3);			// 1,2,3��и� �湮����+
		}
	}

	return ret;
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	printf("%d\n", func(0, pow(2, n) - 1, 0, pow(2, n) - 1));
}

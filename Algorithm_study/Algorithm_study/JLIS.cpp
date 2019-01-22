#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int A[100];
int B[100];
int cache[101][101];
int na, nb;

//	int cnt = 0;

const long long NEGINF = numeric_limits<long long>::min();					// -1 부터 시작하기위해 Negative Infinite 선언

int jlis(int indexA, int indexB) {
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);										// 최대값 뽑아냄

	for (int nextA = indexA + 1; nextA < na; ++nextA) {						// 현재 수열에서 최대값 보다 큰값을 이어 만듬. 완전탐색이므로 가장 긴 경우가 카운트되게 되어있음.
		if (maxElement < A[nextA]) {
			//printf("%d %d in A\n", nextA, indexB);
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < nb; ++nextB) {
		if (maxElement < B[nextB]) {
			//printf("%d %d in B\n", indexA, nextB);
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}

	return ret;
}



//int jlis(int indexA, int indexB) {										// 겹치는 걸 빼는 방법 (시간초과)
//	int &ret = cache[indexA+1][indexB+1];
//	if (ret != -1) return ret;
//
//	if (indexA!=-1 && indexB!=-1 && A[indexA] == B[indexB]) cnt++;
//	ret = 2;
//
//	long long a = (indexA == -1 ? NEGINF : A[indexA]);
//	long long b = (indexB == -1 ? NEGINF : B[indexB]);
//
//	for (int i = indexA; i < na; i++) {	
//		if (i + 1 < na && a < A[i + 1]) ret = max(ret, jlis(i + 1, indexB) + 1);
//		for (int j = indexB; j < nb; j++) {
//			if (j + 1 < nb && b < B[j + 1]) ret = max(ret, jlis(indexA, j + 1) + 1);
//		}
//		ret -= cnt;
//		cnt = 0;
//	}
//
//	return ret;
//}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int result = 0;
		scanf("%d %d", &na, &nb);
		for (int i = 0; i < na; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < nb; i++) {
			scanf("%d", &B[i]);
		}
		memset(cache, -1, sizeof(cache));

		result = jlis(-1, -1) - 2;					// -1, -1 가 포함되므로 2개 빼야함.

		printf("%d\n", result);
	}
	return 0;
}
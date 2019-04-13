#include <stdio.h>
int N, max;
int a[21];

void DFS(int no, int lastA, int lastB, int sum) {
	if (no >= N) {
		if (sum> max) {
			max = sum;
		}
		return;
	}
	if (lastA> a[no]) {
		DFS(no + 1, a[no], lastB, sum + a[no]);
	}
	if (lastB< a[no]) {
		DFS(no + 1, lastA, a[no], sum + a[no]);
	}
	DFS(no + 1, lastA, lastB, sum);
}
int main(void) {
	int ti, T;
	scanf("%d", &T);
	for (ti = 0; ti< T; ti++) {
		int i;
		scanf("%d", &N);
		for (i = 0; i< N; i++) scanf("%d", &a[i]);
		max = 0;
		DFS(0, 1000, 0, 0);
		printf("%d\n", max);
	}
	return 0;
}
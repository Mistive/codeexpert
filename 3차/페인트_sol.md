
###### 내가 짠 코드보다 2배 빠름
###### 4중for문에서 연산량을 줄일 수 있었는데 그러지 못했음 

<pre><code>
#include <stdio.h>
int N, R;
int map[30][30];
int chk[30][30];
int check(int r, int c, int k) {
	int i, j, step=0, cnt=0;
	int sr, sc;
	for (i = r - R; i <= r + R; i++) {
		for (j = c - step; j <= c + step; j++) {
			if (i < 0 || i >= N || j < 0 || j >= N) continue;
			if (map[i][j] == 0 && chk[i][j]==0) cnt++;
			chk[i][j] +=k;
		}
		step += (i >= r)? -1 : 1;
	}
	return cnt;
}

void init(void) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chk[i][j] = 0;
		}
	}
}
int main(void) {
	int i, j, k, l;
	scanf("%d", &N);
	scanf("%d", &R);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	int area1 = 0, area2 = 0, max=0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			init();
			area1 = check(i, j, 1);
			for (k = i; k < N; k++) {
				for (l = 0; l < N; l++) {
					if (i == k && j >= l) continue;
					area2 = check(k, l, 0);
					if (area1 + area2 > max) {
						max = area1 + area2;
						
					}
				}
			}
			
		}
	}
	printf("%d\n", max);
	return 0;
}
</code></pre>

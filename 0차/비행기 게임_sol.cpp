#include<stdio.h> 
char map[15][10];
int T, R = 13, C = 5, max;
int dr[] = { -1, -1, -1 }, dc[] = { -1, 0, 1 };
void DFS(int r, int c, int sum, int bomb, int safe) {
	if (r == 0) {
		if (sum> max)max = sum;
		return;
	}
	int i, score = 0, nr, nc;

	for (i = 0; i< 3; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nc< 0 || nc >= C) continue;
		if (map[nr][nc] == '0') score = 0;
		else if (map[nr][nc] == '*') score = 10;
		else if (map[nr][nc] == 'X') {
			if (safe >0) score = 0;
			else score = -7;
		}
		if (map[nr][nc] == 'X' && bomb == 0) DFS(nr, nc, sum, 1, 4);
		DFS(nr, nc, sum + score, bomb, bomb ? safe - 1 : safe);
	}
}
int main(void) {
	int ti;
	scanf("%d", &T);
	for (ti = 0; ti< T; ti++) {
		int i, j;
		for (i = 1; i <= R; i++) {
			scanf("%s", map[i]);
		}
		max = -7 * 20;
		DFS(13, 2, 0, 0, 0);
		printf("%d\n", max);
	}
	return 0;
}

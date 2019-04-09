#include <stdio.h>

int TC;
int N = 13, M = 5;


char map[13][5];
//시작위치 x = 2, y = 12;


int maxscore = -0x7fffffff;

void usebomb2(int x, int y, int *idx, int qx[], int qy[]) {
	for (int i = 0; i < 5; i++) {
		y--;
		if (y < 0) return;
		for (int x = 0; x < 5; x++) {
			if (map[y][x] == 'X') {
				qx[*idx] = x;
				qy[*idx] = y;
				(*idx)++;
				map[y][x] = '0';
			}
		}
	}
}


void returnbomb(int idx, int qx[], int qy[]) {
	for (int i = 0; i < idx; i++) {
		int x = qx[i];
		int y = qy[i];
		map[y][x] = 'X';
	}
}

void print() {
	printf("===========================\n");
	printf("ms: %d\n", maxscore);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
}

void dfs(int x, int y, int bomb, int score, int vx[]) {
	int idx = 0, qx[30], qy[30];

	if (x >= M || y >= N || x < 0 || y < 0) return;
	vx[y] = x;
	//점수 계산
	if (map[y][x] == 'X') {
		score -= 7;
	}
	else if (map[y][x] == '*') {
		score += 10;
	}

	if (y == 0) {
		//결과 확인
		if (score > maxscore) {
			maxscore = score;
			/*	print();
			for (int i = 12; i >=0; i--) {
			printf("%d ", vx[i]);
			}*/
		}
		return;
	}

	//이동

	if (bomb == 1) {
		usebomb2(x, y, &idx, qx, qy);
		dfs(x + 1, y - 1, 0, score, vx);
		dfs(x - 1, y - 1, 0, score, vx);
		dfs(x, y - 1, 0, score, vx);
		returnbomb(idx, qx, qy);
	}
	dfs(x + 1, y - 1, bomb, score, vx);
	dfs(x - 1, y - 1, bomb, score, vx);
	dfs(x, y - 1, bomb, score, vx);
}


int main() {
	scanf("%d", &TC);

	for (int T = 1; T <= TC; T++) {

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				char ch;
				scanf("%c", &ch);
				if (ch == '\n')
					scanf("%c", &ch);
				map[y][x] = ch;
			}


		}
		int vx[13];
		dfs(2, 12, 1, 0, vx);
		//int idx = 0, qx[6], qy[6];
		/*	usebomb(2, 12, &idx, qx, qy);
		print();
		returnbomb(idx, qx, qy);
		print();*/


		printf("%d\n", maxscore);
		maxscore = 0;
	}

	return 0;
}
#include <stdio.h>
#define MAX (100+10)

int N;
int map[10][10];
int chk[10][10];
int tree_num;

int fire_x[100];
int fire_y[100];
int fp = 0;

int tree_x[100];
int tree_y[100];
int tp = 0;


//없어진 나무 개수(화재 or 제거), 제거한 나무 개수(max 2), 깊이

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


typedef struct {
	int x, y;
}Queue;

Queue queue[MAX];
int rp, wp;
int enqueue(int x, int y) {
	if (wp == MAX) return 0;
	queue[wp].x = x;
	queue[wp].y = y;
	wp++;
	return 1;
}
int dequeue(Queue *t) {
	if (wp == rp) return 0;
	*t = queue[rp];
	rp++;
	return 1;
}


void init() {
	//초기화 단계
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			chk[y][x] = 0;
		}
	}
	wp = rp = 0;
	for (int i = 0; i < fp; i++) {
		enqueue(fire_x[i], fire_y[i]);
		chk[fire_y[i]][fire_x[i]] = 1;
	}
}

int bfs() {
	Queue t;

	while (dequeue(&t)) {
		//printf("%d %d\n", t.x, t.y);
		for (int i = 0; i < 4; i++) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (chk[ny][nx] == 1) continue;

			if (map[ny][nx] == 1) {
				enqueue(nx, ny);
				chk[ny][nx] = 1;
			}
		}
	}

	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (chk[y][x] == 0 && map[y][x] == 1) cnt++;
		}
	}
	return cnt;
}

int max = 0;

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", chk[y][x]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);

			if (map[y][x] == 1) {
				tree_x[tp] = x;
				tree_y[tp] = y;
				tp++;
			}
			if (map[y][x] == 2) {
				fire_x[fp] = x;
				fire_y[fp] = y;
				fp++;
			}
		}
	}
	
	////나무를 하나도 제거하지 않은 경우
	init();
	int ret = bfs();
	if (max < ret) max = ret;

	//나무를 하나 제거한 경우
	for (int i = 0; i < tp; i++) {
		init();
		chk[tree_y[i]][tree_x[i]] = 1;
		int ret = bfs();
		if (max < ret) max = ret;
	}

	//나무를 두 개 제거한 경우
	for (int i = 0; i < tp-1; i++) {
		for (int j = i+1; j < tp; j++) {
			init();
			chk[tree_y[i]][tree_x[i]] = 1;
			chk[tree_y[j]][tree_x[j]] = 1;
			int ret = bfs();
			if (max < ret) max = ret;
		}
	}
	printf("%d", max);
}
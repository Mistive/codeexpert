////time 30m running time : 361
//#include <stdio.h>
//#define DIFF(x,y) ((x>y)? ((x)-(y)): ((y)-(x)))
//
//
//
//int N;
//int R;
//int map[25][25];
//
//
//
//int check(int sx, int sy, int sxx, int syy) {
//	int count = 0;
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			if (map[y][x] == 1) continue;
//			if (DIFF(x, sx) + DIFF(y, sy) <= R || DIFF(x, sxx) + DIFF(y, syy) <= R) count++;
//		}
//	}
//
//	return count;
//}
//
//int max = 0;
//int main() {
//	scanf("%d", &N);
//	scanf("%d", &R);
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			scanf("%d", &map[y][x]);
//		}
//	}
//
//	/*
//	MAP의 최대 크기는 25*25
//	따라서 최대 순환 횟수는 25*24 = 600
//	*/
//
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			int sx = x + 1;
//			for (int yy = y; yy < N; yy++) {
//				for (int xx = sx; xx < N; xx++) {
//					int cnt = check(x, y, xx, yy);
//					if (max < cnt) max = cnt;
//				}
//				sx = 0;
//			}
//		}
//	}
//
//	printf("%d\n", max);
//
//	return 0;
//}
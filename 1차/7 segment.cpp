#include <stdio.h>



int segment[10][7] = {
	{ 1,1,1,1,1,1,0 },
	{ 0,0,1,1,0,0,0 },
	{ 0,1,1,0,1,1,1 },
	{ 0,1,1,1,1,0,1 },
	{ 1,0,1,1,0,0,1 },
	{ 1,1,0,1,1,0,1 },
	{ 1,1,0,1,1,1,1 },
	{ 0,1,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,1 },
};
typedef struct {
	int idx;
	int input[7];
	int num[10];
	int sp=0;

	void check_segment() {
		for (int i = 0; i <= 9; i++) {
			int k;
			for (k = 0; k < 7; k++) {
				if (input[k] == 1 && segment[i][k] == 0) break;
			}
			if (k == 7) {
				num[sp++] = i;
			}
		}
	}

	void print_num_cand() {
			printf("%d: ", idx);
			for (int k = 0; k < sp; k++) {
				printf("%d ", num[k]);
			}
			printf("\n");
	}
}SEGMENT;

SEGMENT seg[12];

typedef struct {
	int A[1000] = {0};

	void dfs(int num, int count) {

		if (count == 3) {
			A[num]++;
			return;
		}

		for (int p = 0; p < seg[count].sp; p++) {
			int tnum = seg[count].num[p];
			for (int i = 0; i < (2 - count); i++) {
				tnum = tnum * 10;
			}
			dfs(num + tnum, count + 1);
		}

	}

	void get_usable_num() {
		dfs(0, 0);
	}

	void print() {
		for (int i = 0; i < 1000; i++) {
			if (A[i] != 0) printf("%d ", i);
		}
		printf("\n");
	}
}ANUM;
typedef struct {
	int B[1000] = { 0 };

	void dfs(int num, int count) {

		if (count == 6) {
			B[num]++;
			return;
		}

		for (int p = 0; p < seg[count].sp; p++) {
			int tnum = seg[count].num[p];
			for (int i = 0; i < (5 - count); i++) {
				tnum = tnum * 10;
			}
			dfs(num + tnum, count + 1);
		}

	}

	void get_usable_num() {
		dfs(0, 3);
	}

	

	void print() {
		for (int i = 0; i < 1000; i++) {
			if (B[i] != 0) printf("%d ", i);
		}
		printf("\n");
	}
}BNUM;

ANUM anumber;
BNUM bnumber;

int check(int num) {
	for (int i = 0; i < 1000; i++) {
		//만들 수 없는 숫자일 경우 pass
		if (anumber.A[i] == 0) continue;
	
		
		if (anumber.A[i] == 1) {
			if (i * 999 < num) continue;
			int j = num / i;
			if (num % i == 0 && bnumber.B[j] != 0) {
				//printf("%d %d\n", i, j);
				return 1;
			}
		}
	}
	return 0;
}

int ans = -1;
void dfs(int num, int count) {
	if (ans != -1) return;

	if (count == 12) {
		if (check(num)) {
			ans = num;
		}
			
		return;
	}

	for (int p = 0; p < seg[count].sp; p++) {
		int tnum = seg[count].num[p];
		for (int i = 0; i < (11 - count); i++) {
			tnum = tnum * 10;
		}
		dfs(num + tnum, count + 1);
	}
}

int main() {
	for (int y = 0; y < 12; y++) {
		seg[y].idx = y;
 		for (int x = 0; x < 7; x++) {
			scanf("%1d", &seg[y].input[x]);
		}
		seg[y].check_segment();
		//seg[y].print_num_cand();
	}

	anumber.get_usable_num();
	bnumber.get_usable_num();
	//anumber.print();
	//bnumber.print();
	dfs(0, 6);

	printf("%d\n", ans);
}
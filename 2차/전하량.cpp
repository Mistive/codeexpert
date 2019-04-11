//1h 20min
#include <stdio.h>

int TC;
int atomNum, holeNum;	//max= 7, 7

enum STATE {EMPTY, FULL};

typedef struct {
	int idx;
	int v;
	//int force;
	int used;		//전하 사용 여부(0: usable, 1: used)
}ATOM;
ATOM atom[7];

typedef struct {
	int d;
	int state;
	ATOM atom;

}HOLE;
HOLE hole[7];

void holesort() {
	for (int i = 0; i < holeNum - 1; i++) {
		for (int j = i + 1; j < holeNum; j++) {
			if (hole[i].d > hole[j].d) {
				HOLE tmp = hole[i];
				hole[i] = hole[j];
				hole[j] = tmp;
			}
		}
	}
}

int saturationCheck() {
	int aforce[7] = { 0 };
	//force calcul
	for (int i = 0; i < holeNum - 1; i++) {
		if (hole[i].state == EMPTY) continue;
		for (int j = i + 1; j < holeNum; j++) {
			if (hole[j].state == EMPTY) continue;
			int force = hole[i].atom.v * hole[j].atom.v / (hole[j].d - hole[i].d);
			aforce[hole[i].atom.idx] += force;
			aforce[hole[j].atom.idx] -= force;
		}
	}
	
	//result check
	int cnt = 0;
	for (int i = 0; i < holeNum; i++) {
		if (hole[i].state == EMPTY) continue;
		cnt++;
		if (aforce[hole[i].atom.idx] != 0) {
			return -1;
		}
	}
	return cnt;
}

void printhole() {
	printf("===========\n");
	for (int i = 0; i < holeNum; i++) {
		printf("[%d](%d)H : ", i, hole[i].state);
		if (hole[i].state == FULL) printf("atom: %d[v: %d]", hole[i].atom.idx, hole[i].atom.v);
		printf("\n");
	}
}

int ans=0;

void dfs(int usedAtom, int count) {
	//if (ans > usedAtom) return;	
	if (usedAtom != 0) {
	
		if (saturationCheck() != -1) {
	
			if (ans < usedAtom) {
				printhole();
				ans = usedAtom;
			}
		}
	}

	if (count == holeNum) return;


	for (int i = 0; i < atomNum; i++) {
		if (atom[i].used == 1) continue;
		hole[count].state = FULL;
		hole[count].atom = atom[i];
		atom[i].used = 1;

 		dfs(usedAtom+1, count + 1);

		hole[count].state = EMPTY;
		atom[i].used = 0;
	}
	dfs(usedAtom, count + 1);
}



void init() {
	ans = 0;
	for (int i = 0; i < 7; i++) {
		atom[i].idx = i;
		atom[i].v = 0;
		//atom[i].force = 0;
		atom[i].used = 0;

		hole[i].d = 0;
		hole[i].state = EMPTY;
	}
}

int main() {
	scanf("%d", &TC);
	for (int T = 1; T <= TC; T++) {
		//00. initialization
		init();
		//01. input
		scanf("%d %d", &atomNum, &holeNum);
		for (int i = 0; i < atomNum; i++) {
			scanf("%d", &atom[i].v);
		}
		for (int i = 0; i < holeNum; i++) {
			scanf("%d", &hole[i].d);
		}
		//02. hole sorting
		holesort();

		//03. TEST
		//hole[0].state = FULL;
		//hole[0].atom = atom[1];
		//hole[1].state = FULL;
		//hole[1].atom = atom[0];
		//hole[2].state = FULL;
		//hole[2].atom = atom[2];
		//printf("%d", saturationCheck());

		//04. Loop
		dfs(0, 0);

		printf("%d\n", ans);
	}
}
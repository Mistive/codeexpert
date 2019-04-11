//11min
#include <stdio.h>

int TC;
int N;
int order[20];

int max = 0;
void dfs(int preA, int preB, int sum, int count) {
	if (count == N) {
		if (sum > max)
			max = sum;
		return;
	}
	
	//A에 넣는 경우
	if (preA > order[count]) {
		dfs(order[count], preB, sum+order[count], count + 1);
	}
	//B에 넣는 경우
	if (preB < order[count]) {
		dfs(preA, order[count], sum + order[count], count + 1);
	}
	//pass
	dfs(preA, preB, sum, count + 1);
}


int main() {
	scanf("%d", &TC);
	for (int T = 1; T <= TC; T++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &order[i]);
		}
		dfs(1001, 0, 0, 0);
	
		printf("%d\n", max);
		
		max = 0;
	}
}
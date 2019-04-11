#include <stdio.h>

int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);



	//int sum = 0;
	//for (int i = 1; i < N; i++) {
	//	sum += i * 2;
	//}
	//printf("%ld\n",sum*2);

	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if ((N - x)*(N - x) + (N - y)*(N - y) <= N*N) sum++;
		}
	}

	printf("%d\n",sum*4);
	return 0;
}
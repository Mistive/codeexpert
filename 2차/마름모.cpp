//31min
#include <stdio.h>

int N, K;

int arr[28];
int queue[6 * 28];
int p;
int main() {
	scanf("%d %d", &N, &K);

	
	for (int i = 0; i < N; i++) {
		char c;
		scanf("%c", &c);
		if (c == '\n') 	scanf("%c", &c);

		if (c >= '0' && c <= '9') {
			arr[i] = c - '0';
		}
		else {
			arr[i] = c - 'A'+10;
		}
		//printf("%d\n", arr[i]);
	}



	for (int s = 0; s < N/4; s++) {

		for (int i = 0; i < 4; i++) {
			int num = 0;
			for (int k = 0; k < N / 4; k++) {
				int idx = (s + (i*N / 4) + (N / 4 - k - 1)) % N;
				
				num += (arr[idx] << (k * 4));
			}
			queue[p++] = num;
		}
	}

	//printf("p: %d\n", p);

	for (int i = 0; i < p-1; i++) {
		for (int j = i + 1; j < p; j++) {
			if (queue[i] == queue[j]) {
				queue[j] = -1;
				continue;
			}
			else if (queue[i] < queue[j]) {
				int tmp = queue[i];
				queue[i] = queue[j];
				queue[j] = tmp;
			}
		}
	}
	//for (int i = 0; i < p; i++) {
	//	printf("%d\n", queue[i]);
	//}

	printf("%d\n", queue[K-1]);
	
}
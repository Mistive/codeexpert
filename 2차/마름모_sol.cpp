#include <stdio.h>
int N, K, M;
char a[30];
int b[30];
void solve(void){
	int i, j, sum=0;
	for (i=0; i< N; i+=N/4){
		sum=0;
		for (j=i; j< i+N/4; j++){
			sum = sum*16 + a[j];
			//if(a[j] >= 'A') sum = sum*16+(a[j]-'A'+10);
			//else sum = sum*16+(a[j]-'0');
		}
		b[M++]=sum;
	}
}
void sort(void){
	int i, j, temp;
	for (i=0; i< M-1; i++){
		for (j=i+1; j< M; j++){
			if (b[i]< b[j]){
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
}
int main(void){
	int i, j, k;
	scanf("%d %d", &N, &K);
	//scanf("%s", &a[0]);
	for (i=0; i< N; i++){
		scanf("%1x", &a[i]);
	}
	
	for (i=0; i< N/4; i++){
		char temp=a[N-1];
		for (j=N-2; j >= 0; j--){
			a[j+1] = a[j];
		}
		a[0]=temp;
		solve();
	}
	sort();
	int cnt=0;
	b[M]=-1;
	for (i=0; i< M; i++){
		if (b[i]!=b[i+1]){
			cnt++;
			if (cnt==K) break;
		}
	}
	printf("%d\n", b[i]);

	return 0;
}
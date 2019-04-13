// 구슬 배치하기 
#if 01 
#include <stdio.h> 
#define MAX (10) 
int N, M; // N 구슬의수, M 홀의 수 
int g[MAX]; 
int h[MAX]; 
int v[MAX];  // 구슬을 중복배치하지 않기 위해 사용 
int sol; 
  
int cnt; 
int list[MAX];                   // 홀에 배치된 구슬 상태 
void printList(int L) 
{ 
       int i; 
       printf("%2d : ", ++cnt); 
       for (i=1; i < L; i++) 
       { 
             printf("%2d ", list[i]); 
       } 
       printf("\n"); 
} 
  
void input(void) 
{ 
       int i; 
  
       scanf("%d %d", &N, &M); 
       for (i=1; i <= N; i++) 
       { 
             scanf("%d", &g[i]); 
       } 
       for (i=1; i <= M; i++) 
       { 
             scanf("%d", &h[i]); 
       } 
} 
  
// 홀을 정렬 
// 홀의 위치를 정렬해서 고정해 놓아야 (=> depth로 사용해라!) 
// "거리" 계산이나 "방향" 확인에 유용하게 사용할 수 있음 
void sort(void) 
{ 
       int iy, jx, temp; 
       for (iy=1; iy <= M - 1; iy++) 
       { 
             for (jx=iy + 1; jx <= M; jx++) 
             { 
                    if (h[iy] > h[jx])  //오름차순 정렬 
                    { 
                           temp = h[iy]; 
                           h[iy] = h[jx]; 
                           h[jx] = temp; 
                    } 
             } 
       } 
} 
  
int getPower(void) 
{ 
       int i, j; 
       int sum[MAX] ={ 0 }; 
       int power; 
  
       for (i=1; i <= M - 1; i++) 
       { 
             for (j=i + 1; j <= M; j++) 
             { 
                 //if (구슬(i)전하량 == 0 || 구슬(j)전하량 == 0) continue; 
                    if (list[i] == 0 || list[j] == 0) continue; 
                    //(홀(i)에 배치된 구슬전하량 * 홀(j)에 배치된 구슬전하량) / (위치(j)-위치(i)) 
                    power = (list[i] * list[j]) / (h[j] - h[i]); 
                    sum[i] += power; 
                    sum[j] += -power; 
             } 
       } 
       // 제자리 확인 
       for (i=1; i <= M; i++) { 
             if (sum[i] != 0) return 0; 
       } 
       return 1; 
} 
// L: 홀의 번호, C: 배치된 구슬의 개수 
void DFS(int L, int C ) 
{ 
       int i; 
       // 지금까지 배치된 구슬 수 + 앞으로 최대 배치될 수 있는 구슬 수 <= sol 
       //if (C + M - L + 1 <= sol) return;  
       if (L > M) 
       { 
             //printList(L); 
             if (C > sol && getPower() == 1)  // 모두 제자리에 있으면 1 리턴 
             { 
                    sol = C; 
             } 
             return; 
       } 
       for (i=1; i <= N; i++)  // i : 구슬의 번호 
       { 
             if (v[i] == 0) 
             { 
                    v[i] = 1; list[L] = g[i]; 
                    DFS(L + 1, C + 1); 
                    v[i] = 0; list[L] = 0; 
             } 
       } 
       DFS(L + 1, C);  // 구슬을 배치하지 않음 
} 
int main(void) 
{ 
       int tc, T; 
       //T = 1; 
       scanf("%d", &T); 
       for (tc=1; tc <= T; tc++) 
       { 
             input(); 
             sort(); 
             sol = 1; // max를 찾는 것이므로 min으로 초기화 
             DFS(1, 0); 
             printf("%d\n", sol); 
       } 
       return 0; 
} 
#endif 
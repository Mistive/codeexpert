// ���� ��ġ�ϱ� 
#if 01 
#include <stdio.h> 
#define MAX (10) 
int N, M; // N �����Ǽ�, M Ȧ�� �� 
int g[MAX]; 
int h[MAX]; 
int v[MAX];  // ������ �ߺ���ġ���� �ʱ� ���� ��� 
int sol; 
  
int cnt; 
int list[MAX];                   // Ȧ�� ��ġ�� ���� ���� 
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
  
// Ȧ�� ���� 
// Ȧ�� ��ġ�� �����ؼ� ������ ���ƾ� (=> depth�� ����ض�!) 
// "�Ÿ�" ����̳� "����" Ȯ�ο� �����ϰ� ����� �� ���� 
void sort(void) 
{ 
       int iy, jx, temp; 
       for (iy=1; iy <= M - 1; iy++) 
       { 
             for (jx=iy + 1; jx <= M; jx++) 
             { 
                    if (h[iy] > h[jx])  //�������� ���� 
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
                 //if (����(i)���Ϸ� == 0 || ����(j)���Ϸ� == 0) continue; 
                    if (list[i] == 0 || list[j] == 0) continue; 
                    //(Ȧ(i)�� ��ġ�� �������Ϸ� * Ȧ(j)�� ��ġ�� �������Ϸ�) / (��ġ(j)-��ġ(i)) 
                    power = (list[i] * list[j]) / (h[j] - h[i]); 
                    sum[i] += power; 
                    sum[j] += -power; 
             } 
       } 
       // ���ڸ� Ȯ�� 
       for (i=1; i <= M; i++) { 
             if (sum[i] != 0) return 0; 
       } 
       return 1; 
} 
// L: Ȧ�� ��ȣ, C: ��ġ�� ������ ���� 
void DFS(int L, int C ) 
{ 
       int i; 
       // ���ݱ��� ��ġ�� ���� �� + ������ �ִ� ��ġ�� �� �ִ� ���� �� <= sol 
       //if (C + M - L + 1 <= sol) return;  
       if (L > M) 
       { 
             //printList(L); 
             if (C > sol && getPower() == 1)  // ��� ���ڸ��� ������ 1 ���� 
             { 
                    sol = C; 
             } 
             return; 
       } 
       for (i=1; i <= N; i++)  // i : ������ ��ȣ 
       { 
             if (v[i] == 0) 
             { 
                    v[i] = 1; list[L] = g[i]; 
                    DFS(L + 1, C + 1); 
                    v[i] = 0; list[L] = 0; 
             } 
       } 
       DFS(L + 1, C);  // ������ ��ġ���� ���� 
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
             sol = 1; // max�� ã�� ���̹Ƿ� min���� �ʱ�ȭ 
             DFS(1, 0); 
             printf("%d\n", sol); 
       } 
       return 0; 
} 
#endif 
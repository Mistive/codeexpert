#include <stdio.h>

#define MAX (10+2)
typedef struct _ind
{
	int r;
	int c;
}IND;
int N;
int map[MAX][MAX];
int end;
IND Que[MAX*MAX];
int swp;
int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };
int min;
int count;
void input(void)
{
	register int i, j;
	int tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &tmp);
			if (tmp == 2)
				Que[swp++] = (IND) { i, j };
			else if (tmp == 1)
				count++;
			map[i][j] = tmp;
		}
	}
	end = N * N;
}

int BFS(int add)
{
	int visit[MAX][MAX] = { 0 };
	int wp, rp;
	int cr, cc;
	register int i, nr, nc;
	IND out;
	wp = swp;
	rp = 0;
	while (wp > rp)
	{
		out = Que[rp++];
		cr = out.r;
		cc = out.c;
		visit[cr][cc] = 1;
		for (i = 0; i < 4; i++)
		{
			nr = cr + dr[i];
			nc = cc + dc[i];
			if (nr < 0 || nc <0 || nr >= N || nc >= N)	continue;
			if (map[nr][nc] == 1 && !visit[nr][nc])
			{
				visit[nr][nc] = 1;
				Que[wp++] = (IND) { nr, nc };
				add++;
				if (add >= min)	return min;
			}
		}
	}
	return add;
}
void DFS(int depth, int now, int en)
{
	int i, j;
	if (now == en)
	{
		min = BFS(en);
		return;
	}
	if (depth >= end)	return;
	i = depth / N;
	j = depth % N;
	if (map[i][j] == 1)
	{
		map[i][j] = 0;
		DFS(depth + 1, now + 1, en);
		map[i][j] = 1;
	}
	DFS(depth + 1, now, en);
}
int main(void)
{
	input();

	min = 0x7fff0000;
	if (!swp)
		printf("%d", count);
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (i > count)	break;
			DFS(0, 0, i);
		}
		printf("%d", count - min);
	}
	return 0;
}
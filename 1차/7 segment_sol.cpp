#include 
#define MAX (12+10)

char a[MAX][10];
int num[MAX][10];  // num[1][1] = 0 (사용가능) num[1][2] = 1 (불가능)
int data[10][10] = {
	{ 0 },
{ 4, 1, 2, 3, 7 },
{ 2, 1, 4 },
{ 2, 5, 6 },
{ 1, 2 },
{ 3, 1, 4, 7 },
{ 6, 1, 3, 4, 5, 7, 9 },
{ 3, 1, 7, 0 } };
int n1[1000];
int n1Cnt, n2Cnt;
int n2[1000];


void input(void)
{
	int i;
	for (i = 1; i <= 12; i++)
		scanf("%s", &a[i][1]);
}
void guessNumber(void)
{
	int i, j, k;
	for (i = 1; i <= 12; i++) // 12개 숫자 
	{
		for (j = 1; j <= 7; j++) // 7개 segments 
		{
			if (a[i][j] == '0') continue;
			for (k = 1; k <= data[j][0]; k++)
			{
				num[i][data[j][k]] = 1;  // 안되는 숫자에 1 
			}
		}
	}
}

int getNum(int base, int * arr)
{
	int i, j, k;
	int cnt = 0;
	int p1 = base + 1;
	int p2 = base + 2;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				if (num[base][i] == 0 && num[p1][j] == 0 && num[p2][k] == 0)
				{
					arr[++cnt] = i * 100 + j * 10 + k;
				}
			}
		}
	}
	return cnt;
}

int checkNum(int r)
{
	int i;

	for (i = 12; i >= 7; i--)
	{
		if (num[i][r % 10] == 1) return 0;
		r /= 10;
	}
	return 1;
}

int getSolution(void)
{
	int i, j;
	int r;
	int min = 0x7FFFFFFF;
	n1Cnt = getNum(1, n1);
	n2Cnt = getNum(4, n2);
	for (i = 1; i <= n1Cnt; i++)
	{
		for (j = 1; j <= n2Cnt; j++)
		{
			r = n1[i] * n2[j];
			if (min> r && checkNum(r) == 1) min = r;
		}
	}
	return min;
}

int main(void)
{
	input();
	guessNumber();
	printf("%d\n", getSolution());
	return 0;
}
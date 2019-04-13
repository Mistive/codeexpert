#include <stdio.h>

int R;
int sol;

int main(void)
{
	int i, j;


	scanf("%d", &R);


	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= R; j++)
		{
			if (((i*i) + (j*j)) <= (R*R)) sol++;
		}
	}
	sol = sol * 4;


	printf("%d", sol);

	return 0;
}
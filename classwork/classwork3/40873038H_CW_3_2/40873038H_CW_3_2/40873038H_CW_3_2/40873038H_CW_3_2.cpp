#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y, i, j, k;
	printf_s("====�C�L�P����====\n");
	printf_s("�п�J�~������Τ������:");
	scanf_s("%d%d", &x, &y);
	k = (x - y) / 2;
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= x; j++)
		{
			printf_s("* ");
		}
		printf_s("\n");
	}
	for (i = 1; i <= y; i++)
	{
		for (j = 1; j <= k; j++)
		{
			printf_s("* ");
		}
		for (j = 1; j <= y; j++)
		{
			printf_s("  ");
		}
		for (j = 1; j <= k; j++)
		{
			printf_s("* ");
		}
		printf_s("\n");
	}
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= x; j++)
		{
			printf_s("* ");
		}
		printf("\n");
	}
	system("pause");
}
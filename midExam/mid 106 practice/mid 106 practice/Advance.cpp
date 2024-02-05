#include<stdio.h>
#include<stdlib.h>
#include"Advance.h"
void p5()
{
	int m;
	printf_s("***************p5*****************\n");
	printf_s("*   Table of Permutation P(m,n)  *\n");
	while (1)
	{
		printf_s("Please input m(<=6):");
		if (scanf_s("%d", &m) == EOF)
			break;
		int i, j;
		for (i = 1;i <= m;i++)
		{
			for (j = 0;j <= i;j++)
			{
				printf_s("P%d%d=%d\t", i, j, p5(i, j));
			}
			printf_s("\n");
		}
	}
	system("pause");
}
int p5(int i,int j)
{
	int k,n=1;
	for (k = 0;k <= j-1;k++)
	{
		n *= (i - k);
	}
	return n;
}
void p6()
{
	int n, r;
	printf_s("***************p6*****************\n");
	printf_s("*         Reverse Number         *\n");
	while (1)
	{
		r = 0;
		printf_s("Please input an integer(<=10 digits):");
		if (scanf_s("%d", &n) == EOF)
			break;
		printf_s("Reverse of %d is:", n);
		if (n % 10 == 0)
		{
			while (n % 10 == 0)
			{
				n /= 10;
				printf_s("0");
			}
		}
		printf_s("%d\n", p6(n, r));
	}
	system("pause");
}
int p6(int n, int r)
{
	if (n == 0)
		return r;
	else
		return p6(n / 10, r * 10 + n % 10);
}
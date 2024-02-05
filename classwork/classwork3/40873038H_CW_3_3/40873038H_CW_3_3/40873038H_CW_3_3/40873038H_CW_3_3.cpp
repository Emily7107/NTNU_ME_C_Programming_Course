#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, i, j;
	printf_s("=========¦C¦L¹Ï§Î=========\n");
	printf_s("Please input length:\n");
	scanf_s("%d", &x);
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= x; j++)
		{
			if (i == j || i + j == (x + 1))
				printf_s("1 ");
			else
				printf_s("0 ");
		}
		printf_s("\n");
	}
	system("pause");
}
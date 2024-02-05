#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			printf_s("%d^%d=%4d,\t", j, i, (int)pow(j, i));
		}
		printf_s("\n");
	}
	system("pause");
}
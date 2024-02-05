#include<stdio.h>
#include<stdlib.h>
bool isPrime(int);
int main()
{
	int n,j,count=0;
	do {
		printf_s("請輸入一個正整數<Ctrl Z 結束程式>:");
		
		if (scanf_s("%d", &n) == EOF)
			break;
		printf_s("========%d以內的質數有=======\n",n);
		for (j = 1;j <= n;j++)
		{
			if (isPrime(j) == 1)
			{
				printf_s("%4d\t", j);
				count++;
				if (count % 10 == 0)
				{
					printf_s("\n");
					printf_s("\n");
				}
			}
			else
				continue;
		}
		printf_s("\n");

		
	} while (1);
	
}
bool isPrime(int j)
{
	int i, count = 0;
	for (i = 1;i <= j;i++)
	{
		if (j % i == 0)
			count++;
		else
			continue;
	}
	if (count < 3 && count != 1)
		return true;
	else
		return false;
}
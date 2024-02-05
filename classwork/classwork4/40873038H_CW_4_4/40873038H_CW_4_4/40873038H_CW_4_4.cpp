#include<stdio.h>
#include<stdlib.h>
bool isPrime(int);
int isPrime2(int);
int main()
{
	int n;
	do {
		printf_s("輸入一個整數<Ctrl z 結束程式:\n");
			if (scanf_s("%d", &n) == EOF)
				break;
			else
			printf_s("%d內共有%d個質數:\n", n, isPrime2(n));
	} while (1);
	system("pause");
	return 0;
}
bool isPrime(int j)
{
	int i, count2 = 0;
	for (i = 1;i <= j;i++)
	{
		if (j % i == 0)
			count2++;
		else
			continue;
	}
	if (count2 < 3 && count2 != 1)
		return true;
	else
		return false;
}
int isPrime2(int n)
{
	int j, count(0);
		for (j = 1;j <= n;j++)
		{
			if (isPrime(j))
				count++;
		}
		return count;
}
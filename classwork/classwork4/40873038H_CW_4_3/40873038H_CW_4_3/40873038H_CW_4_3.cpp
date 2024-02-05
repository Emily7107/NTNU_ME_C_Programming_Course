#include<stdio.h>
#include<stdlib.h>
bool isPrime(int);
int main()
{
	int n,result;
	do {
			printf_s("輸入一個整數<Ctrl Z 結束程式>:\n");
			if (scanf_s("%d", &n) == EOF)
				break;
			if (isPrime(n))
				printf_s("%d為質數\n", n);
			else
				printf_s("%d為合數\n", n);
	} while (1);
	system("pause");
	return 0;
}
bool isPrime(int n)
{
	    int i,count=0;
		for (i = 1;i <= n;i++)
		{
			if (n % i == 0)
				count++;
			else
				continue;
		}
		if (count >= 3)
			return false;
		else
			return true;
}
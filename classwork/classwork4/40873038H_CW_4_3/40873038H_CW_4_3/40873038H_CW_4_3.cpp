#include<stdio.h>
#include<stdlib.h>
bool isPrime(int);
int main()
{
	int n,result;
	do {
			printf_s("��J�@�Ӿ��<Ctrl Z �����{��>:\n");
			if (scanf_s("%d", &n) == EOF)
				break;
			if (isPrime(n))
				printf_s("%d�����\n", n);
			else
				printf_s("%d���X��\n", n);
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
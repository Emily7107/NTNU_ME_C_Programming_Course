#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, i, a;
	printf_s("�п�J�@�Ӿ��:");
	scanf_s("%d", &x);
	printf_s("%d���]�Ʀ�:\n", x);
	for (i = 1;i <= x;i++)
	{
		if (x % i != 0)
			continue;
		a = x / i;
		if (a != i && a > i)
		{
			printf_s("%4d,\t", i);
			printf_s("%4d\n", a);
		}
		else if (a == i)
			printf_s("%4d,\n", i);
	}
	system("pause");
}
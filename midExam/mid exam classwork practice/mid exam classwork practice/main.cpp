#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int f(int);
int main()
{
	int a,i;
	printf_s("======�C�L�en�����O�i�Ǧ�ƦC======\n");
	while (1)
	{
		printf_s("�п�J�@���:");
		scanf_s("%d", &a);
		for (i = 0;i <= a;i++)
		{
			printf_s("fib(%d)=%d\n", i, f(i));
		}

	}
	system("pause");
}
int f(int i)
{
	if (i == 0 || i == 1)
		return 1;
	else
		return f(i - 1) + f(i - 2);
}
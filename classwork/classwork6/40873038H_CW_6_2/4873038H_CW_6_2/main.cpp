#include<stdio.h>
#include<stdlib.h>
int p1(int, int, int);
int main()
{
	int a, d, n;
	while (1)
	{
		printf_s("½Ð¿é¤Ja,d,n:");
		if (scanf_s("%d %d %d", &a, &d, &n) == EOF)
			break;
		printf_s("S=%d\n", p1(a, d, n));
	}
	system("pause");
}
int p1(int a, int d, int n)
{
	if (n == 1)
		return a;
	else
		return p1(a, d, n - 1) + a + (n - 1) * d;
}
#include<stdio.h>
#include<stdlib.h>
int sumofSeries(int a, int d, int n);
int main()
{
	int a, d, n;
	printf_s("請輸入首項、公差和項數:");
	scanf_s("%d %d %d", &a, &d, &n);
	sumofSeries(a, d, n);
	printf_s("S=%d\n", sumofSeries(a, d, n));
	system("pause");
}
int sumofSeries(int a, int d, int n)
{
	int i,s=0;
	for (i = 1;i <= n;i++)
	{
		s += (a+(i - 1) * d);
	}
	return s;
}
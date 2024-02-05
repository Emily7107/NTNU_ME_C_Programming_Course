#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, an, sn, n;
	printf_s("Terms:");
	scanf_s("%d", &n);
	an = 1;
	sn = 1;
	for (i = 1; i <= n - 1; i++)
	{
		an = 2 * an + 1;
		sn = sn + an;
	}
	printf_s("an=%d\n", an);
	printf_s("sn=%d\n", sn);
	system("pause");
}
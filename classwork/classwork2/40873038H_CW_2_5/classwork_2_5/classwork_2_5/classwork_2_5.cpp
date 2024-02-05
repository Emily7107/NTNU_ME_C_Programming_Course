#include<stdio.h>
#include<stdlib.h>
int main()
{
	int j, n, x;
	double pi;
	printf_s("pi=4-4/3+4/5-4/7......\n");
	printf_s("Please input the number of terms:");
	scanf_s("%d", &n);
	pi = 0;
	for (j = 1; j <= n; j++)
	{
		if ((j + 1) % 2 == 0)
			x = 1;
		else
			x = -1;
		pi += ((double)x * 4 / (2 * j - 1));
	}
	printf_s("pi=%lf\n", pi);
	system("pause");
}
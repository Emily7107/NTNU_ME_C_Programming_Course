#include<stdio.h>
#include<stdlib.h>
int main()
{
	double t, pi, x;
	int n;
	printf_s("pi=4-4/3+4/5-4/7......\n");
	printf_s("Please input tolerance:");
	scanf_s("%lf", &t);
	n = 1;
	pi = 0;
	for ( ; (float)4 / (2 * n - 1) >= t; n++)
	{
		if ((n + 1) % 2 == 0)
			x = 1;
		else
			x = -1;
		pi += (x*(float)4 / (2 * n - 1));
	}
	printf_s("Terms used=%d\n", n);
	printf_s("pi=%lf\n", pi);
	system("pause");
}
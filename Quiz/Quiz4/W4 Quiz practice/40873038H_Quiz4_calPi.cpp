#include<stdio.h>
double calculatePi(int n)
{
	int i,x;
	double pi;
	pi = 0;
	for (i = 1;i <= n;i++)
	{
		if ((i + 1) % 2 == 0)
			x = 1;
		else
			x = -1;
		pi += ((float)x * 4 / (2 * i - 1));
	}
	return pi;
}
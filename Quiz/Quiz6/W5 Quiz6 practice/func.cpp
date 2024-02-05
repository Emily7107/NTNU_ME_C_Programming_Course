#include<stdio.h>
int gcd(int a, int b)
{
	int temp;
	while (a % b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}
int lcm(int a, int b)
{
	int temp,a1,b1,end;
	a1 = a;
	b1 = b;
	while (a % b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	a1 /= b;
	b1 /= b;
	end = a1 * b1 * b;
	return end;
}
#include<stdio.h>
int gcd(int a, int b)
{
	if ((a % b) == 0)
		return b;
	else
		return gcd(b, a % b);
}
int factorial(int a)
{
	if ((a == 1) || (a == 0))
		return 1;
	else
		return factorial(a - 1) * a;
}
int fib(int i)
{
	return (i == 0 || i == 1) ? 1 : fib(i - 1) + fib(i - 2);
}
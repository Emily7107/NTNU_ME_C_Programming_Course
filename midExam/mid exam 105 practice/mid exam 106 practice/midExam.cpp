#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"midExam.h"
void p1()
{
	float x1, y1, x2, y2;
	printf_s("**********p1**********\n");
	printf_s("*  Line Equation     *\n");
	while (1)
	{
		printf_s("Please input the coordinate of point 1:");
		if (scanf_s("%f %f", &x1, &y1) == EOF)
			break;
		printf_s("Please input the coordinate of point 2:");
		scanf_s("%f %f", &x2, &y2);
		p1(x1, y1, x2, y2);
	}
	system("pause");
}
float p1(float x1, float y1, float x2, float y2)
{
	float a, b;
	a = (y1 - y2) / (x1 - x2);
	b = y1 - a * x1;
	if (x1 == x2)
		return printf_s("x=%3.2f\n", x1);
	else if (y1 == y2)
		return printf_s("y=%3.2f\n", y1);
	else
		return printf_s("y=%3.2f*x=%3.2f\n", a, b);
}
void p2()
{
	double a, b, c;
	printf_s("*********P2**********\n");
	printf_s("*    求ax^2+bx+c的根    *\n");
	while (1)
	{
		printf_s("請輸入a,b,c:");
		if (scanf_s("%lf %lf %lf", &a, &b, &c) == EOF)
			break;
		else
			p2(a, b, c);
	}
	system("pause");
	system("cls");
}
double p2(double a, double b, double c)
{
	double t, t2, x1, x2;
	t = sqrt(b * b - 4 * a * c);
	t2 = sqrt(4 * a * c - b * b);
	x1 = (-b + t) / (2 * a);
	x2 = (-b - t) / (2 * a);
	if (a == 0)
		return printf_s("x^2的係數a 不能為零\n");
	if (t > 0)
		return printf_s("x=%lf or %lf\n", x1, x2);
	else if (t == 0)
		return printf_s("x=%lf<重根>\n", x1);
	else
		return printf_s("x=%lf+%lfi or %lf-%lfi\n", -b / (2 * a), t2 / (2 * a), -b / (2 * a), t2 / (2 * a));
}

void p3()
{
	int i,j,x;
	printf_s("********** P3 ************\n");
	printf_s("*  Symbols Arrangement   *\n");
	
	while (1)
	{
		printf_s("Please input side length (<10):");
		if (scanf_s("%d", &x) == EOF)
			break;
		for (i = 1; i <= x; i++)
		{
			for (j = 1; j <= x; j++)
			{

				if (i == j || i + j == (x + 1))
				{
					if (x%2!=0 && i == x / 2 + 1 && j == x / 2 + 1)
						printf_s("O ");
					else
						printf_s("+ ");
				}
				else
					printf_s("* ");
			}
			printf_s("\n");
		}
	}
	system("pause");
	system("cls");
}

void p4()
{
	int n, d;
	printf_s("*************p4************\n");
	printf_s("*   Prime factorization   *\n");
	while (1)
	{
		printf_s("Please input a integer number:");
		if (scanf_s("%d", &n) == EOF)
			break;
		d = n;
		while (n > 1)
		{
			if (p4(d))
			{
				while (n % d == 0)
				{
					n /= d;
					if (n != 1)
						printf_s("%d\t ", d);
					else
						printf_s("%d", d);
				}
			}
			d--;
		}
		printf_s("\n");
	}
	system("pause");
}
bool p4(int d)
{
	int i, count = 0;
	for (i = 1; i <= d; i++)
	{
		if (d % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}
void p5()
{
	int n, r;
	printf_s("***************p5*****************\n");
	printf_s("*         Reverse Number         *\n");
	while (1)
	{
		r = 0;
		printf_s("Please input an integer(<=10 digits):");
		if (scanf_s("%d", &n) == EOF)
			break;
		printf_s("Reverse of %d is:", n);
		if (n % 10 == 0)
		{
			while (n % 10 == 0)
			{
				n /= 10;
				printf_s("0");
			}
		}
		printf_s("%d\n", p5(n, r));
	}
	system("pause");
}
int p5(int n, int r)
{
	if (n == 0)
		return r;
	else
		return p5(n / 10, r * 10 + n % 10);
}

void p6()
{
	int n;
	printf_s("**********p6**********\n");
	printf_s("*   Tower of Hanoi   *\n");
	while (1)
	{
		printf_s("Please input disk num <1<=n<=4>:");
		if (scanf_s("%d", &n) == EOF)
			break;
		if (n > 4)
			printf_s("Error input!\n");
		else
		{
			printf_s("***S=Source,A=Auxiliary,T=Target***\n");
			p6(n, 'S', 'T', 'A');
		}
	}
	system("pause");
}
void p6(int n, char source, char target, char auxiliary)
{
	if (n > 0)
	{
		p6(n - 1, source, auxiliary, target);
		printf_s("Disk%d:\t%c==>%c\n", n, source, target);
		p6(n - 1, auxiliary, target, source);
	}
}
#include<stdio.h>
#include<stdlib.h>
#include"Fundamental.h"
void p1()
{
	double w, h;
	printf_s("**********p1**********\n");
	printf_s("*   BMI Calculation  *\n");
	while (1)
	{
		printf_s("Please input the height:");
		if (scanf_s("%lf", &h) == EOF)
			break;
		printf_s("Please input the weight:");
		scanf_s("%lf", &w);
		printf_s("BMI=%lf\n", p1(h, w));
		if (p1(h, w) < 18.5)
			printf_s("體重過輕\n");
		else if (p1(h, w) >= 18.5 && p1(h, w) < 24)
			printf_s("體重適中\n");
		else
			printf_s("體重過重\n");
	}
	system("pause");
}
double p1(double h, double w)
{
	double BMI;
	BMI = w / ((h / 100) * (h / 100));
	return BMI;
}
void p2()
{
	float x1, y1, x2, y2;
	printf_s("**********p2**********\n");
	printf_s("*    Line Equation   *\n");
	while (1)
	{
		printf_s("Please input the coordinate of point 1:");
		if (scanf_s("%f %f",&x1,&y1) == EOF)
			break;
		printf_s("Please input the coordinate of point 2:");
		scanf_s("%f %f",&x2,&y2);
		p2(x1, y1, x2, y2);
	}
	system("pause");
}
void p2(float x1, float y1, float x2, float y2)
{
	float a, b;
	a = (y1 - y2) / (x1 - x2);
	b = y1 - a * x1;
	if (y1 == y2)
		printf_s("y=%3.2f\n", y1);
	else if (x1 == x2)
		printf_s("x=%3.2f\n", x1);
	else
		printf_s("y=%3.2f*x=%3.2f\n", a, b);
}
void p3()
{
	int n;
	printf_s("**********p3**********\n");
	printf_s("*   Prime Judgement  *\n");
	while (1)
	{
		printf_s("Please input a integer number:");
		if (scanf_s("%d", &n) == EOF)
			break;
		if (n < 0)
			printf_s("輸入錯誤\n");
		else if (p3(n))
			printf_s("%d是質數\n", n);
		else
			printf_s("%d不是質數\n", n);
	}
	system("pause");
}
bool p3(int n)
{
	int i, count=0;
	for (i = 1;i <= n;i++)
	{
		if (n % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}
void p4()
{
	int n;
	printf_s("************p4************\n");
	printf_s("*   Symbols Arrangement  *\n");
	while (1)
	{
		printf_s("Please input side length(<10):");
		if (scanf_s("%d", &n) == EOF)
			break;
		p4(n);
	}
	system("pause");
}
void p4(int n)
{
	int i, j;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (i == j && i + j == n + 1)
				printf_s("0 ");
			else if (i == j || i + j == n + 1)
				printf_s("+ ");
			else
				printf_s("* ");
		}
		printf_s("\n");
	}
}
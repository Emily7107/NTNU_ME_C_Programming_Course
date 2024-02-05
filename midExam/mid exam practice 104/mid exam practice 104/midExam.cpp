#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"midExam.h"
void test1()
{
		double a,b,c;
		printf_s("*********�Ĥ@�D**********\n");
		printf_s("*    �Dax^2+bx+c����    *\n");
		while (1)
		{
			printf_s("�п�Ja,b,c:");
			if (scanf_s("%lf %lf %lf", &a, &b, &c) == EOF)
				break;
			else
				p1(a, b, c);
		}
		system("pause");
		system("cls");
}
double p1(double a, double b, double c)
{
	double t, t2, x1, x2;
	t = sqrt(b * b - 4 * a * c);
	t2 = sqrt(4 * a * c - b * b);
	x1 = (-b + t) / (2 * a);
	x2 = (-b - t) / (2 * a);
	if (a == 0)
		return printf_s("x^2���Y��a ���ର�s\n");
	if (t > 0)
		return printf_s("x=%lf or %lf\n", x1, x2);
	else if (t == 0)
		return printf_s("x=%lf<����>\n", x1);
	else
		return printf_s("x=%lf+%lfi or %lf-%lfi\n", -b / (2 * a), t2 / (2 * a), -b / (2 * a), t2 / (2 * a));
}
void test2()
{
	printf_s("*********�ĤG�D**********\n");
	printf_s("*                �Ʀr����\n");
	int n, r = 0;
	while (1)
	{
		printf_s("�п�J�@�Ӿ��<<=10���>:");
		if (scanf_s("%d", &n) == EOF)
			break;
		else
		{
			reverse(n, r);
			printf_s("Reverse of %d is %d\n", n, reverse(n,r));
		}
	}
	system("pause");
	system("cls");
}
int reverse(int n,int r)
{
	if (n ==0)
		return r;
	else
		return reverse(n / 10, r * 10 + n % 10);
}
void test3()
{
	int n;
	printf_s("*********�ĤT�D**********\n");
	printf_s("*      �����൥��       *\n");
	while (1)
	{
		printf_s("�п�J����:");
		if (scanf_s("%d", &n) == EOF)
			break;
		if (n >= 0 && n <= 100)
			printf_s("%d�������Ĭ�%c\n", n, p3(n));
		else
			printf_s("���ƥ�������0~100����\n");
	}
	system("pause");
	system("cls");
}
char p3(int n)
{
	int y;
	y = n / 10;
	switch (y)
	{
	case 10:
	case 9:
		return 'A';
		break;
	case 8:
		return 'B';
		break;
	case 7:
		return 'C';
		break;
	case 6:
		return 'D';
		break;
	default:
		return 'E';
		break;
	}
}
void test4()
{
	printf_s("*********�ĥ|�D**********\n");
	while (1)
	{
		int a, b;
		printf_s("�п�J�~��Τ������(<10):");
		if (scanf_s("%d %d", &a, &b) == EOF)
			break;
		if ((a <= b) && ((a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0)))
		{
			printf_s("������׻ݤp��~�����\n");
			printf_s("������׻P�~����ץ����P����Ʃΰ���\n");
		}
		else if (a <= b)
			printf_s("������׻ݤp��~�����\n");
		else if ((a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0))
			printf_s("������׻P�~����ץ����P����Ʃΰ���\n");
		else
			p4(a, b);
	}
	system("pause");
	system("cls");
}
void p4(int a, int b)
{
	int i, j,s,e;
	s = (a - b) / 2 + 1;
	e = (a + b) / 2;
	for (i = 1;i <= a;i++)
	{
		for (j = 1;j <= a;j++)
		{
			if ((i >= s && i <= e) && (j >= s && j <= e))
				printf_s("  ");
			else
				printf_s("* ");
		}
		printf_s("\n");
	}
}
void test5()
{
	int m, n;
	printf_s("*********�Ĥ��D**********\n");
	printf_s("*        �ƦC�զX       *\n");
	while (1)
	{
		printf_s("�п�Jm,n:");
		if (scanf_s("%d %d", &m, &n) == EOF)
			break;
		else
			printf_s("c<%d,%d>=%d\n", m, n, p5(m, n));
	}
	system("pause");
	system("cls");
}
int p5(int m, int n)
{
	int i;
	double c = 1;
	if (n > m / 2)
		n = m - n;
	for (i = 1;i <= n;i++)
	{
		c *= (((double)m - i + 1) / i);
	}
	return (int)c;
}
void test6()
{
	int y;
	printf_s("*********�Ĥ��D**********\n");
	printf_s("*  �ˬd�Y�~�O�|�~�Υ��~ *\n");
	while (1)
	{
		printf_s("�п�J�~��<1~3000>:");
		if (scanf_s("%d", &y) == EOF)
			break;
		if (y < 1 || y>3000)
			printf_s("�~����������1~3000����\n");
		else if (p6(y))
			printf_s("�褸%8d�~���|�~\n", y);
		else
			printf_s("�褸%8d�~�����~\n", y);
	}
	system("pause");
	system("cls");
}
bool p6(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	else
		return false;
}
void test7()
{
	int n,d;
	printf_s("*********�ĤC�D**********\n");
	printf_s("*    �Y�ƪ���]�Ƥ���   *\n");
	while (1)
	{
		printf_s("�п�J�@�Ӿ��:");
		if (scanf_s("%d", &n) == EOF)
			break;
		d = 2;
		while (n >= d)
		{
			if (p7(d))
			{
				while (n % d == 0)
				{
					n /= d;
					printf_s("%8d", d);
				}
			}
			d++;
		}
		printf_s("\n");
			
	}
	system("pause");
	system("cls");
}
bool p7(int d)
{
	int i, count=0;
	for (i = 1;i <= d;i++)
	{
		if (d % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}
#include<stdio.h>
#include<stdlib.h>
int sumofSeries(int a, int d, int n);
int sumofSeries(int a1, int d1, int n1, int s);
int reversenumber(int, int);
int classwork6(int select2)
{
	switch (select2)
	{
	case 1:
		printf_s("執行classwork6_1\n");
		int a, d, n;
		printf_s("請輸入首項、公差和項數:");
		scanf_s("%d %d %d", &a, &d, &n);
		sumofSeries(a, d, n);
		printf_s("S=%d\n", sumofSeries(a, d, n));
		system("pause");
		break;
	case 2:
	{
		printf_s("執行classwork6_2\n");
		int a1, d1, n1, s = 0;
		printf_s("請輸入首項、公差和項數:");
		scanf_s("%d %d %d", &a1, &d1, &n1);
		sumofSeries(a1, d1, n1, s);
		printf_s("S=%d\n", sumofSeries(a1, d1, n1, s));
		system("pause");
		break;
	}
	case 3:
		printf_s("執行classwork6_3\n");
		int num, rev = 0;
		do {
			printf_s("Enter a number:\n");
			if (scanf_s("%d", &num) == EOF)
				break;
			if (num > 999999999 || num < 0 || num % 10 == 0)
				printf_s("輸入數字不合法!\n");
			else
			{
				reversenumber(num, rev);
				printf_s("The reversed number is %d\n", reversenumber(num, rev));
			}

		} while (1);
		system("pause");
		break;
	}
	if (select2 < 0 || select2 > 3)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return(select2);
}
int sumofSeries(int a, int d, int n)
{
	int i, s = 0;
	for (i = 1;i <= n;i++)
	{
		s += (a + (i - 1) * d);
	}
	return s;
}
int sumofSeries(int a1, int d1, int n1, int s)
{
	if (n1 == 0)
		return s;
	else
		return sumofSeries(a1, d1, n1 - 1, s + a1 + (n1 - 1) * d1);
}
int reversenumber(int num, int rev)
{
	if (num == 0)
		return rev;
	else
		return reversenumber(num / 10, rev * 10 + num % 10);
}
#include<stdio.h>
#include<stdlib.h>
int classwork2(int select2)
{
	
	switch (select2)
	{
	case 1:
		printf_s("執行classwork2_1\n");
		int year;
		printf_s("請輸入年分:");
		scanf_s("%d", &year);
		if (year % 4 == 0 && year % 100 != 0)
			printf_s("閏年\n");
		else if (year % 400 == 0 && year % 3200 != 0)
			printf_s("閏年\n");
		else
			printf_s("平年\n");
		system("pause");
		break;
	case 2:
		printf_s("執行classwork2_2\n");
		float x1, y1, x2, y2, a, b;
		printf_s("請輸入第一個點座標:");
		scanf_s("%f%f", &x1, &y1);
		printf_s("請輸入第二個點座標:");
		scanf_s("%f%f", &x2, &y2);
		a = (y1 - y2) / (x1 - x2);
		b = y1 - (a * x1);
		if (a == 0)
			printf_s("y=%0.f\n", y1);
		else if ((x1 - x2) / (y1 - y2) == 0)
			printf_s("x=%0.f\n", x1);
		else
			printf_s("y=%2.1fx+%0.f\n", a, b);
		system("pause");
		break;
	case 3:
		printf_s("執行classwork2_3\n");
		int x;
		printf_s("請輸入分數:");
		scanf_s("%d", &x);
		if (90 <= x && x <= 100)
			printf_s("A級\n");
		else if (80 <= x && x <= 89)
			printf_s("B級\n");
		else if (70 <= x && x <= 79)
			printf_s("C級\n");
		else if (60 <= x && x <= 69)
			printf_s("D級\n");
		else
			printf_s("E級\n");
		system("pause");
		break;
	case 4:
		printf_s("執行classwork2_4\n");
		int input, y;
		printf_s("請輸入成積:");
		scanf_s("%d", &input);
		y = input / 10;
		switch (y)
		{
		case 9:
		case 10:
			printf_s("A級\n");
			break;
		case 8:
			printf_s("B級\n");
			break;
		case 7:
			printf_s("C級\n");
			break;
		case 6:
			printf_s("D級\n");
			break;
		default:
			printf_s("E級\n");
			break;
		}
		system("pause");
		break;
	case 5:
		printf_s("執行classwork2_5\n");
		int j, n, work;
		double pi;
		printf_s("pi=4-4/3+4/5-4/7......\n");
		printf_s("Please input the number of terms:");
		scanf_s("%d", &n);
		pi = 0;
		for (j = 1; j <= n; j++)
		{
			if ((j + 1) % 2 == 0)
				work = 1;
			else
				work = -1;
			pi += ((float)work * 4 / (2 * j - 1));
		}
		printf_s("pi=%lf\n", pi);
		system("pause");
		break;
	case 6:
		printf_s("執行classwork2_6\n");
		double t, pi2, m;
		int num;
		printf_s("pi=4-4/3+4/5-4/7......\n");
		printf_s("Please input tolerance:");
		scanf_s("%lf", &t);
		num = 1;
		pi2 = 0;
		for (; (float)4 / (2 * num - 1) >= t; num++)
		{
			if ((num + 1) % 2 == 0)
				m = 1;
			else
				m = -1;
			pi2 += ((float)m * 4 / (2 * num - 1));
		}
		printf_s("Terms used=%d\n", num);
		printf_s("pi=%lf\n", pi2);
		system("pause");
		break;
	case 7:
		printf_s("執行classwork2_7\n");
		int i, an, sn, con;
		printf_s("Terms:");
		scanf_s("%d", &con);
		an = 1;
		sn = 1;
		for (i = 1; i <= con - 1; i++)
		{
			an = 2 * an + 1;
			sn = sn + an;
		}
		printf_s("an=%d\n", an);
		printf_s("sn=%d\n", sn);
		system("pause");
		break;

	}
	if (select2 < 0 || select2 > 7)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return select2;
}

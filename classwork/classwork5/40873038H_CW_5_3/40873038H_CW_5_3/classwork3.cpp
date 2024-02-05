#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int classwork3(int select2)
{

	switch (select2)
	{
	case 1:
		printf_s("執行classwork3_1\n");
		int i, j;
		for (i = 1; i <= 5; i++)
		{
			for (j = 1; j <= 5; j++)
			{
				printf_s("%d^%d=%4d,\t", j, i, (int)pow(j, i));
			}
			printf_s("\n");
		}
		system("pause");
		break;
	case 2:
		printf_s("執行classwork3_2\n");
		int x, y, i1, j1, k;
		printf_s("====列印星狀圖====\n");
		printf_s("請輸入外圈邊長及內圈邊長:");
		scanf_s("%d%d", &x, &y);
		k = (x - y) / 2;
		for (i1 = 1; i1 <= k; i1++)
		{
			for (j1 = 1; j1 <= x; j1++)
			{
				printf_s("* ");
			}
			printf_s("\n");
		}
		for (i1 = 1; i1 <= y; i1++)
		{
			for (j1 = 1; j1 <= k; j1++)
			{
				printf_s("* ");
			}
			for (j1 = 1; j1 <= y; j1++)
			{
				printf_s("  ");
			}
			for (j1 = 1; j1 <= k; j1++)
			{
				printf_s("* ");
			}
			printf_s("\n");
		}
		for (i1 = 1; i1 <= k; i1++)
		{
			for (j1 = 1; j1 <= x; j1++)
			{
				printf_s("* ");
			}
			printf("\n");
		}
		system("pause");
		break;
	case 3:
		printf_s("執行classwork3_3\n");
		int number, i2, j2;
		printf_s("=========列印圖形=========\n");
		printf_s("Please input length:\n");
		scanf_s("%d", &number);
		for (i2 = 1; i2 <= number; i2++)
		{
			for (j2 = 1; j2 <= number; j2++)
			{
				if (i2 == j2 || i2 + j2 == (number + 1))
					printf_s("1 ");
				else
					printf_s("0 ");
			}
			printf_s("\n");
		}
		system("pause");
		break;
	case 4:
		printf_s("執行classwork3_4\n");
		int innumber,i3;
		printf_s("請輸入十位數以內的數字:");
		scanf_s("%d", &innumber);
		i3 = 0;
		while (i3 <= 10)
		{
			if (innumber > 0)
			{
				printf_s("%d", innumber % 10);
				innumber /= 10;
				i3++;
			}
			else
				break;
		}
		printf_s("\n");
		system("pause");
		break;

	}
	if (select2 < 0 || select2 > 5)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return select2;
}
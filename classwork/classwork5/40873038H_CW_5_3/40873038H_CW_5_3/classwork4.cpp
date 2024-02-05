#include<stdio.h>
#include<stdlib.h>
bool isLeap(int);
int noofLeap(int, int);
bool isPrime(int);
int isPrime2(int);
int classwork4(int select2)
{
	
	switch (select2)
	{
	case 1:
		
		printf_s("執行classwork4_1\n");
		int year;
		do
		{
			printf_s("請輸入年分(Ctrl z結束程式):\n");
			if (scanf_s("%d", &year) == EOF)
				break;
			if (isLeap(year))
				printf_s("%d年為閏年\n==================\n", year);
			else
				printf_s("%d年為平年\n==================\n", year);
		} while (1);
		system("pause");
		break;
	case 2:
		printf_s("執行classwork4_2\n");
		int start, end;
		do {
			printf_s("輸入起始年份與結束年份<Ctrl Z 結束程式:\n");
			if (scanf_s("%d %d", &start, &end) == EOF)
				break;
			printf_s("%d~%d共有%d個閏年\n", start, end, noofLeap(start, end));
		} while (1);

			system("pause");
		break;
	case 3:
		printf_s("執行classwork4_3\n");
		int n, result;
		do {
			printf_s("輸入一個整數<Ctrl Z 結束程式>:\n");
			if (scanf_s("%d", &n) == EOF)
				break;
			if (isPrime(n))
				printf_s("%d為質數\n", n);
			else
				printf_s("%d為合數\n", n);
		} while (1);
		system("pause");
		break;
	case 4:
		printf_s("執行classwork4_4\n");
		int n1;
		do {
			printf_s("輸入一個整數<Ctrl z 結束程式:\n");
			if (scanf_s("%d", &n1) == EOF)
				break;
			else
				printf_s("%d內共有%d個質數:\n", n1, isPrime2(n1));
		} while (1);
		system("pause");
		break;
	case 5:
		printf_s("執行classwork4_5\n");
		int n3, j, count = 0;
		do {
			printf_s("請輸入一個正整數<Ctrl Z 結束程式>:");

			if (scanf_s("%d", &n3) == EOF)
				break;
			printf_s("========%d以內的質數有=======\n", n3);
			for (j = 1;j <= n3;j++)
			{
				if (isPrime(j) == 1)
				{
					printf_s("%4d\t", j);
					count++;
					if (count % 10 == 0)
					{
						printf_s("\n");
						printf_s("\n");
					}
				}
				else
					continue;
			}
			printf_s("\n");


		} while (1);

		system("pause");
		break;

	}
	if (select2 < 0 || select2 > 5)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return(select2);
}
bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}
int noofLeap(int start, int end)
{
	int i, count(0);
	for (i = start;i <= end;i++)
	{
		if (isLeap(i))
			count++;
	}
	return count;
}
bool isPrime(int n)
{
	int i, count = 0;
	for (i = 1;i <= n;i++)
	{
		if (n % i == 0)
			count++;
		else
			continue;
	}
	if (count < 3 && count != 1)
		return true;
	else
		return false;
}
int isPrime2(int n1)
{
	int j, count(0);
	for (j = 1;j <= n1;j++)
	{
		if (isPrime(j))
			count++;
	}
	return count;
}


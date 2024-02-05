#include<stdio.h>
#include<stdlib.h>
#include"midExam.h"
int main()
{
	int select, select2,k1,k2;
	while (1)
	{
		k1 = 0;
		system("cls");
		printf_s("=====Menu For 111 MidExam=====\n");
		printf_s("1. Fundamentals\n");
		printf_s("2. Advance\n");
		printf_s("0. Exit\n");
		printf_s("Please give your selection:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			while (1)
			{
				k2 = 0;
				system("cls");
				printf_s("=====Menu For Fundamental Problems=====\n");
				printf_s("1. p1\n");
				printf_s("2. p2\n");
				printf_s("3. p3\n");
				printf_s("4. p4\n");
				printf_s("0. Main Menu\n");
				printf_s("Please give your selection:");
				scanf_s("%d", &select2);
				switch (select2)
				{
				case 1:
					p1();
					break;
				case 2:
					p2();
					break;
				case 3:
					p3();
					break;
				case 4:
					p4();
					break;
				case 0:
					k2 = 1;
					break;
				}
				if (k2 == 1)
					break;
			}
			break;
		case 2:
			while (1)
			{
				k2 = 0;
				system("cls");
				printf_s("=====Menu For Advance Problems=====\n");
				printf_s("1. p5\n");
				printf_s("2. p6\n");
				printf_s("0. Main Menu\n");
				printf_s("Please give your selection:");
				scanf_s("%d", &select2);
				switch (select2)
				{
				case 1:
					p5();
					break;
				case 2:
					p6();
					break;
				case 0:
					k2 = 1;
					break;
				}
				if (k2 == 1)
					break;
			}
			break;
		case 0:
			k1 = 1;
			break;
		}
		if (k1 == 1)
			break;
	}
	printf_s("µ{¦¡µ²§ô\n");
	system("pause");
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int select1, select2;
	do {
		printf_s("======�D���=====\n");
		printf_s("1. classwork1\n");
		printf_s("2. classwork2\n");
		printf_s("3. classwork3\n");
		printf_s("0. Exit\n");
		printf_s("=================\n");
		printf_s("�п�J�A�����:\n");
		scanf_s("%d", &select1);
		switch (select1)
		{
		case 1:
			do {
				printf_s("=====ClassWork1���=====\n");
				printf_s("1. ClassWork1_1\n");
				printf_s("2. ClassWork1_2\n");
				printf_s("3. ClassWork1_3\n");
				printf_s("4. ClassWork1_4\n");
				printf_s("5. ClassWork1_5\n");
				printf_s("0. �^�D���\n");
				printf_s("===================\n");
				printf_s("�п�J�A�����:\n");
				scanf_s("%d", &select2);
				switch (select2)
				{
				case 1:
					printf_s("����classwork1_1\n");
					system("pause");
					break;
				case 2:
					printf_s("����classwork1_2\n");
					system("pause");
					break;
				case 3:
					printf_s("����classwork1_3\n");
					system("pause");
					break;
				case 4:
					printf_s("����classwork1_4\n");
					system("pause");
					break;
				case 5:
					printf_s("����classwork1_5\n");
					system("pause");
					break;
					
				}
				if (select2 < 0 || select2 > 5)
				{
					printf_s("��J���~\n");
					system("pause\n");
				}
			} while (select2!=0);
			 if (select2 == 0)
				printf_s("�^�D���\n");
			system("pause");
			 
			break;
		case 2:
			do {
				printf_s("=====ClassWork2���=====\n");
				printf_s("1. ClassWork2_1\n");
				printf_s("2. ClassWork2_2\n");
				printf_s("3. ClassWork2_3\n");
				printf_s("4. ClassWork2_4\n");
				printf_s("0. �^�D���\n");
				printf_s("===================\n");
				printf_s("�п�J�A�����:\n");
				scanf_s("%d", &select2);
				switch (select2)
				{
				case 1:
					printf_s("����classwork2_1\n");
					system("pause");
					break;
				case 2:
					printf_s("����classwork2_2\n");
					system("pause");
					break;
				case 3:
					printf_s("����classwork2_3\n");
					system("pause");
					break;
				case 4:
					printf_s("����classwork2_4\n");
					system("pause");
					break;
				
			}
			if (select2 < 0 || select2 > 4)
				{
					printf_s("��J���~\n");
					system("pause\n");
				}
		} while (select2 != 0);
			if (select2 == 0)
				printf_s("�^�D���\n");
			system("pause");
			break;
		case 3:
			do {
				printf_s("=====ClassWork3���=====\n");
				printf_s("1. ClassWork3_1\n");
				printf_s("2. ClassWork3_2\n");
				printf_s("3. ClassWork3_3\n");
				printf_s("4. ClassWork3_4\n");
				printf_s("5. ClassWork3_5\n");
				printf_s("0. �^�D���\n");
				printf_s("===================\n");
				printf_s("�п�J�A�����:\n");
				scanf_s("%d", &select2);
				switch (select2)
				{
				case 1:
					printf_s("����classwork3_1\n");
					system("pause");
					break;
				case 2:
					printf_s("����classwork3_2\n");
					system("pause");
					break;
				case 3:
					printf_s("����classwork3_3\n");
					system("pause");
					break;
				case 4:
					printf_s("����classwork3_4\n");
					system("pause");
					break;
				case 5:
					printf_s("����classwork3_5\n");
					system("pause");
					break;
				
				}
				if (select2 < 0 || select2 > 5)
				{
					printf_s("��J���~\n");
					system("pause\n");
				}
			} while (select2 != 0);
			if (select2 == 0)
				printf_s("�^�D���\n");
			system("pause");
			break;
		}
		if (select1 <0 || select1>3)
		{
			printf_s("��J���~\n");
			system("pause");
		}
		
	}while (select1!=0);
	printf_s("�����{��\n");
	system("pause");
}
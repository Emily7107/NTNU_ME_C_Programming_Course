#include<stdio.h>
#include<stdlib.h>
#include"classwork1.h"
#include"classwork2.h"
#include"classwork3.h"
#include"classwork4.h"
#include"classwork6.h"
#include"classwork8.h"
int main()
{
	int select1, select2;
	do {
		system("cls");
		printf_s("======主選單=====\n");
		printf_s("1. classwork1\n");
		printf_s("2. classwork2\n");
		printf_s("3. classwork3\n");
		printf_s("4. classwork4\n");
		printf_s("6. classwork6\n");
		printf_s("8. classwork8\n");
		printf_s("0. Exit\n");
		printf_s("=================\n");
		printf_s("請輸入你的選擇:\n");
		scanf_s("%d", &select1);
		switch (select1)
		{
		case 1:
			do {
				system("cls");
				printf_s("=====ClassWork1選單=====\n");
				printf_s("1. ClassWork1_1\n");
				printf_s("2. ClassWork1_2\n");
				printf_s("3. ClassWork1_3\n");
				printf_s("4. ClassWork1_4\n");
				printf_s("5. ClassWork1_5\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork1(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");

			break;
		case 2:
			do {
				system("cls");
				printf_s("=====ClassWork2選單=====\n");
				printf_s("1. ClassWork2_1\n");
				printf_s("2. ClassWork2_2\n");
				printf_s("3. ClassWork2_3\n");
				printf_s("4. ClassWork2_4\n");
				printf_s("5. ClassWork2_5\n");
				printf_s("6. ClassWork2_6\n");
				printf_s("7. ClassWork2_7\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork2(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");
			break;
		case 3:
			do {
				system("cls");
				printf_s("=====ClassWork3選單=====\n");
				printf_s("1. ClassWork3_1\n");
				printf_s("2. ClassWork3_2\n");
				printf_s("3. ClassWork3_3\n");
				printf_s("4. ClassWork3_4\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork3(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");
			break;
		case 4:
			do {
				system("cls");
				printf_s("=====ClassWork4選單=====\n");
				printf_s("1. ClassWork4_1\n");
				printf_s("2. ClassWork4_2\n");
				printf_s("3. ClassWork4_3\n");
				printf_s("4. ClassWork4_4\n");
				printf_s("5. ClassWork4_5\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork4(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");
			break;
		case 6:
			do {
				system("cls");
				printf_s("=====ClassWork6選單=====\n");
				printf_s("1. ClassWork6_1\n");
				printf_s("2. ClassWork6_2\n");
				printf_s("3. ClassWork6_3\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork6(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");
			break;
		case 8:
			do {
				system("cls");
				printf_s("=====ClassWork8選單=====\n");
				printf_s("1. ClassWork8_1\n");
				printf_s("2. ClassWork8_2\n");
				printf_s("3. ClassWork8_3\n");
				printf_s("0. 回主選單\n");
				printf_s("===================\n");
				printf_s("請輸入你的選擇:\n");
				scanf_s("%d", &select2);

				classwork8(select2);

			} while (select2 != 0);
			if (select2 == 0)
				printf_s("回主選單\n");
			system("pause");
			break;
		}
		if (select1 < 0 || select1>8||select1==5)
		{
			printf_s("輸入錯誤\n");
			system("pause");
		}

	} while (select1 != 0);

	printf_s("結束程式\n");
	system("pause");
}
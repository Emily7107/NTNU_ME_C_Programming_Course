#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
int mainMenu()
{
	int select;
	system("cls");
	printf("=====104 期中考選單======\n");
	printf("1. 基礎題\n");
	printf("2. 進階題\n");
	printf("0. 結束程式\n");
	printf("請輸入選項:\n");
	scanf_s("%d", &select);
	return select;
}
int FundamentalMenu()
{
	int select;
	system("cls");
	printf("=====基礎題選單======\n");
	printf("1. 第一題\n");
	printf("2. 第二題\n");
	printf("3. 第三題\n");
	printf("4. 第四題\n");
	printf("0. 回主選單\n");
	printf("請輸入選項:\n");
	scanf_s("%d", &select);
	return select;
}
int AdvanceMenu()
{
	int select;
	system("cls");
	printf("=====進階題題選單======\n");
	printf("1. 第五題\n");
	printf("2. 第六題\n");
	printf("3. 第七題\n");
	printf("0. 回主選單\n");
	printf("請輸入選項:\n");
	scanf_s("%d", &select);
	return select;
}

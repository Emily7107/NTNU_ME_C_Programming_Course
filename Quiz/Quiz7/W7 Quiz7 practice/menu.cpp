#include<stdio.h>
#include <stdlib.h>

int list()
{
	int select;
	system("cls");
	printf_s("=====主選單=====\n");
	printf_s("1. 遞迴問題\n");
	printf_s("2. 遞迴&三元運算\n");
	printf_s("0. 結束程式\n");
	printf_s("請輸入選項:\n");
	scanf_s("%d", &select);
	return select;
}
int list2()
{
	int select2;
	system("cls");
	printf_s("=====遞迴問題選單=====\n");
	printf_s("1. 最大公因數\n");
	printf_s("2. 階層\n");
	printf_s("0. 回主選單\n");
	printf_s("請輸入選項:");
	scanf_s("%d", &select2);
	return select2;
}
int list3()
{
	int select2;
	system("cls");
	printf_s("=====遞迴&三元運算問題選單=====\n");
	printf_s("1. 列印前n項之費波納西數列\n");
	printf_s("0. 回主選單\n");
	printf_s("請輸入選項:");
	scanf_s("%d", &select2);
	return select2;
}
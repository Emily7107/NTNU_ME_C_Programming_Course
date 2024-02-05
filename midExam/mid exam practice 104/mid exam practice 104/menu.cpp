#include<stdio.h>
#include<stdlib.h>
int list()
{
	int select;
	system("cls");
	printf_s("=====104期中考選單=====\n");
	printf_s("1. 基礎題\n");
	printf_s("2. 進階題\n");
	printf_s("0. 結束程式\n");
	printf_s("請輸入選項:");
	scanf_s("%d", &select);
	return(select);
}
int list2()
{
	int select2;
	system("cls");
	printf_s("======基礎題選單======\n");
	printf_s("1. 第一題\n");
	printf_s("2. 第二題\n");
	printf_s("3. 第三題\n");
	printf_s("4. 第四題\n");
	printf_s("0. 回主選單\n");
	printf_s("請輸入選項:");
	scanf_s("%d", &select2);
	return select2;
}
int list3()
{
	int select2;
	system("cls");
	printf_s("======進階題選單======\n");
	printf_s("1. 第五題\n");
	printf_s("2. 第六題\n");
	printf_s("3. 第七題\n");
	printf_s("0. 回主選單\n");
	printf_s("請輸入選項:");
	scanf_s("%d", &select2);
	return select2;
}

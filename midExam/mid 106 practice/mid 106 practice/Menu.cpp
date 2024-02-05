#include<stdio.h>
#include<stdlib.h>
int menu()
{
	int select;
	system("cls");
	printf_s("=====Menu For 106 MidExam====\n");
	printf_s("1. Fundametals\n");
	printf_s("2. Advance\n");
	printf_s("0. Exit\n");
	printf_s("Please give your selection:");
	scanf_s("%d",& select);
	return select;
}
int menu2()
{
	int select2;
	system("cls");
	printf_s("=====Menu For Fundanental Problems====\n");
	printf_s("1. p1\n");
	printf_s("2. p2\n");
	printf_s("3. p3\n");
	printf_s("4. p4\n");
	printf_s("0. Main Menu\n");
	printf_s("Please give your selection:");
	scanf_s("%d", &select2);
	return select2;
}
int menu3()
{
	int select2;
	system("cls");
	printf_s("=====Menu For Advance Problems====\n");
	printf_s("1. p5\n");
	printf_s("2. p6\n");
	printf_s("0. Main Menu\n");
	printf_s("Please give your selection:");
	scanf_s("%d", &select2);
	return select2;
}
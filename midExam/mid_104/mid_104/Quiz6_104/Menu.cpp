#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
int mainMenu()
{
	int select;
	system("cls");
	printf("=====104 �����ҿ��======\n");
	printf("1. ��¦�D\n");
	printf("2. �i���D\n");
	printf("0. �����{��\n");
	printf("�п�J�ﶵ:\n");
	scanf_s("%d", &select);
	return select;
}
int FundamentalMenu()
{
	int select;
	system("cls");
	printf("=====��¦�D���======\n");
	printf("1. �Ĥ@�D\n");
	printf("2. �ĤG�D\n");
	printf("3. �ĤT�D\n");
	printf("4. �ĥ|�D\n");
	printf("0. �^�D���\n");
	printf("�п�J�ﶵ:\n");
	scanf_s("%d", &select);
	return select;
}
int AdvanceMenu()
{
	int select;
	system("cls");
	printf("=====�i���D�D���======\n");
	printf("1. �Ĥ��D\n");
	printf("2. �Ĥ��D\n");
	printf("3. �ĤC�D\n");
	printf("0. �^�D���\n");
	printf("�п�J�ﶵ:\n");
	scanf_s("%d", &select);
	return select;
}

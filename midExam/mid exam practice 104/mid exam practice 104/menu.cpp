#include<stdio.h>
#include<stdlib.h>
int list()
{
	int select;
	system("cls");
	printf_s("=====104�����ҿ��=====\n");
	printf_s("1. ��¦�D\n");
	printf_s("2. �i���D\n");
	printf_s("0. �����{��\n");
	printf_s("�п�J�ﶵ:");
	scanf_s("%d", &select);
	return(select);
}
int list2()
{
	int select2;
	system("cls");
	printf_s("======��¦�D���======\n");
	printf_s("1. �Ĥ@�D\n");
	printf_s("2. �ĤG�D\n");
	printf_s("3. �ĤT�D\n");
	printf_s("4. �ĥ|�D\n");
	printf_s("0. �^�D���\n");
	printf_s("�п�J�ﶵ:");
	scanf_s("%d", &select2);
	return select2;
}
int list3()
{
	int select2;
	system("cls");
	printf_s("======�i���D���======\n");
	printf_s("1. �Ĥ��D\n");
	printf_s("2. �Ĥ��D\n");
	printf_s("3. �ĤC�D\n");
	printf_s("0. �^�D���\n");
	printf_s("�п�J�ﶵ:");
	scanf_s("%d", &select2);
	return select2;
}

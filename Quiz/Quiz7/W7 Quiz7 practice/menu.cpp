#include<stdio.h>
#include <stdlib.h>

int list()
{
	int select;
	system("cls");
	printf_s("=====�D���=====\n");
	printf_s("1. ���j���D\n");
	printf_s("2. ���j&�T���B��\n");
	printf_s("0. �����{��\n");
	printf_s("�п�J�ﶵ:\n");
	scanf_s("%d", &select);
	return select;
}
int list2()
{
	int select2;
	system("cls");
	printf_s("=====���j���D���=====\n");
	printf_s("1. �̤j���]��\n");
	printf_s("2. ���h\n");
	printf_s("0. �^�D���\n");
	printf_s("�п�J�ﶵ:");
	scanf_s("%d", &select2);
	return select2;
}
int list3()
{
	int select2;
	system("cls");
	printf_s("=====���j&�T���B����D���=====\n");
	printf_s("1. �C�L�en�����O�i�Ǧ�ƦC\n");
	printf_s("0. �^�D���\n");
	printf_s("�п�J�ﶵ:");
	scanf_s("%d", &select2);
	return select2;
}
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
int main()
{
	int a, b, select;
	do {
		printf_s("******************************\n");
		printf_s("* 1. �D��Ƥ��̤j���]��      *\n");
		printf_s("* 2. �D��Ƥ��̤p������      *\n");
		printf_s("* 0. �����{��                *\n");
		printf_s("******************************\n");
		printf_s("�п�J�ﶵ:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf_s("======�D��Ƥ��̤j���]��======\n");
			printf_s("�п�J��Ӿ��:");
			scanf_s("%d %d", &a, &b);
			gcd(a, b);
			printf_s("(%d,%d)=%8d", a, b, gcd(a, b));
			break;
		case 2:
			printf_s("======�D��Ƥ��̤p������======\n");
			printf_s("�п�J��Ӿ��:");
			scanf_s("%d %d", &a, &b);
			lcm(a, b);
			printf_s("(%d,%d)=%8d", a, b, lcm(a, b));
			break;
		}
		printf_s("\n");
	} while (select != 0);
	system("pause");
}
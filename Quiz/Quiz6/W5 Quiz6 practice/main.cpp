#include<stdio.h>
#include<stdlib.h>
#include"func.h"
int main()
{
	int a, b, select;
	do {
		printf_s("******************************\n");
		printf_s("* 1. ―ㄢ计ぇ程そ计      *\n");
		printf_s("* 2. ―ㄢ计ぇ程そ计      *\n");
		printf_s("* 0. 挡祘Α                *\n");
		printf_s("******************************\n");
		printf_s("叫块匡兜:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf_s("======―ㄢ计ぇ程そ计======\n");
			printf_s("叫块ㄢ俱计:");
			scanf_s("%d %d", &a, &b);
			gcd(a, b);
			printf_s("(%d,%d)=%8d", a, b, gcd(a, b));
			break;
		case 2:
			printf_s("======―ㄢ计ぇ程そ计======\n");
			printf_s("叫块ㄢ俱计:");
			scanf_s("%d %d", &a, &b);
			lcm(a, b);
			printf_s("(%d,%d)=%8d", a, b, lcm(a, b));
			break;
		}
		printf_s("\n");
	} while (select != 0);
	system("pause");
}
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
#include"menu.h"

int main()
{
	int a,b,k1,k2;
	do {
		k1 = 0;
		switch (list())
		{
		case 1:
			do {
				k2 = 0;
				switch (list2())
				{
				case 1:
					printf_s("======�̤j���]��======\n");
					printf_s("�п�J��Ӿ��:");
					scanf_s("%d %d", &a, &b);
					printf_s("(%d,%d)=%d\n", a, b, gcd(a, b));
					system("pause");
					break;
				case 2:
					printf_s("======���h======\n");
					printf_s("�п�J�@�Ӿ��:");
					scanf_s("%d", &a);
					printf_s("%d!=%d\n", a, factorial(a));
					system("pause");
					break;
				case 0:
					k2 = 1;
					break;
				}
			} while (k2!=1);
			break;
		case 2:
			do {
				k2 = 0;
				switch (list3())
				{
				case 1:
					int i;
					printf_s("======�C�L�en�����O�i�Ǧ�ƦC======\n");
					printf_s("�п�J�@���:");
					scanf_s("%d", &a);
					for (i = 0;i <= a;i++)
					{
						printf("f(%d)=%d \n", i, fib(i));
					}
					system("pause");
					break;
				case 0:
					k2 = 1;
					break;
				}
			} while (k2!=1);
			break;
		case 0:
			k1 = 1;
			break;
		}
	} while (k1!= 1);
	system("pause");
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y;
	printf_s("�п�J���n:");
	scanf_s("%d", &x);
	y = x / 10;
	switch (y)
	{
	case 9:
	case 10:
		printf_s("A��\n");
		break;
	case 8:
		printf_s("B��\n");
		break;
	case 7:
		printf_s("C��\n");
		break;
	case 6:
		printf_s("D��\n");
		break;
	default:
		printf_s("E��\n");
		break;
	}
	system("pause");
}
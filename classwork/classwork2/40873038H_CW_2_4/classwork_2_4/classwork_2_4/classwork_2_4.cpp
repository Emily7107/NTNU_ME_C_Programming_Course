#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y;
	printf_s("½Ð¿é¤J¦¨¿n:");
	scanf_s("%d", &x);
	y = x / 10;
	switch (y)
	{
	case 9:
	case 10:
		printf_s("A¯Å\n");
		break;
	case 8:
		printf_s("B¯Å\n");
		break;
	case 7:
		printf_s("C¯Å\n");
		break;
	case 6:
		printf_s("D¯Å\n");
		break;
	default:
		printf_s("E¯Å\n");
		break;
	}
	system("pause");
}
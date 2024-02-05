#include<stdio.h>
#include<stdlib.h>
bool isLeap(int);
int main()
{
	int year;
	do
	{
		printf_s("請輸入年分(Ctrl z結束程式):\n");
		if (scanf_s("%d", &year) == EOF)
			break;
		if (isLeap(year))
			printf_s("%d年為閏年\n==================\n",year);
		else
			printf_s("%d年為平年\n==================\n",year);
	} while (1);
	system("pause");
}
bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}
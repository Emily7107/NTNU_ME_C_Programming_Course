#include<stdio.h>
#include<stdlib.h>
bool isLeap(int);
int main()
{
	int year;
	do
	{
		printf_s("�п�J�~��(Ctrl z�����{��):\n");
		if (scanf_s("%d", &year) == EOF)
			break;
		if (isLeap(year))
			printf_s("%d�~���|�~\n==================\n",year);
		else
			printf_s("%d�~�����~\n==================\n",year);
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
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year;
	printf_s("�п�J�~��:");
	scanf_s("%d", &year);
	if (year % 4 == 0 && year % 100 != 0)
		printf_s("�|�~\n");
	else if (year % 400 == 0&&year%3200!=0)
		printf_s("�|�~\n");
	else
		printf_s("���~\n");
	system("pause");
}
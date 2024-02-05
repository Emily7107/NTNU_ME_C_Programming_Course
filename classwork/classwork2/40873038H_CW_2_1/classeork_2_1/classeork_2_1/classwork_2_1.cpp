#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year;
	printf_s("請輸入年分:");
	scanf_s("%d", &year);
	if (year % 4 == 0 && year % 100 != 0)
		printf_s("閏年\n");
	else if (year % 400 == 0&&year%3200!=0)
		printf_s("閏年\n");
	else
		printf_s("平年\n");
	system("pause");
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x;
    printf_s("請輸入分數:");
    scanf_s("%d", &x);
	if (90 <= x && x <= 100)
		printf_s("A級\n");
	else if (80 <= x && x <= 89)
		printf_s("B級\n");
	else if (70 <= x && x <= 79)
		printf_s("C級\n");
	else if (60 <= x && x <= 69)
		printf_s("D級\n");
	else
		printf_s("E級\n");
	system("pause");
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x;
    printf_s("�п�J����:");
    scanf_s("%d", &x);
	if (90 <= x && x <= 100)
		printf_s("A��\n");
	else if (80 <= x && x <= 89)
		printf_s("B��\n");
	else if (70 <= x && x <= 79)
		printf_s("C��\n");
	else if (60 <= x && x <= 69)
		printf_s("D��\n");
	else
		printf_s("E��\n");
	system("pause");
}
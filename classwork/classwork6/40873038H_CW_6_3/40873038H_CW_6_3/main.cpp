#include<stdio.h>
#include<stdlib.h>
int reversenumber(int, int);
int main()
{
	int num, rev = 0;
	do {
		printf_s("Enter a number:\n");
		if (scanf_s("%d", &num) == EOF)
			break;
		if (num > 999999999 || num < 0 || num % 10 == 0)
			printf_s("輸入數字不合法!\n");
		else
		{
			reversenumber(num, rev);
			printf_s("The reversed number is %d\n", reversenumber(num, rev));
		}
		
	} while (1);
	system("pause");
}
int reversenumber(int num, int rev)
{
	if (num == 0)
		return rev;
	else
		return reversenumber(num / 10, rev * 10 + num % 10);
}
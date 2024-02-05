#include<stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	printf_s("please input a :");
	scanf_s("%d", &a);
	printf_s("please input b :");
	scanf_s("%d", &b);
	c = (a * a - b * b * b) / (2 * a);
	printf_s("result = %d\n", c);

	system("pause");

}
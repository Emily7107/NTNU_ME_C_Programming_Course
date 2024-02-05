#include<stdio.h>
#include <stdlib.h>

int main() {
	double a, b, c;
	printf_s("please input a :");
	scanf_s("%lf", &a);
	printf_s("please input b :");
	scanf_s("%lf", &b);
	c = (a * a - b * b * b) / (2 * a);
	printf_s("result = %lf\n", c);

	system("pause");

}
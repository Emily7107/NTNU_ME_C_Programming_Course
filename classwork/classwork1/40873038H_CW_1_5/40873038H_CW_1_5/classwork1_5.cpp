#include<stdio.h>
#include <stdlib.h>

int main() {
	float a, b, c, d;
	printf_s("please input a, b, c, d :");
	scanf_s("%f%f%f%f", &a, &b, &c, &d);
	printf_s("Add : %f + %fi\n", a + c, b + d);
	printf_s("Sub : %f + %fi\n", a - c, b - d);
	printf_s("Mul : %f + %fi\n", a * c - b * d, a * d + b * c);
	printf_s("Div : (%f + %fi)/(%f)\n", a * c + b * d, b * c - a * d, c * c + d * d);

	system("pause");

}
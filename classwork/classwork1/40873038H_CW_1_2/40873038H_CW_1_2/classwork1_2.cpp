#include<stdio.h>
#include <stdlib.h>

int main() {
	int x;
	double y;
	char z;
	printf_s("Please input x:");
	scanf_s("%d", &x);
	printf_s("Please input y:");
	scanf_s("%lf", &y);
	printf_s("Please input z:");
	scanf_s(" %c", &z);
	printf_s("x = %d\ny = %lf\ny = %e\nz = %c\n", x, y, y, z);

	system("pause");

}
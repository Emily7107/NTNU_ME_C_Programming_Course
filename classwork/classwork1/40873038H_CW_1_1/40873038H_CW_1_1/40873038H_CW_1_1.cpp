#include<stdio.h>
#include <stdlib.h>

int main() {
	int x = 5;
	double y = 0.031415;
	char z = 'a';
	printf_s("x = %d\ny = %lf\ny = %e\nz = %c\n", x, y, y, z);

	system("pause");
}
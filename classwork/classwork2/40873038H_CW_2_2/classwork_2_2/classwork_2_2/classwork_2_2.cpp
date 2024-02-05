#include<stdio.h>
#include<stdlib.h>
int main()
{
	float x1, y1, x2, y2,a,b;
	printf_s("請輸入第一個點座標:");
	scanf_s("%f%f", &x1, &y1);
	printf_s("請輸入第二個點座標:");
	scanf_s("%f%f", &x2, &y2);
	a = (y1 - y2) / (x1 - x2);
	b = y1 - (a*x1);
	if (a == 0)
		printf_s("y=%0.f\n", y1);
	else if ((x1 - x2) / (y1 - y2) == 0)
		printf_s("x=%0.f\n", x1);
	else
		printf_s("y=%2.1fx+%0.f\n", a, b);
	system("pause");
}
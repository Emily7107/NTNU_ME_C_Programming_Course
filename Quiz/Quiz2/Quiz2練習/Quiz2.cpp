#include<stdio.h>
#include<stdlib.h>
int main()
{
	double x, y, BMI;
	printf_s("�п�J����<cm>:");
	scanf_s("%lf",&x);
	printf_s("�п�J�魫<Kg>:");
	scanf_s("%lf", &y);
	BMI = y / ((x / 100) * (x / 100));
	printf_s("BMI=%lf\n", BMI);
	if (BMI < 18.5)
		printf_s("�魫�L��\n");
	else if (18.5 <= BMI && BMI < 24)
		printf_s("�魫�A��\n");
	else
		printf_s("�魫�L��\n");
	system("pause");
}
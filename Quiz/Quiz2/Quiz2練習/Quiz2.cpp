#include<stdio.h>
#include<stdlib.h>
int main()
{
	double x, y, BMI;
	printf_s("請輸入身高<cm>:");
	scanf_s("%lf",&x);
	printf_s("請輸入體重<Kg>:");
	scanf_s("%lf", &y);
	BMI = y / ((x / 100) * (x / 100));
	printf_s("BMI=%lf\n", BMI);
	if (BMI < 18.5)
		printf_s("體重過輕\n");
	else if (18.5 <= BMI && BMI < 24)
		printf_s("體重適中\n");
	else
		printf_s("體重過重\n");
	system("pause");
}
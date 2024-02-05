#include<stdio.h>
#include<stdlib.h>
#include"40873038H_Quiz4_calPi.h"
int main()
{
	int k, n;
	double result;
	char select;
	k = 1;
	do {
		printf_s("==========第%d次測試==========\n", k);
		printf_s("pi=4-4/3+4/5-4/7......\n");
		printf_s("please input the number of terms:");
		scanf_s("%d", &n);
		result = calculatePi(n);
		printf_s("pi=%lf\n", result);
		printf_s("Again?<Y or y>:");
		scanf_s(" %c", &select,1);
		k++;
		printf_s("\n");
	} while (select == 'Y' || select == 'y');
	printf_s("==========結束程式==========\n");
	system("pause");
}
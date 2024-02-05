#include<stdio.h>
#include<stdlib.h>
int arrayInput(double arr[]);
void arrayPrint(double arr[], int size);
double arrayMax(double arr[], int size);
double arrayMin(double arr[], int size);
double arrayAvg(double arr[], int size);
int main()
{
	int i;
	char y;
	double a[10];
	do{
		system("cls");
		printf_s("==========Out put==========\n");
		printf_s("Please input floating numbers<no.<10, Terminated by Ctrl Z>:\n");
		i=arrayInput(a);
		arrayPrint(a, i);
		arrayMax(a, i);
		arrayMin(a, i);
		arrayAvg(a, i);
		printf_s("Max=%3.2lf\n", arrayMax(a, i));
		printf_s("Min=%3.2lf\n", arrayMin(a, i));
		printf_s("Mean=%3.2lf\n", arrayAvg(a, i) / i);
		printf_s("Do it Again?\n");
		scanf_s(" %c", &y);
	} while (y == 'Y' || y == 'y');
	printf_s("µ{¦¡µ²§ô\n");
	system("pause");
}
int arrayInput(double arr[])
{
	int i;
	for (i = 0; ;i++)
	{
		if (scanf_s("%lf", &arr[i]) == EOF)
			break;
	}
	return i;
}
void arrayPrint(double arr[], int size)
{
	int j;
	for (j = 0;j < size;j++)
	{
		printf_s("%3.2lf\t",arr[j]);
	}
	printf_s("\n");
}
double arrayMax(double arr[], int size)
{
	double max;
	int j;
	max = arr[0];
	for (j = 0;j < size;j++)
	{
		if (arr[j] > max)
			max = arr[j];
	}
	return max;
}
double arrayMin(double arr[], int size)
{
	double min;
	int j;
	min = arr[0];
	for (j = 0;j < size;j++)
	{
		if (arr[j] < min)
			min = arr[j];
	}
	return min;
}
double arrayAvg(double arr[], int size)
{
	double sum=0;
	int j;
	for (j = 0;j < size;j++)
	{
		sum += arr[j];
	}
	return sum;
}
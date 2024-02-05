#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void classwork7_1();
void classwork7_2();
void classwork7_3();
void classwork7_4();

int main()
{
	int select,k1;
	do {
		k1 = 0;
		system("cls");
		printf_s("========Classwork 7=======\n");
		printf_s("1. classwork7_1\n");
		printf_s("2. classwork7_2\n");
		printf_s("3. classwork7_3\n");
		printf_s("4. classwork7_4\n");
		printf_s("0. 程式結束\n");
		printf_s("Please enter your selection:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			classwork7_1();
			break;
		case 2:
			classwork7_2();
			break;
		case 3:
			classwork7_3();
 			break;
		case 4:
			classwork7_4();
			break;
		case 0:
			k1 = 1;
			break;
		}
	} while (k1 != 1);
	printf_s("程式結束\n");
	system("pause");
}
void classwork7_1()
{
	double n,temp;
	while (1)
	{
		printf_s("====================\n");
		printf_s("Please enter a num:");
		if (scanf_s("%lf", &n) == EOF)
			break;
		temp = 1;
		while ((temp - n / temp) > 1e-6 || (temp - n / temp) < -1e-6)
		{
			temp = (temp + n / temp) / 2;
		}
		printf_s("sqrt<%lf>=%lf\n", n, temp);
	}
}
void classwork7_2()
{

		int i, j;
		float arr[10], sum = 0, a = 0, k = 0, mean, uar, std, kurt;
		printf_s("========================================\n");
		printf_s("Please input several <<=10> integers:\n");
		for (i = 0;;i++)
		{
			if (scanf_s("%f", &arr[i]) == EOF)
				break;
		}
		for (j = 0;j < i;j++)
		{
			sum += arr[j];
		}
		mean = sum / j;
		for (j = 0;j < i;j++)
		{
			a += (arr[j] - mean) * (arr[j] - mean);
		}
		uar = a / j;
		std = (double)sqrt(uar);
		for (j = 0;j < i;j++)
		{
			k += (arr[j] - mean) * (arr[j] - mean) * (arr[j] - mean) * (arr[j] - mean);
		}
		kurt = (k / j) / (uar * uar) - 3;
		printf_s("Mean=%f\n", mean);
		printf_s("Uar=%f\n", uar);
		printf_s("Std=%f\n", std);
		printf_s("Kurtosis=%f\n", kurt);
		system("pause");
}
void classwork7_3()
{
	char ch, color[20] = { 0 };
	int i = 0,j;
	printf_s("=========================\n");
	printf_s("Please enter a string:\n");
	while ((ch = getchar()) != EOF)
	{
		color[i] = ch;
		i++;
	}
	printf_s("Reverse the input string\n");
	for (j = i-2;j >= 0;j--)
	{
		putchar(color[j]);
	}
	printf_s("\n");
	system("pause");
}
void classwork7_4()
{
	char ch, color[20] = { 0 };
	int i=0, j;
	printf_s("==================\n");
	printf_s("Please enter a string:\n");
	while ((ch = getchar()) != EOF)
	{
		color[i] = ch;
		i++;
	}
	printf_s("Convert the input string:\n");
	for (j = 1;j <= i - 2;j++)
	{
		color[j]=toupper(color[j]);
		putchar(color[j]);
	}
	printf_s("\n");
	system("pause");
}
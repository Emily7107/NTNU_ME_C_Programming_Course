#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Menu.h"
#include "Advance.h"


void Advance()
{
	int exit_flag;
	while(1)
	{
		exit_flag = 0;
		switch(AdvanceMenu())
		{
			case 0:
				exit_flag = 1;
				break;
			case 1:
				Mid5();
				break;
			case 2:
				Mid6();
				break;
			case 3:
				Mid7();
				break;
			default:
				printf("輸入錯誤\n");
				break;
		}
		if (1 == exit_flag)
		{
			printf("回主選單\n");
			break;
		}
		system("pause");
	}
}


void Mid5()
{
	int m,n;
	printf("**********第五題***********\n");
	printf("*        排列組合         *\n");
	while (1)
	{
		printf("請輸入m,n: ");
		if (scanf_s("%d %d",&m,&n)==EOF)
			break;
		printf("C(%d,%d)=%d\n",m,n,Combination(m,n));
	}
}

int Combination(int m,int n)
{
	double c=1;
	int i;
	if (n>m/2)
		n=m-n;
	for (i=1;i<=n;i++)
	{
		c*=((double)(m-i+1)/i);
	}
	return (int)c;
}
void Mid6()
{
	int year;
	printf("**********第六題*************\n");
	printf("*	檢查某年是閏年或平年  ***\n");
	while (1)
	{
		printf("請輸入年份 (1~3000): ");
		if (scanf_s("%d",&year)==EOF)
			break;
		if (year<0 || year >3000)
			printf("年份必須介於 1~3000之間\n");
		else
		{
			if(isLeap(year))
				printf("西元%8d年為閏年\n",year);
			else
				printf("西元%8d年為平年\n",year);
		}
	}
}
int isLeap(int year)
{
	int i=0;
	if((year%4!=0) ||((year%100)==0 && (year%400)!=0))
		return 0;  
	else
		return 1;
}


void Mid7()
{
	int num,divisor;
	printf("**********第七題*************\n");
	printf("*	某數的質因數分解      ***\n");
	while (1)
	{
		printf("請輸入一個整數: ");
		if (scanf_s("%d",&num)==EOF)
			break;
		divisor=2;
		while(num >= divisor)
		{
			if(isPrime(divisor))
			{
				while(num%divisor==0)
				{
					num/=divisor;
					printf("%8d",divisor);
				}
			}
			divisor++;
		}
		printf("\n");
	}
}
int isPrime(int num)
{
	int i;
	if(num==2 || num==3)
		return 1;
	else
	{
		for (i=2;i*i<=num;i++)
		{
			if(num%i==0)
				return 0;
		}
		return 1;
	}
}

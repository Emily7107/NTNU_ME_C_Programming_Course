#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "midFunction.h"
int mainMenu()
{
	int select;
	system("cls");
	printf("=====Menu For 105 MidExam======\n");
	printf("1. Fundamentals\n");
	printf("2. Advance\n");
	printf("0. Exit\n");
	printf("Please give your selection:\n");
	scanf_s("%d",&select);
	return select;
}
int FundamentalMenu()
{
	int select;
	system("cls");
	printf("=====Menu For Fundamental Problems======\n");
	printf("1. P1\n");
	printf("2. P2\n");
	printf("3. P3\n");
	printf("4. P4\n");
	printf("0. Main Menu\n");
	printf("Please give your selection:\n");
	scanf_s("%d",&select);
	return select;
}
int AdvanceMenu()
{
	int select;
	system("cls");
	printf("=====Menu For Advance Program======\n");
	printf("1. P5\n");
	printf("2. P6\n");
	printf("0. MainMenu\n");
	printf("Please give your selection:\n");
	scanf_s("%d",&select);
	return select;
}


void FundamentalEntry()
{
	int select;
	while(1)
	{
		select=FundamentalMenu();
		if(select==0)
		{
			printf("Return to MainMenu!\n");
			system("pause");
			break;
		}
		switch(select)
		{
						
			case 1:
				Mid1();
				break;
			case 2:
				Mid2();
				break;
			case 3:
				Mid3();
				break;
			case 4:
				Mid4();
				break;
			default:
				printf("Error Input!\n");
				break;
		}
		system("pause");
	}
}
void AdvanceEntry()
{
	int select;
	while(1)
	{
		select=AdvanceMenu();
		if(select==0)
		{
			printf("Return to MainMenu\n");
			system("pause");
			break;
		}
		switch(select)
		{
						
			case 1:
				Mid5();
				break;
			case 2:
				Mid6();
				break;

			default:
				printf("Error Input\n");
				break;
		}
		system("pause");
	}
}
void Mid1()
{
	double point1x,point1y,point2x,point2y,m,b;
	printf("********** P1 ***********\n");
	printf("*   Line Equation       *\n");
	while (1)
	{
		printf("Please input the coordinate of point 1: ");
		if (scanf_s("%lf %lf",&point1x,&point1y)==EOF)
			break;
		printf("Please input the coordinate of point 2: ");
		if (scanf_s("%lf %lf",&point2x,&point2y)==EOF)
			break;

		if (point1x==point2x)
			printf("x=%.2lf\n",point1x);
		else if(point1y==point2y)
			printf("y=%.2lf\n",point1y);
		else
		{
			m=(point2y-point1y)/(point2x-point1x);
			b=point1y-m*point1x;
			printf("y = %.2lf*x+%.2lf\n",m,b);
		}
	}
}
void Mid2()
{
	int num;
	printf("**********  P2 ***********\n");
	printf("*   Reverse a number	 *\n");
	while (1)
	{
		printf("Please input an integer (<= 10 digits): ");
		if (scanf_s("%d",&num)==EOF)
			break;
		if (num%10==0)
			printf("Error input!\n");
		else
			printf("Reverse of %d is %d\n",num,reverse(num,0));
	}
}
int reverse(int num, int rev)
{
	if (num==0)
		return rev;
	else
		return reverse(num/10,rev*10+num%10);
}
void Mid3()
{
	int noDisk;
	printf("************P3*****************\n");
	printf("*       Tower of Hanoi        *\n");
	while (1)
	{
		printf("Please input disk num (1<=n<=4): ");
		if(scanf_s("%d",&noDisk)==EOF)
			break;
		if(noDisk < 1 || noDisk >4)
		{
			printf("Error input!\n");
			continue;
		}
		printf("***S=Source, A=Auxiliary, T=Target***\n"); 
		TOH(noDisk,'S','T','A');
	}
}


void TOH(int n,char source,char target,char temp)
{
	if(n>0)
	{
		TOH(n-1,source,temp,target);
		printf("Disk%d\t%c ==> %c\t\t\n",n,source,target);
		TOH(n-1,temp,target,source);
	}
}

void Mid4()
{
	int side;
	printf("**********P4***********\n");
	while (1)
	{
		printf("Please input side length (<10): ");
		if (scanf_s("%d",&side)==EOF)
			break;
		else
			Heart(side);
	}
}
void Heart(int side)
{	
	int i,j;
	for (i=1;i<=side;i++)
	{
		for(j=1;j<=side;j++)
		{
			if((i==j) || ((i+j)==(side+1)))
				printf(" %c",3);
			else
				printf(" %c",4);
		}
		printf("\n");
	}
}

void Mid5()
{
	int m,i,j;
	printf("*************** P5 ****************\n");
	printf("*  Table of Combinations C(m,n)   *\n");
	while (1)
	{
		printf("Please input m (< 10): ");
		if (scanf_s("%d",&m)==EOF)
			break;
		if (m>=10)
		{
			printf("Error Input!\n");
			continue;
		}
		for (i=1;i<=m;i++)
		{
			for(j=0;j<=i;j++)
				printf("C%d%d=%d\t",i,j,Combination(i,j));
			printf("\n");
		}
	}
}

int Combination(int m,int n)
{
	double c=1;
	int i;
	if (n==0)
		return 1;
	if (n==1)
		return m;
	if (n>m/2)
		n=m-n;
	for (i=1;i<=n;i++)
	{
		c*=(double)(m-i+1)/i;
	}
	return (int)c;
}


void Mid6()
{
	int num,divisor;
	printf("********** P6 *************\n");
	printf("** prime factorization  ***\n");
	while (1)
	{
		printf("Please input a integer number: ");
		if (scanf_s("%d",&num)==EOF)
			break;
		divisor=num;
		printf("%8d =",num);
		while(num >1)
		{
			if(isPrime(divisor))
			{
				while(num%divisor==0)
				{
					num/=divisor;
					if(num!=1)
						printf("%d* ",divisor);
					else
						printf("%d",divisor);
				}
			}
			
			divisor--;
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

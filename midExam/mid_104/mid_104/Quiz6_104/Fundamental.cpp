#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Menu.h"
#include "Fundamental.h"

void Fundamental()
{
	int exit_flag;
	while (1)
	{
		exit_flag = 0;
		switch (FundamentalMenu())
		{
			case 0:
				exit_flag = 1;
				break;
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
				printf("��J���~\n");
				break;
		}
		if (1==exit_flag)
		{
			printf("�^�D���\n");
			break;
		}
		system("pause");
	}
}
void Mid1()
{
	double a, b, c, delta;
	printf("**********�Ĥ@�D***********\n");
	printf("*    �D ax^2+bx+c=0 ����  *\n");
	while (1)
	{
		printf("�п�Ja, b, c: ");
		if (scanf_s("%lf %lf %lf", &a, &b, &c) == EOF)
			break;
		if (a == 0)
		{
			printf("x^2���Y�� a ���ର0\n");
			continue;
		}
		delta = b*b - 4 * a*c;
		if (delta>0)
			printf("x=%lf or %lf\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
		else if (delta == 0)
			printf("x=%lf (����)\n", -b / (2 * a));
		else
		{
			printf("x=%lf+%lfi or %lf%lfi\n", -b / (2 * a), sqrt(-delta) / (2 * a), -b / (2 * a), -sqrt(-delta) / (2 * a));
		}
	}
}
void Mid2()
{
	int num;
	printf("**********�ĤG�D***********\n");
	printf("*		 �Ʀr����		 *\n");
	while (1)
	{
		printf("�п�J�@�Ӿ�� (<= 10 ���): ");
		if (scanf_s("%d", &num) == EOF)
			break;
		printf("Reverse of %d is %d\n", num, reverse(num, 0));
	}
}
int reverse(int num, int rev)
{
	if (num == 0)
		return rev;
	else
		return reverse(num / 10, rev * 10 + num % 10);
}
void Mid3()
{
	int score;
	printf("**********�ĥ|�D***********\n");
	printf("*       �����൥��        *\n");
	while (1)
	{
		printf("�п�J����: ");
		if (scanf_s("%d", &score) == EOF)
			break;
		if (score < 0 || score >100)
		{
			printf("���ƥ������� 0 ~100 ����\n");
			continue;
		}
		printf("%d�������Ĭ�%c\n", score, scoreToGrade(score));
	}
}
char scoreToGrade(int score)
{
	char grade;
	score = score / 10;
	switch (score)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'E';
		break;
	}
	return grade;
}

void Mid4()
{
	int outer, inner;
	printf("**********�ĥ|�D***********\n");
	while (1)
	{
		printf("�п�J�~��Τ������ (<10): ");
		if (scanf_s("%d %d", &outer, &inner) == EOF)
			break;
		if (inner > outer)
		{
			printf("������ץ����p��~�����\n");
			if ((inner + outer) % 2 == 1)
				printf("������׻P�~����ץ����P���_�ƩΦP������\n");
		}
		else
		{
			if ((inner + outer) % 2 == 1)
				printf("������׻P�~����ץ����P���_�ƩΦP������\n");
			else
				Heart(outer, inner);
		}
	}
}
void Heart(int outer, int inner)
{
	int start, end, i, j;
	start = 1 + (outer - inner) / 2;
	end = (outer + inner) / 2;

	for (i = 1; i <= outer; i++)
	{
		for (j = 1; j <= outer; j++)
		{
			if ((i >= start && i <= end) && (j >= start && j <= end))
				printf("  ");
			else
				printf(" %c", '*');
		}
		printf("\n");
	}
}
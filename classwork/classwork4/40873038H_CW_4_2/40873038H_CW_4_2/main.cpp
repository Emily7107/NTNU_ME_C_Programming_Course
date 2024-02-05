#include<stdio.h>
#include<stdlib.h>
bool isLeap(int);
int noofLeap(int,int);
int main()
{
	int start, end;
	do {
		printf_s("��J�_�l�~���P�����~��<Ctrl Z �����{��:\n");
		if (scanf_s("%d %d", &start, &end) == EOF)
			break;
		printf_s("%d~%d�@��%d�Ӷ|�~\n", start, end, noofLeap(start, end));
	} while (1);
	system("pause");
	return 0;
}
bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}
int noofLeap(int start, int end)
{
	int i, count(0);
	for (i = start;i <= end;i++)
	{
		if (isLeap(i))
			count++;
	}
	return count;
}
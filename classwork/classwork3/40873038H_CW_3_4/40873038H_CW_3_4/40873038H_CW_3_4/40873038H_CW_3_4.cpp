#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int innumber, i3;
	printf_s("�п�J�Q��ƥH�����Ʀr:");
	scanf_s("%d", &innumber);
	i3 = 0;
	while (i3 <= 10)
	{
		if (innumber > 0)
		{
			printf_s("%d", innumber % 10);
			innumber /= 10;
			i3++;
		}
		else
			break;
	}
	printf_s("\n");
	system("pause");
}
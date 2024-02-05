#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int innumber, i3;
	printf_s("請輸入十位數以內的數字:");
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
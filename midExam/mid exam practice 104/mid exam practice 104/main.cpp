#include<stdio.h>
#include<stdlib.h>
#include"midExam.h"
#include"menu.h"
int main()
{
	int k1,k2=0;
	while (1)
	{
		k1 = 0;
		switch (list())
		{
		case 1:
			while (1)
			{
				k2 = 0;
				switch (list2())
				{
				case 1:
					test1();
					system("cls");
					break;
				case 2:
					test2();
					system("cls");
					break;
				case 3:
					test3();
					system("cls");
					break;
				case 4:
					test4();
					system("cls");
					break;
				case 0:
					k2 = 1;
					break;
				}
				if (k2== 1)
					break;
			}
			break;
		case 2:
			while (1)
			{
				k2 = 0;
				switch (list3())
				{
				case 1:
					test5();
					system("cls");
					break;
				case 2:
					test6();
					system("cls");
					break;
				case 3:
					test7();
					system("cls");
					break;
				case 0:
					k2 = 1;
					break;
				}
				if (k2 == 1)
					break;
			}
			break;
		case 0:
			k1 = 1;
		}
		if (k1 == 1)
			break;
	}
	printf_s("µ²§ôµ{¦¡\n");
	system("pause");
}
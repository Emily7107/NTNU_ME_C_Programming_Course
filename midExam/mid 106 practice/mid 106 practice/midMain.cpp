#include<stdio.h>
#include<stdlib.h>
#include"Menu.h"
#include"Advance.h"
#include"Fundamental.h"
int main()
{
	int k1, k2;
	while (1)
	{
		k1 = 0;
		switch (menu())
		{
		case 1:
			while (1)
			{
				k2 = 0;
				switch (menu2())
				{
				case 1:
					p1();
					break;
				case 2:
					p2();
					break;
				case 3:
					p3();
					break;
				case 4:
					p4();
					break;
				case 0:
					k2 = 1;
					break;
				}
				if (k2 == 1)
					break;
			}
			break;
		case 2:
			while (1)
			{
				k2 = 0;
				switch (menu3())
				{
				case 1:
					p5();
					break;
				case 2:
					p6();
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
			break;
		}
		if (k1 == 1)
			break;
	}
	printf_s("µ{¦¡µ²§ô\n");
	system("pause");
}
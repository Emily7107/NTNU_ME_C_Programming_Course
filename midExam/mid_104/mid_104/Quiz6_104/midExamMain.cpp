#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Advance.h"
#include "Fundamental.h"

int main()
{
	int exit_flag;
	while(1)
	{
		exit_flag = 0;
		switch(mainMenu())
		{
			case 0:
				exit_flag = 1;
				break;
			case 1:
				Fundamental();
				break;
			case 2:
				Advance();
				break;
			default:
				printf("��J���~\n");
				system("pause");
				break;
		}
		if (1 == exit_flag)
		{ 
			printf("�����{��\n");
			break;
		}
	}
	system("pause");
}
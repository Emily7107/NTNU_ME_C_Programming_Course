#include <stdio.h>
#include <stdlib.h>
#include "midFunction.h"

int main()
{
	int select_main;
	while(1)
	{
		select_main=mainMenu();
		if(select_main==0)
		{
			printf("�����{��\n");
			break;
		}
		switch(select_main)
		{
			case 1:
				FundamentalEntry();
				break;
			case 2:
				AdvanceEntry();
				break;
			default:
				printf("��J���~\n");
				system("pause");
				break;
		}
	}
	system("pause");
}
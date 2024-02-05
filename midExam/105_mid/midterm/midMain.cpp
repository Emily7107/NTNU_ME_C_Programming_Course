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
			printf("結束程式\n");
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
				printf("輸入錯誤\n");
				system("pause");
				break;
		}
	}
	system("pause");
}
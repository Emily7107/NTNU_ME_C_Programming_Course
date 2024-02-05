#include <stdio.h>
#include <stdlib.h>
#include "final_func.h"

int main()
{
	//function pointer array
	void (*mainMenuFuncs[6])()={NULL,openFileAndShowData,dataOperation,sortOperation,writeFiles,clearScreen};
	int select;

	while(1)
	{
		mainMenu();
		scanf_s("%d",&select);
		if (select==0)
			break;
		else if((select>=1) && (select <=5))
			mainMenuFuncs[select](); //call function
		else
			printf("Wrong Selection!\n");
	}
	system("pause");
	return 0;
}
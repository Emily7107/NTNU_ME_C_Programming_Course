#include <stdio.h>
#include <stdlib.h>
#include "final_func.h"

int main()
{
	int select;

	while(1)
	{
		mainMenu();
		scanf_s("%d",&select);
		if(0==select)
			break;
		switch(select)
		{
		case 1:
			openFileAndShowData();
			break;
		case 2:
			dataOperation();
			break;
		case 3:
			sortOperation();
			break;
		case 4:
			writeFiles();
			break;
		case 5:
			system("CLS");
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
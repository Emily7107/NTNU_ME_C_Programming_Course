#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main()
{
	int select;
	while (1)
	{
		Mainmenu();
		scanf_s("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			opendfileandshowdata();
			break;
		case 2:
			dataoperation();
			break;
		case 3:
			sortoperation();
			break;
		case 4:
			writedata();
			break;
		case 5:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;//¥[return 0;
}
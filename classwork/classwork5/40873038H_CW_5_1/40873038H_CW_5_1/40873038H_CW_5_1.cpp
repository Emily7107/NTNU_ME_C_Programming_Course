#include<stdio.h>
#include<stdlib.h>
int main()
{
	int select;
	do {
		printf_s("=====主選單=====\n");
		printf_s("11. ClassWork1_1\n");
		printf_s("12. ClassWork1_2\n");
		printf_s("13. ClassWork1_3\n");
		printf_s("14. ClassWork1_4\n");
		printf_s("15. ClassWork1_5\n");
		printf_s("21. ClassWork2_1\n");
		printf_s("22. ClassWork2_2\n");
		printf_s("23. ClassWork2_3\n");
		printf_s("24. ClassWork2_4\n");
		printf_s("31. ClassWork3_1\n");
		printf_s("32. ClassWork3_2\n");
		printf_s("33. ClassWork3_3\n");
		printf_s("34. ClassWork3_4\n");
		printf_s("35. ClassWork3_5\n");
		printf_s("0. Exit\n");
		printf_s("=================\n");
		printf_s("請輸入你的選擇:\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 11:
			printf_s("執行classwork1_1\n");
			break;
		case 12:
			printf_s("執行classwork1_2\n");
			break;
		case 13:
			printf_s("執行classwork1_3\n");
			break;
		case 14:
			printf_s("執行classwork1_4\n");
			break;
		case 15:
			printf_s("執行classwork1_5\n");
			break;
		case 21:
			printf_s("執行classwork2_1\n");
			break;
		case 22:
			printf_s("執行classwork2_2\n");
			break;
		case 23:
			printf_s("執行classwork2_3\n");
			break;
		case 24:
			printf_s("執行classwork2_4\n");
			break;
		case 31:
			printf_s("執行classwork3_1\n");
			break;
		case 32:
			printf_s("執行classwork3_2\n");
			break;
		case 33:
			printf_s("執行classwork3_3\n");
			break;
		case 34:
			printf_s("執行classwork3_4\n");
			break;
		case 35:
			printf_s("執行classwork3_5\n");
			break;
		case 0:
			printf_s("結束程式\n");
			break;
		}
		printf_s("輸入錯誤\n");
	   system("pause");	
	} while (1);
	
}

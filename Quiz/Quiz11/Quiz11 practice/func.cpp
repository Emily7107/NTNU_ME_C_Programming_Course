#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.h"

char objecttype[NO_OF_OBJECT + 1][20] = { "Unknown","Ball","Cube","Pyramid","Cylinder" };
char materialtype[NO_OF_MATERIAL + 1][20] = { "Unknown","Iron","Aluminum","Lead" };
char errtype[NO_OF_ERRTYPE + 1][20] = { "Normal","Err_object","Err_material","Err_para1","Err_para2"};
double density[NO_OF_MATERIAL + 1] = { 0,7.87,2.7,11.3 };
char filePath[6][128] = { "WrongPath",FILE_TXT1,FILE_TXT2,FILE_TXT3,FILE_TXT4,FILE_TXT5 };

O_ST data[MAXSIZE];
int size = 0;

void mainmanu()
{
	printf_s("============Main Menu============\n");
	printf_s("0. Exit\n");
	printf_s("1. open file and show data\n");
	printf_s("2. data operations\n");
	printf_s("3. sort operations\n");
	printf_s("4. save data to file\n");
	printf_s("5. clear screen\n");
	printf_s("================================\n");
	printf_s("Please select an option:");
}
void operationmanu()
{
	printf_s("============File Operation Menu============\n");
	printf_s("0. Main Menu\n");
	printf_s("1. print data\n");
	printf_s("2. Append data\n");
	printf_s("3. Update data\n");
	printf_s("4. Delete data\n");
	printf_s("==========================================\n");
	printf_s("Please select an option:");
}
void sortmanu()
{
	printf_s("============Sort Operatin Menu============\n");
	printf_s("0. Main Menu\n");
	printf_s("1. Sort by ID\n");
	printf_s("2. Sort by Object type\n");
	printf_s("3. Sort by Material\n");
	printf_s("4. Sort by Volume\n");
	printf_s("5. Sort by Weight\n");
	printf_s("=========================================\n");
	printf_s("Please select an option:");
}

void openfileandshowdata()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp,FILE_ORIGIN,"r");
	if (err != 0)
	{
		printf_s("File could not be open!\n");
		return;
	}
	else
	{
		size = readData(data, fp);
		printdata(data, size);
		fclose(fp);
	}
}
int readData(O_ST obj[], FILE* fp)
{
	int i=0;
	char temp[20];
	while (!feof(fp))
	{
		fscanf_s(fp, "%d", &(obj[i].id));
		if (obj[i].id == 0)
			break;
		fscanf_s(fp, "%s", temp,20);
		obj[i].otype=strtobjtype(temp);
		fscanf_s(fp, "%s", temp, 20);
		obj[i].mtype= strtomaterialtype(temp);
		fscanf_s(fp, "%f", &(obj[i].para1));
		fscanf_s(fp, "%f",&(obj[i].para2));
		checkdata(obj[i]);
		i++;
	}
	return i;
}
O_TYPE strtobjtype(char str[])
{
	if (strcmp(str, "Ball") == 0)
		return BALL;
	else if (strcmp(str, "Cube") == 0)
		return CUBE;
	else if (strcmp(str, "Pyramid") == 0)
		return PYRAMID;
	else if (strcmp(str, "Cylinder") == 0)
		return CYLINDER;
	else
		return O_UNKNOWN;
}
M_TYPE strtomaterialtype(char str[])
{
	if (strcmp(str, "Iron") == 0)
		return IRON;
	else if (strcmp(str, "Aluminum") == 0)
		return ALUMINUM;
	else if (strcmp(str, "Lead") == 0)
		return LEAD;
	else
		return M_UNKNOWN;
}
void checkdata(O_ST &obj)
{
	if (obj.otype == 0)
		obj.etype = ERR_OBJ;
	else if (obj.mtype == 0)
		obj.etype = ERR_MAT;
	else if (obj.para1 < 0)
		obj.etype = ERR_PARAL1;
	else if (obj.para2 < 0)
		obj.etype = ERR_PARAL2;
	else
		obj.etype = NORMAL;
}
void printdata(O_ST obj[], int size)
{
	int i;
	printf_s("**************************Display Data**************************\n");
	printf_s("%4s %10s %10s %9s %9s %9s %9s %9s\n", "ID", "ObjectType", "Material", "PARA1", "PARA2", "Volume", "Weight", "Error");
	for (i = 0;i < size;i++)
		printf_s("%4d %10s %10s %9.3f %9.3f %9.3f %9.3f %9s\n", obj[i].id, objecttype[obj[i].otype], materialtype[obj[i].mtype], obj[i].para1, obj[i].para2, volume(obj[i]),weight(obj[i]), errtype[obj[i].etype]);
	printf_s("****************************************************************\n");
}
double volume(O_ST obj)
{
	double v;
	if ((obj.etype == ERR_OBJ) || (obj.etype == ERR_PARAL1) || (obj.etype == ERR_PARAL2))
		return 0;
	switch (obj.otype)
	{
	case BALL:
		v = 4.0 / 3 * PI * (obj.para1) * (obj.para1) * (obj.para1);
		break;
	case CUBE:
		v = (obj.para1) * (obj.para1) * (obj.para1);
		break;
	case PYRAMID:
		v = 1.0 / 3 * (obj.para1) * (obj.para1) * (obj.para2);
		break;
	case CYLINDER:
		v = PI * (obj.para1) * (obj.para1) * (obj.para2);
		break;
	default:
		v = 0;
		break;
	}
	return v;
}
double weight(O_ST obj)
{
	if (obj.etype == ERR_MAT)
		return 0;
	else
		return density[obj.mtype] * volume(obj);
}

void dataoperation()
{
	int select,id;
	if (size == 0)
	{
		printf_s("No data!!! Please read data from file\n");
			return;
	}
	while (1)
	{
		operationmanu();
		scanf_s("%d", &select);
		if (select == 0)
		{
			printf_s("Return to main menu\n");
			break;
		}
		switch (select)
		{
		case SHOW:
			printdata(data, size);
			break;
		case APPEND:
			appenddata(data, size);
			printdata(data, size);
			break;
		case UPDATE:
			printf_s("Please enter an ID:");
			scanf_s("%d", &id);
			updatedata(data, size, id);
			printdata(data, size);
			break;
		case DELET:
			printf_s("Please enter an ID:");
			scanf_s("%d", &id);
			deletdata(data, size, id);
			printdata(data, size);
			break;
		default:
			break;
		}
	}
}
int searchdata(O_ST obj[], int size, int id)
{
	int index;
	for (index = 0;index < size;index++)
	{
		if (obj[index].id == id)
			return index;
	}
	return -1;
}
void appenddata(O_ST obj[], int& size)
{
	int id, index;
	printf_s("Please input an ID\n");
	printf_s("ID:");
	scanf_s("%d", &id);
	index = searchdata(obj, size, id);
	if (index != -1)
	{
		printf_s("ID exist!\n");
		return;
	}
	else
	{
		obj[size].id = id;
		printf_s("Object type:1.Ball 2.Cube 3.Pyramid 4.Cylinder\n");
		scanf_s("%d", &obj[size].otype);
		printf_s("Material type:1.Iron 2.Aluminum 3.Lead\n");
		scanf_s("%d", &obj[size].mtype);
		printf_s("Para1:");
		scanf_s("%f", &obj[size].para1);
		if (obj[size].otype == PYRAMID || obj[size].otype == CYLINDER)
		{
			printf_s("Para2:");
			scanf_s("%f", &obj[size].para2);
		}
		else
			obj[size].para2 = 0;

		checkdata(obj[size]);
		size++;
	}
}
void updatedata(O_ST obj[], int size, int id)
{
	int index;
	index = searchdata(obj, size, id);
	if (index == -1)
	{
		printf_s("ID dosen't exist!\n");
		return;
	}
	else
	{
		printf("Please update the properties of object %d:\n", obj[index].id);
		printf_s("Object type:1.Ball 2.Cube 3.Pyramid 4.Cylinder\n");
		scanf_s("%d", &obj[index].otype);
		printf_s("Material type:1.Iron 2.Aluminum 3.Lead\n");
		scanf_s("%d", &obj[index].mtype);
		printf_s("Para1:");
		scanf_s("%f", &obj[index].para1);
		if (obj[index].otype == PYRAMID || obj[index].otype == CYLINDER)
		{
			printf_s("Para2:");
			scanf_s("%f", &obj[index].para2);
		}
		else
			obj[index].para2 = 0;
		checkdata(obj[size]);
	}
}
void deletdata(O_ST obj[], int& size, int id)
{
	int i, index;
	index = searchdata(obj, size, id);
	if (index == -1)
	{
		printf_s("ID dosen't exist!\n");
		return;
	}
	else
	{
		for (i = index;i < size;i++)
		{
			obj[i] = obj[i + 1];
		}
		size--;
	}
}
void sortoperation()
{
	int select;
	if (size == 0)
	{
		printf("No data!!! Please read data from file\n");
		return;
	}
	while (1)
	{
		sortmanu();
		scanf_s("%d", &select);
		if (select == 0)
		{
			printf_s("Data not exist! Please open file\n");
			return;
		}
		sortdata(data, size, (S_METHOD)select);
		printdata(data, size);
	}
}
void swap(O_ST& obj1, O_ST& obj2)
{
	O_ST temp;
	temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}
int compare(O_ST obj1, O_ST obj2, S_METHOD method)
{
	switch (method)
	{
	case SOR_BY_ID:
		if (obj1.id < obj2.id)
			return 1;
		break;
	case SOR_BY_OBJECT:
		if (obj1.otype < obj2.otype)
			return 1;
		break;
	case SOR_BY_MATERIAL:
		if (obj1.mtype < obj2.mtype)
			return 1;
		break;
	case SOR_BY_VOLUME:
		if (volume(obj1) < volume(obj2))
			return 1;
		break;
	case SOR_BY_WEIGHT:
		if (weight(obj1) < weight(obj2))
			return 1;
		break;
	}
	return 0;
}
void sortdata(O_ST obj[], int size, S_METHOD method)
{
	int pass, i;
	for (pass = 1;pass < size;pass++)
	{
		for (i = 0;i < pass;i++)
		{
			if (1 == compare(obj[i], obj[i + 1], method))
				swap(obj[i], obj[i + 1]);
		}
	}
}
void writedata()
{
	FILE* wfp;
	errno_t err;
	int i;
	if (size == 0)
	{
		printf_s("No data! Please read data from file!\n");
		return;
	}
	for (i = 0; i <= 5; i++)
	{
		sortdata(data, size, (S_METHOD)i);
		err = fopen_s(&wfp, filePath[(S_METHOD)i], "w");
		if (err != 0)
		{
			printf_s("File could not be open!\n");
			return;
		}
		else
		{
			writeDataToSingleFile(data, size, wfp);
			fclose(wfp);
		}
	}
}
void writeDataToSingleFile(O_ST obj[], int& size, FILE* fp)
{
	int i;
	fprintf_s(fp, "%4s %10s %10s %9s %9s %9s %9s\n", "ID", "ObjectType","Material", "Para1", "Para2", "Volume", "Weight");
	for (i = 0;i < size;i++)
	{
		fprintf_s(fp, "%4d %10s %10s %9.3f %9.3f %9.3f %9.3f\n", obj[i].id, objecttype[obj[i].otype], materialtype[obj[i].mtype], obj[i].para1, obj[i].para2, volume(obj[i]), weight(obj[i]));
	}
}
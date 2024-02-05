#include<stdio.h>
#include<string.h>
#include"func.h"

char object[NO_OF_OBJECT + 1][20] = { "Unknown","Ball","Cube","Pyramid","Cylinder" };
char material[NO_OF_MATERIAL + 1][20] = { "Unknown","Iron","Aluminum","Lead" };
char errtype[NO_OF_ERRTYPE + 1][20] = { "Normal","Err object","Err material","Err Para1","Err Para2" };
double density[NO_OF_MATERIAL + 1] = { 0,11.3,2.7,7.87 };
char filepath[6][128] = { "Wrong path",TXT_FILE1,TXT_FILE2,TXT_FILE3,TXT_FILE4,TXT_FILE5 };

O_ST data[MAXSIZE];
int size = 0;

void mainMenu()
{
	printf_s("==========Main Menu==============\n");
	printf_s("0. Exit\n");
	printf_s("1. Open file and show data\n");
	printf_s("2. Data operations\n");
	printf_s("3. Sort operations\n");
	printf_s("4. Save Data to file\n");
	printf_s("5. Clear screen\n");
	printf_s("=================================\n");
	printf_s("Please select an option:");
}
void operationMenu()
{
	printf_s("==========File Operation Menu==============\n");
	printf_s("0. Main menu\n");
	printf_s("1. Print data\n");
	printf_s("2. Append data\n");
	printf_s("3. Update data\n");
	printf_s("4. Delete data\n");
	printf_s("=================================\n");
	printf_s("Please select an option:");
}
void sorMenu()
{
	printf_s("==========File Operation Menu==============\n");
	printf_s("0. Main menu\n");
	printf_s("1. Sort by ID\n");
	printf_s("2. Sort by Object type\n");
	printf_s("3. Sort by Material\n");
	printf_s("4. Sort by volume\n");
	printf_s("5. Sort by Weight\n");
	printf_s("=================================\n");
	printf_s("Please select an option:");
}

void openfileandshowdata()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, ORIGINAL_FILE, "r");
	if (err != 0)
	{
		printf_s("File can't be open!\n");
		return;
	}
	else
	{
		size=readData(data,fp);
		printdata(data,size);
		fclose(fp);
	}
}
int readData(O_ST* obj, FILE* fp)
{
	int i=0;
	char temp[20];
	while (!feof(fp))
	{
		fscanf_s(fp, "%d", &((obj + i)->id));
		if ((obj + i)->id == 0)
			break;
		fscanf_s(fp, "%s", temp,20);
		(obj+i)->otype= strtoObject(temp);
		fscanf_s(fp, "%s", temp, 20);
		(obj + i)->mtype = strtoMaterial(temp);
		fscanf_s(fp, "%f", &((obj + i)->para1));
		fscanf_s(fp, "%f", &((obj + i)->para2));
		chectdata(obj+i);
		i++;
	}
	return i;
}
O_TYPE strtoObject(char str[])
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
M_TYPE strtoMaterial(char str[])
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
void chectdata(O_ST* obj)
{
	if (obj->otype == 0)
		obj->etype = ERR_OBJ;
	else if (obj->mtype == 0)
		obj->etype = ERR_MATERIAL;
	else if (obj->para1 < 0)
		obj->etype = ERR_PARA1;
	else if (obj->para2 < 0 && (obj->otype != BALL) && (obj->otype != CUBE))
		obj->etype = ERR_PARA2;
	else
		obj->etype = NORMAL;
}
void printdata(const O_ST* obj, int size)
{
	int i;
	printf_s("*******************************Display Data************************************\n");
	printf_s("%4s %10s %10s %9s %9s %9s %9s %9s\n", "ID", "Objtype", "Material", "PARA1", "PARA2", "Voiume", "Weight", "Error");
	for (i=0;i<size;i++)
	{
		printf_s("%4d %10s %10s %9.3f %9.3f %9.3lf %9.3lf %9s\n",(obj+i)->id,object[(obj+i)->otype], material[(obj + i)->mtype],((obj + i)->para1), (obj + i)->para2,volume(obj+i),weight(obj+i), errtype[(obj + i)->etype]);
	}
	printf_s("********************************************************************************\n");
}
double volume(const O_ST* obj)
{
	double v;
	if (obj->etype == ERR_OBJ || obj->etype == ERR_PARA1 || obj->etype == ERR_PARA2)
		return 0;
	switch (obj->otype)
	{
	case BALL:
		v = 4.0 / 3 * PI * (obj->para1) * (obj->para1) * (obj->para1);
		break;
	case CUBE:
		v = (double)(obj->para1) * (obj->para1) * (obj->para1);
		break;
	case PYRAMID:
		v = 1.0 / 3 * (obj->para1) * (obj->para1) * (obj->para2);
		break;
	case CYLINDER:
		v = PI * (obj->para1) * (obj->para1) * (obj->para2);
		break;
	default:
		v = 0;
		break;
	}
	return v;
}
double weight(const O_ST* obj)
{
	if (obj->etype == ERR_MATERIAL)
		return 0;
	else
		return volume(obj) * density[obj->mtype];
}

void dataoperation()
{
	int select, id;
	if (size == 0)
	{
		printf_s("No data!!! Please read data from file\n");
		return;
	}
	while (1)
	{
		operationMenu();
		scanf_s("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case SHOW:
			printdata(data, size);
			break;
		case APPEND:
			appendata(data, &size);
			printdata(data, size);
			break;
		case UPDATE:
			printf_s("Please enter an ID:\n");
			scanf_s("%d", &id);
			updatadata(data, size, id);
			printdata(data, size);
			break;
		case DELETE:
			printf_s("Please enter an ID:\n");
			scanf_s("%d", &id);
			deletedata(data, &size, id);
			printdata(data, size);
			break;
		default:
			break;
		}
	}
}
int search(O_ST obj[],int size,int id)
{
	int index;
	for (index = 0;index < size;index++)
	{
		if (obj[index].id == id)
		{
			return index;
		}
		return -1;
	}
}
void appendata(O_ST* obj, int* size)
{
	int id, index;
	printf_s("Enter an ID:");
	scanf_s("%d", &id);
	index = search(obj, *size, id);
	if (index != -1)
	{
		printf_s("ID exist!\n");
		return;
	}
	else
	{
		(obj + (*size))->id = id;
		printf_s("Object type: 1.Ball; 2.Cube; 3.Pyramid; 4.Cylinder\n");
		scanf_s("%d", &((obj + (*size))->otype));
		printf_s("Material type: 1.Iron; 2.Aluminum; 3.Lead");
		scanf_s("%d", &((obj + (*size))->mtype));
		printf_s("Para1:");
		scanf_s("%f", &((obj + (*size))->para1));
		if ((obj + (*size))->otype == PYRAMID || (obj + (*size))->otype == CYLINDER)
		{
			printf_s("Para2:");
			scanf_s("%f", &((obj + (*size))->para2));
		}
		else
			(obj + (*size))->para2 = 0;
		chectdata(obj + (*size));
		(*size)++;
	}
}
void updatadata(O_ST* obj, int size, int id)
{
	int index;
	index= search(obj, size, id);
	if (index == -1)
	{
		printf_s("ID dosen't exist!\n");
		return;
	}
	else
	{
		(obj + index)->id = id;
		printf_s("Object type: 1.Ball; 2.Cube; 3.Pyramid; 4.Cylinder\n");
		scanf_s("%d", &((obj + index)->otype));
		printf_s("Material type: 1.Iron; 2.Aluminum; 3.Lead");
		scanf_s("%d", &((obj + index)->mtype));
		printf_s("Para1:");
		scanf_s("%f", &((obj + index)->para1));
		if ((obj + index)->otype == PYRAMID || (obj + index)->otype == CYLINDER)
		{
			printf_s("Para2:");
			scanf_s("%f", &((obj + index)->para2));
		}
		else
			(obj + index)->para2 = 0;
		chectdata(obj + index);
	}
}
void deletedata(O_ST* obj, int* size, int id)
{
	int index,i;
	index = search(obj, *size, id);
	if (index == -1)
	{
		printf_s("ID dosen't exist!\n");
		return;
	}
	else
	{
		for (i = 0;i < *size;i++)
		{
			*(obj + i) = *(obj + i + 1);
		}
	}
}
int compare(O_ST* obj1, O_ST* obj2, S_MATHOD method)
{
	switch (method)
	{
	case SOR_BY_ID:
		if (obj1->id < obj2->id)
			return 1;
		break;
	case SOR_BY_OBJECT:
		if (obj1->otype < obj2->otype)
			return 1;
		break;
	case SOR_BY_MATERIAL:
		if (obj1->mtype < obj2->mtype)
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
void sortoperation()
{
	int select;
	if (size == 0)
	{
		printf_s("No data!!! Please read data from file\n");
		return;
	}
	while (1)
	{
		sorMenu();
		scanf_s("%d", &select);
		if (select == 0)
		{
			printf_s("Return Main Menu\n");
			break;
		}
		sortdata(data, size, (S_MATHOD)select);
		printdata(data, size);
	}
}
void sortdata(O_ST* obj, int size, S_MATHOD method)
{
	int pass, i;
	for (pass = 1;pass < size;pass++)
	{
		for (i = 0;i < size - pass;i++)
		{
			if (1 == compare(obj + i, (obj + i + 1),method))
				swap(obj + i, obj + i + 1);
		}
	}
}
void swap(O_ST* obj1, O_ST* obj2)
{
	O_ST temp;
	temp = *obj1;
	*obj1 = *obj2;
	*obj2 = temp;
}

void writedata()
{
	FILE* wfp;
	errno_t err;
	int i;
	if (size == 0)
	{
		printf_s("No data!!! Please read data from file\n");
		return;
	}
	else
	{
		for (i = 1;i <= 5;i++)
		{
			sortdata(data, size, (S_MATHOD)i);
			err = fopen_s(&wfp, filepath[(S_MATHOD)i], "w");
			savedatatosinglefile(data, &size, wfp);
		}
	}
}
void savedatatosinglefile(O_ST* obj, int* size, FILE* fp)
{
	int i;
	fprintf_s(fp,"%4s %10s %10s %9s %9s %9s %9s %9s\n", "ID", "Objtype", "Material", "PARA1", "PARA2", "Voiume", "Weight", "Error");
	for (i = 0;i < *size;i++)
	{
		fprintf_s(fp,"%4d %10s %10s %9.3f %9.3f %9.3lf %9.3lf %9s\n", (obj + i)->id, object[(obj + i)->otype], material[(obj + i)->mtype], ((obj + i)->para1), (obj + i)->para2, volume(obj + i), weight(obj + i), errtype[(obj + i)->etype]);
	}
}
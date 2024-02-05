#include <stdio.h>
#include <string.h>                //�]���ϥΨ�r�����禡 strcmp
#include "final_func.h"
#include <stdlib.h>

//�ŧi�U�ذ}�C
char objType[NO_OF_OBJECT_TYPE+1][20]={"Unknown","Ball","Cube","Pyramid","Cylinder"};      
char materialType[NO_OF_MATERIAL_TYPE+1][20]={"Unknown","Iron","Aluminum","Lead"};
char errorType[NO_OF_ERROR_TYPE+1][20]={"Normal","Err_object","Err_material","Err_para1","Err_para2"};	// #2015
double density[NO_OF_MATERIAL_TYPE+1]={0,7.87, 2.7,11.3};
char filePath[6][128]={"WrongPath",FILE_TXT1,FILE_TXT2,FILE_TXT3,FILE_TXT4,FILE_TXT5};

//���c�}�C���ܼ�, �Ψ��x�s�Ҧ�������
O_ST data[MAXSIZE];
int size=0;   //���󪺭Ӽ�

//�D���
void mainMenu()
{
	printf("=========Main Menu===============\n");
	printf("0. Exit \n");
	printf("1. Open file and Show Data\n");
	printf("2. Data operations\n");
	printf("3. Sort operations\n");
	printf("4. Save Data to file\n");
	printf("5. Clear screen \n");
	printf("==================================\n");
	printf("Please select an option \n");
}

//�ﶵ2 �����
void operationMenu()
{
	printf("=========File Operation Menu===============\n");
	printf("0. Main menu \n");
	printf("1. Print data\n");
	printf("2. Append data\n");
	printf("3. Update data\n");
	printf("4. Delete data\n");
	printf("==================================\n");
	printf("Please select an option \n");
}

//�ﶵ3 �����
void sortMenu()
{
	printf("=========Sort Operation Menu===============\n");
	printf("0. Main menu \n");
	printf("1. Sort by ID\n");
	printf("2. Sort by Object type\n");
	printf("3. Sort by Material\n");
	printf("4. Sort by Volume\n");
	printf("5. Sort by Weight\n");
	printf("==================================\n");
	printf("Please select an option \n");
}

//�ﶵ5 ���{���i�J�I
void clearScreen()
{
	system("CLS");
}
//�ﶵ1 ���{���i�J�I
void openFileAndShowData()
{
	FILE* fp=NULL;
	errno_t err;
	err=fopen_s(&fp,FILE_ORIGIN,"r");  //�}���ɮ�
	if(0!=err)                          
	{
		printf("File could not be opened!\n");
		return;
	}
	else
	{
		size=readData(data,fp);   //Ū���ɮצܵ��c�}�C data ��
		printData(data,size);     //�N���c�}�C�������e�C�L�� console
		fclose(fp);               //�����ɮ�
	}
}


//Ū���ɮפ��e�ñN���G�ഫ�����c�}�C���榡 (�s�W: �T�{��ƬO�_���T)
//�Ѽ� obj �����c�}�C�ܼ�
//     fp  ����Ū�����ɮת��ɮ׫���
//�^�ǭ�   �ɮפ��x�s������Ӽ�
int readData(O_ST* obj, FILE* fp)
{
	int i;
	char temp[20];
	i=0;
	while(!feof(fp))
	{
		fscanf_s(fp,"%d",&((obj+i)->id));
		if((obj+i)->id==0)
			break;
		fscanf_s(fp,"%s",temp,20);
		(obj+i)->otype=strToObjType(temp);           //�N����Ϊ�����ܤ覡 �Ѧr���ഫ�� enum 
		fscanf_s(fp,"%s",temp,20);
		(obj+i)->mtype=strToMaterialType(temp);      //�N������誺��ܤ覡 �Ѧr���ഫ�� enum 
		fscanf_s(fp,"%f",&((obj+i)->para1));
		fscanf_s(fp,"%f",&((obj+i)->para2));
		checkdata(obj+i);		// #2015 �ˬd��J�Ѽ�
		i++;
	}
	return i;    //�^���ɮפ�������Ӽ�
}

//�N����Ϊ�����ܤ覡 �Ѧr���ഫ�� enum 
//��J�Ѽ�:  str ������Ϊ����r���{�覡
//�^�ǭ�:    ����Ϊ���enum��{�覡
O_TYPE strToObjType(char str[])
{
	if(strcmp(str,"Ball")==0)
		return BALL;
	else if (strcmp(str,"Cube")==0)
		return CUBE;
	else if (strcmp(str,"Pyramid")==0)
		return PYRAMID;
	else if (strcmp(str,"Cylinder")==0)
		return CYLINDER;
	else
		return O_UNKNOWN;
}


//�N������誺��ܤ覡 �Ѧr���ഫ�� enum 
//��J�Ѽ�:  str ��������誺�r���{�覡
//�^�ǭ�:    ������誺enum��{�覡
M_TYPE strToMaterialType(char str[])
{
	if(strcmp(str,"Aluminum")==0)
		return ALUMINUM;
	else if (strcmp(str,"Iron")==0)
		return IRON;
	else if (strcmp(str,"Lead")==0)
		return LEAD;
	else
		return M_UNKNOWN;
}


//�C�L���c�}�C�������e�� console
//�Ѽ� obj �����c�}�C�ܼ�
//     int �����c�}�C�������Ӽ�
void printData(const O_ST* obj,int size)
{
	int i;
	printf("*******************************Display Data**********************************\n");
	printf("%4s %10s %10s %9s %9s %9s %9s %9s\n","ID","ObjType","Material","PARA1","PARA2","Volume","Weight", "Error");
	for (i=0;i<size;i++)
	{
		printf("%4d %10s %10s %9.3f %9.3f %9.3f %9.3f %9s\n",(obj+i)->id,objType[(obj+i)->otype],materialType[(obj+i)->mtype],(obj+i)->para1,(obj+i)->para2,volume(obj+i),weight(obj+i),errorType[(obj+i)->etype]);
 	}
	printf("*****************************************************************************\n");

}

//�p��Y���骺��n
double volume(const O_ST* obj)
{
	double v;
	if ((obj->etype==ERR_OBJECT)||(obj->etype==ERR_PARA1)||(obj->etype==ERR_PARA2))	// �u�n�o�{���` volume
		return 0;

	switch(obj->otype)
	{
	case BALL:
		v = 4.0/3*PI*(obj->para1)*(obj->para1)*(obj->para1);
		break;
	case CUBE:
		v = (obj->para1)*(obj->para1)*(obj->para1);
		break;
	case CYLINDER:
			v = PI*(obj->para1)*(obj->para1)*(obj->para2);
		break;
	case PYRAMID:
			v=1.0/3*(obj->para1)*(obj->para1)*(obj->para2);
		break;
	default:
		v=0;
		break;
	}
	return v;
}

//�p��Y���骺���q
double weight(const O_ST* obj)
{
	if (obj->etype==ERR_MATERIAL)
		return 0;
	else
		return density[obj->mtype]*volume(obj);   //�ھڪ��骺����s��, �d�ߨ�K��, �M��A���H��n
}


//�ﶵ2 ���{���i�J�I
void dataOperation()
{
	int select,id;
	if(size==0)
	{
		printf("No data!!! Please read data from file\n");
		return;
	}
	while(1)
	{
		operationMenu();
		scanf_s("%d",&select);
		if(0==select)
		{
			printf("Return to Main Menu\n"); 
			break;
		}
		
		switch(select)
		{
		case SHOW:
			printData(data,size);
			break;
		case APPEND:
			appendData(data,&size);
			printData(data,size);
			break;
		case UPDATE:
			printf("Enter the ID of update data:");
			scanf_s("%d",&id);
			updateData(data,size,id);
			printData(data,size);
			break;
		case DELETE:
			printf("Enter the ID of data:");
			scanf_s("%d",&id);
			deleteData(data,&size,id);
			printData(data,size);
			break;
		default:
			break;
		}
	}
}

//���w���骺 id, �d�ߦ�����b�}�C�������ޭ�(�}�C���ĴX�Ӥ���)
//��J�Ѽ� obj  �x�s���骺���c�}�C
//         int  �}�C�j�p
//         id   ���j�M�����骺�s��
//�^�ǭ�         ����b�}�C�������ޭ�
int searchData(O_ST obj[],int size,int id)
{
	int index;
	for (index=0;index<size;index++)
	{
		if(obj[index].id==id)
			return index;
	}
	return -1; //�䤣��id ����������h�^�� -1
}

//�b���c�}�C�����ݷs�W�@�����
//��J�Ѽ� obj  �x�s���骺���c�}�C
//         int  �}�C�j�p, �ĥζǰѦ� (call by reference) �O�]���W�[�@����ƫ�}�C�j�p�n�[1     
void appendData(O_ST* obj,int* size)
{
	int id,index;
	printf("Please input the properties of new object:\n");
	printf("ID: ");
	scanf_s("%d",&id);
	index=searchData(obj,*size,id);
	if(index!=-1)                   //index ������ -1 �N�� ID������s�b��}�C��               
	{
		printf("ID exist!\n");   
		return;
	}
	else
	{
		obj[*size].id=id;
		printf("Object type: 1. Ball; 2.Cube; 3. Pyramid; 4. Cylinder: ");
		scanf_s("%d",&((obj+(*size))->otype));
		printf("Material type: 1. Iron; 2. Aluminum; 3. Lead: ");
		scanf_s("%d",&((obj+(*size))->mtype));
		printf("Para1: ");
		scanf_s("%f",&((obj+(*size))->para1));
		if(((obj+(*size))->otype==PYRAMID)||((obj+(*size))->otype==CYLINDER))
		{
			printf("Para2: ");
			scanf_s("%f",&((obj+(*size))->para2));
		}
		else
			(obj+(*size))->para2=0;

		checkdata(obj+(*size));		//#2015 �ˬd��J�Ѽ�
		(*size)++;    //��Ʒs�W���\��, �}�C�j�p�[1
	}
}

//��s���c�}�C�������
//��J�Ѽ� obj  �x�s���骺���c�}�C
//         int  �}�C�j�p
//         id   ����s�����骺�s��
void updateData(O_ST* obj,int size, int id)
{
	int index;
	index=searchData(obj,size,id);
	if(index==-1)
	{
		printf(" ID doesn't exist!\n");
		return;
	}
	else
	{
		printf("Please update the properties of object %d:\n",(obj+index)->id);
		printf("Object type: 1. Ball; 2.Cube; 3. Pyramid; 4. Cylinder: ");
		scanf_s("%d",&((obj+index)->otype));
		printf("Material type: 1. Iron; 2. Aluminum; 3. Lead: ");
		scanf_s("%d",&((obj+index)->mtype));
		printf("Para1: ");
		scanf_s("%f",&((obj+index)->para1));
		if(((obj+index)->otype==PYRAMID)||((obj+index)->otype==CYLINDER))
		{
			printf("Para2: ");
			scanf_s("%f",&((obj+index)->para2));
		}
		else
			obj[index].para2=0;      //�Y����O BALL �� CUBE �ĤG�ӰѼƬ�0
		checkdata(obj+index);		 // #2015 �ˬd��J�Ѽ�
	}
}

//�R�����c�}�C�������
//��J�Ѽ� obj  �x�s���骺���c�}�C
//         int  �}�C�j�p, �ĥζǰѦ� (call by reference) �O�]���R���@����ƫ�}�C�j�p�n��1  
//         id   ���R�������骺�s��
void deleteData(O_ST* obj,int* size, int id)
{
	int i,index;
	index=searchData(obj,*size,id);
	if(index==-1)
	{
		printf(" ID doesn't exist!\n");
		return;
	}
	else
	{
		for(i=index;i<*size;i++)
		{
			*(obj+i)=*(obj+i+1);       //�R����ƫ�
		}
		(*size)--;  
	}
}

// #2015 �T�{���󪺰ѼƬO�_���T
void checkdata(O_ST* obj)
{
	if (obj->otype == 0)
		obj->etype = ERR_OBJECT;
	else if (obj->mtype == 0)
		obj->etype = ERR_MATERIAL;
	else if (obj->para1 < 0)
		obj->etype = ERR_PARA1;
	else if (obj->para2 < 0)		//�`�N: ���Ҽ{��Ball, Cube�����ˬd�Ѽ�2
		obj->etype = ERR_PARA2;
	else
		obj->etype = NORMAL;
}

//�ﶵ3 ���{���i�J�I
void sortOperation()
{
	int select;
	if(size==0)
	{
		printf("No data!!! Please read data from file\n");
		return;
	}
	while (1)
	{
		sortMenu();
		printf("please select:\n");
		scanf_s("%d",&select);
		if (0==select)
		{
			printf("Return to Main Menu\n"); 
			break;
		}
		else if ((select>=1)&&(select<=5))
		{
			sortData(data,size,(S_METHOD)select);
			printData(data,size);
		}
		else
			printf("Wrong Selection!\n"); 
	}
}
void swap(O_ST* obj1,O_ST* obj2)
{
	O_ST temp;
	temp=*obj1;
	*obj1=*obj2;
	*obj2=temp;
}

int compareID(O_ST* obj1, O_ST* obj2)
{
	return (obj1->id < obj2->id);
}
int compareObj(O_ST* obj1, O_ST* obj2)
{
	return (obj1->otype < obj2->otype);
}
int compareMaterial(O_ST* obj1, O_ST* obj2)
{
	return (obj1->mtype < obj2->mtype);
}
int compareVolume(O_ST* obj1, O_ST* obj2)
{
	return (volume(obj1) < volume(obj2));
}
int compareWeight(O_ST* obj1, O_ST* obj2)
{
	return (weight(obj1) < weight(obj2));
}

//�ŧi�ƧǨ�ƫ��а}�C
int (*cmp[6])(O_ST*, O_ST*) = {NULL,compareID,compareObj,compareMaterial,compareVolume,compareWeight};

//�w�w�ƧǪk
void sortData(O_ST* obj,int size,S_METHOD method)
{
	int pass,i;
	for(pass=1;pass<size;pass++)
	{
		for(i=0;i<size-pass;i++)
		{
			if (1==cmp[method](obj+i,obj+i+1))
				swap(obj+i,obj+(i+1));
		}
	}
}

//�ﶵ4���{���i�J�I
void writeFiles()
{
	FILE *wfp;
	errno_t err;
	int i;
	
	if(size==0)
	{
		printf("No data!!! Please read data from file\n");
		return;
	}
	//�C�@�رƧǪk�Ƨ���, �⵲�G�g�J�������ɮפ�
	for(i=1;i<=5;i++)
	{
		sortData(data,size,(S_METHOD)i);
		err=fopen_s(&wfp,filePath[(S_METHOD)i],"w");   //�}�ұ��g�J���ɮ�, �ò����ɮ׫���wfp
		if(0!=err)
			printf("File could not be opened!\n");
		else
		{
			 writeDataToSingleFile(data,size,wfp);
			 fclose(wfp);
		}
	}
}

//�N���c�}�C�����e�g�J�ɮפ�
//��J�Ѽ� obj  �x�s���骺���c�}�C
//         int  �}�C�j�p
//         fp   ���g�J���ɮ׹������ɮ׫���
void writeDataToSingleFile(O_ST* obj,int size,FILE* fp)
{
	int i;

	fprintf(fp,"%4s %10s %10s %9s %9s %9s %9s\n","ID","ObjType","Material","PARA1","PARA2","Volume","Weight");
	for (i=0;i<size;i++)
	{
		fprintf(fp,"%4d %10s %10s %9.3f %9.3f %9.3f %9.3f\n",(obj+i)->id,objType[(obj+i)->otype],materialType[(obj+i)->mtype],(obj+i)->para1,(obj+i)->para2,volume(obj+i),weight(obj+i));
	}
}


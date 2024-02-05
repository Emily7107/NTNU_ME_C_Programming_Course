#include <stdio.h>
#include <string.h>                //�]���ϥΨ�r�����禡 strcmp
#include "final_func.h"

//�ŧi�U�ذ}�C
char objType[NO_OF_OBJECT_TYPE+1][20]={"Unknown","Ball","Cube","Pyramid","Cylinder"};      
char materialType[NO_OF_MATERIAL_TYPE+1][20]={"Unknown","Iron","Aluminum","Lead"};
char errorType[NO_OF_ERROR_TYPE+1][20]={"Normal","Err_object","Err_material","Err_para1","Err_para2"};	// #2015
double density[NO_OF_MATERIAL_TYPE+1]={0,7.87, 2.7,11.3};


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
int readData(O_ST obj[], FILE* fp)
{
	int i;
	char temp[20];
	i=0;
	while(!feof(fp))
	{
		fscanf_s(fp,"%d",&(obj[i].id));
		if(obj[i].id==0)
			break;
		fscanf_s(fp,"%s",temp,20);
		obj[i].otype=strToObjType(temp);           //�N����Ϊ�����ܤ覡 �Ѧr���ഫ�� enum 
		fscanf_s(fp,"%s",temp,20);
		obj[i].mtype=strToMaterialType(temp);      //�N������誺��ܤ覡 �Ѧr���ഫ�� enum 
		fscanf_s(fp,"%f",&(obj[i].para1));
		fscanf_s(fp,"%f",&(obj[i].para2));
		checkdata(obj[i]);		// #2015 �ˬd��J�Ѽ�
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
void printData(O_ST obj[],int size)
{
	int i;
	printf("*******************************Display Data**********************************\n");
	printf("%4s %10s %10s %9s %9s %9s %9s %9s\n","ID","ObjType","Material","PARA1","PARA2","Volume","Weight", "Error");
	for (i=0;i<size;i++)
	{
		printf("%4d %10s %10s %9.3f %9.3f %9.3f %9.3f %9s\n",obj[i].id,objType[obj[i].otype],materialType[obj[i].mtype],obj[i].para1,obj[i].para2,volume(obj[i]),weight(obj[i]),errorType[obj[i].etype]);
 	}
	printf("*****************************************************************************\n");

}

//�p��Y���骺��n
double volume(O_ST obj)
{
	double v;
	if ((obj.etype==ERR_OBJECT)||(obj.etype==ERR_PARA1)||(obj.etype==ERR_PARA2))	// �u�n�o�{���` volume
		return 0;

	switch(obj.otype)
	{
	case BALL:
		v = 4.0/3*PI*(obj.para1)*(obj.para1)*(obj.para1);
		break;
	case CUBE:
		v = (obj.para1)*(obj.para1)*(obj.para1);
		break;
	case CYLINDER:
			v = PI*(obj.para1)*(obj.para1)*(obj.para2);
		break;
	case PYRAMID:
			v=1.0/3*(obj.para1)*(obj.para1)*(obj.para2);
		break;
	default:
		v=0;
		break;
	}
	return v;
}

//�p��Y���骺���q
double weight(O_ST obj)
{
	if (obj.etype==ERR_MATERIAL)
		return 0;
	else
		return density[obj.mtype]*volume(obj);   //�ھڪ��骺����s��, �d�ߨ�K��, �M��A���H��n
}


// �T�{���󪺰ѼƬO�_���T
void checkdata(O_ST &obj)
{
	if (obj.otype == 0)
		obj.etype = ERR_OBJECT;
	else if (obj.mtype == 0)
		obj.etype = ERR_MATERIAL;
	else if (obj.para1 < 0)
		obj.etype = ERR_PARA1;
	else if (obj.para2 < 0)		//�`�N: ���Ҽ{��Ball, Cube�����ˬd�Ѽ�2
		obj.etype = ERR_PARA2;
	else
		obj.etype = NORMAL;
}




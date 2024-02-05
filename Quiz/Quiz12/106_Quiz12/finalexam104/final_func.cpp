#include <stdio.h>
#include <string.h>                //因為使用到字串比較函式 strcmp
#include "final_func.h"

//宣告各種陣列
char objType[NO_OF_OBJECT_TYPE+1][20]={"Unknown","Ball","Cube","Pyramid","Cylinder"};      
char materialType[NO_OF_MATERIAL_TYPE+1][20]={"Unknown","Iron","Aluminum","Lead"};
char errorType[NO_OF_ERROR_TYPE+1][20]={"Normal","Err_object","Err_material","Err_para1","Err_para2"};	// #2015
double density[NO_OF_MATERIAL_TYPE+1]={0,7.87, 2.7,11.3};


//結構陣列的變數, 用來儲存所有的物件
O_ST data[MAXSIZE];
int size=0;   //物件的個數

//主選單
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


//選項1 的程式進入點
void openFileAndShowData()
{
	FILE* fp=NULL;
	errno_t err;
	err=fopen_s(&fp,FILE_ORIGIN,"r");  //開啟檔案
	if(0!=err)                          
	{
		printf("File could not be opened!\n");
		return;
	}
	else
	{
		size=readData(data,fp);   //讀取檔案至結構陣列 data 中
		printData(data,size);     //將結構陣列中的內容列印至 console
		fclose(fp);               //關閉檔案
	}
}


//讀取檔案內容並將結果轉換成結構陣列的格式 (新增: 確認資料是否正確)
//參數 obj 為結構陣列變數
//     fp  為欲讀取之檔案的檔案指標
//回傳值   檔案中儲存的物件個數
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
		obj[i].otype=strToObjType(temp);           //將物體形狀的表示方式 由字串轉換成 enum 
		fscanf_s(fp,"%s",temp,20);
		obj[i].mtype=strToMaterialType(temp);      //將物體材質的表示方式 由字串轉換成 enum 
		fscanf_s(fp,"%f",&(obj[i].para1));
		fscanf_s(fp,"%f",&(obj[i].para2));
		checkdata(obj[i]);		// #2015 檢查輸入參數
		i++;
	}
	return i;    //回傳檔案中的物件個數
}

//將物體形狀的表示方式 由字串轉換成 enum 
//輸入參數:  str 為物體形狀的字串表現方式
//回傳值:    物體形狀的enum表現方式
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


//將物體材質的表示方式 由字串轉換成 enum 
//輸入參數:  str 為物體材質的字串表現方式
//回傳值:    物體材質的enum表現方式
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


//列印結構陣列中的內容至 console
//參數 obj 為結構陣列變數
//     int 為結構陣列的元素個數
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

//計算某物體的體積
double volume(O_ST obj)
{
	double v;
	if ((obj.etype==ERR_OBJECT)||(obj.etype==ERR_PARA1)||(obj.etype==ERR_PARA2))	// 只要發現異常 volume
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

//計算某物體的重量
double weight(O_ST obj)
{
	if (obj.etype==ERR_MATERIAL)
		return 0;
	else
		return density[obj.mtype]*volume(obj);   //根據物體的材質編號, 查詢其密度, 然後再乘以體積
}


// 確認物件的參數是否正確
void checkdata(O_ST &obj)
{
	if (obj.otype == 0)
		obj.etype = ERR_OBJECT;
	else if (obj.mtype == 0)
		obj.etype = ERR_MATERIAL;
	else if (obj.para1 < 0)
		obj.etype = ERR_PARA1;
	else if (obj.para2 < 0)		//注意: 未考慮到Ball, Cube不需檢查參數2
		obj.etype = ERR_PARA2;
	else
		obj.etype = NORMAL;
}




#include <stdio.h>
#include <string.h>                //因為使用到字串比較函式 strcmp
#include "final_func.h"
#include <stdlib.h>

//宣告各種陣列
char objType[NO_OF_OBJECT_TYPE+1][20]={"Unknown","Ball","Cube","Pyramid","Cylinder"};      
char materialType[NO_OF_MATERIAL_TYPE+1][20]={"Unknown","Iron","Aluminum","Lead"};
char errorType[NO_OF_ERROR_TYPE+1][20]={"Normal","Err_object","Err_material","Err_para1","Err_para2"};	// #2015
double density[NO_OF_MATERIAL_TYPE+1]={0,7.87, 2.7,11.3};
char filePath[6][128]={"WrongPath",FILE_TXT1,FILE_TXT2,FILE_TXT3,FILE_TXT4,FILE_TXT5};

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

//選項2 的選單
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

//選項3 的選單
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

//選項5 的程式進入點
void clearScreen()
{
	system("CLS");
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
		(obj+i)->otype=strToObjType(temp);           //將物體形狀的表示方式 由字串轉換成 enum 
		fscanf_s(fp,"%s",temp,20);
		(obj+i)->mtype=strToMaterialType(temp);      //將物體材質的表示方式 由字串轉換成 enum 
		fscanf_s(fp,"%f",&((obj+i)->para1));
		fscanf_s(fp,"%f",&((obj+i)->para2));
		checkdata(obj+i);		// #2015 檢查輸入參數
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

//計算某物體的體積
double volume(const O_ST* obj)
{
	double v;
	if ((obj->etype==ERR_OBJECT)||(obj->etype==ERR_PARA1)||(obj->etype==ERR_PARA2))	// 只要發現異常 volume
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

//計算某物體的重量
double weight(const O_ST* obj)
{
	if (obj->etype==ERR_MATERIAL)
		return 0;
	else
		return density[obj->mtype]*volume(obj);   //根據物體的材質編號, 查詢其密度, 然後再乘以體積
}


//選項2 的程式進入點
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

//給定物體的 id, 查詢此物體在陣列中的索引值(陣列的第幾個元素)
//輸入參數 obj  儲存物體的結構陣列
//         int  陣列大小
//         id   欲搜尋之物體的編號
//回傳值         物體在陣列中的索引值
int searchData(O_ST obj[],int size,int id)
{
	int index;
	for (index=0;index<size;index++)
	{
		if(obj[index].id==id)
			return index;
	}
	return -1; //找不到id 對應的物體則回傳 -1
}

//在結構陣列的尾端新增一筆資料
//輸入參數 obj  儲存物體的結構陣列
//         int  陣列大小, 採用傳參考 (call by reference) 是因為增加一筆資料後陣列大小要加1     
void appendData(O_ST* obj,int* size)
{
	int id,index;
	printf("Please input the properties of new object:\n");
	printf("ID: ");
	scanf_s("%d",&id);
	index=searchData(obj,*size,id);
	if(index!=-1)                   //index 不等於 -1 代表此 ID的物件存在於陣列中               
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

		checkdata(obj+(*size));		//#2015 檢查輸入參數
		(*size)++;    //資料新增成功後, 陣列大小加1
	}
}

//更新結構陣列中的資料
//輸入參數 obj  儲存物體的結構陣列
//         int  陣列大小
//         id   欲更新之物體的編號
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
			obj[index].para2=0;      //若物體是 BALL 或 CUBE 第二個參數為0
		checkdata(obj+index);		 // #2015 檢查輸入參數
	}
}

//刪除結構陣列中的資料
//輸入參數 obj  儲存物體的結構陣列
//         int  陣列大小, 採用傳參考 (call by reference) 是因為刪除一筆資料後陣列大小要減1  
//         id   欲刪除之物體的編號
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
			*(obj+i)=*(obj+i+1);       //刪除資料後
		}
		(*size)--;  
	}
}

// #2015 確認物件的參數是否正確
void checkdata(O_ST* obj)
{
	if (obj->otype == 0)
		obj->etype = ERR_OBJECT;
	else if (obj->mtype == 0)
		obj->etype = ERR_MATERIAL;
	else if (obj->para1 < 0)
		obj->etype = ERR_PARA1;
	else if (obj->para2 < 0)		//注意: 未考慮到Ball, Cube不需檢查參數2
		obj->etype = ERR_PARA2;
	else
		obj->etype = NORMAL;
}

//選項3 的程式進入點
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

//宣告排序函數指標陣列
int (*cmp[6])(O_ST*, O_ST*) = {NULL,compareID,compareObj,compareMaterial,compareVolume,compareWeight};

//泡泡排序法
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

//選項4的程式進入點
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
	//每一種排序法排完後, 把結果寫入對應的檔案中
	for(i=1;i<=5;i++)
	{
		sortData(data,size,(S_METHOD)i);
		err=fopen_s(&wfp,filePath[(S_METHOD)i],"w");   //開啟欲寫入之檔案, 並產生檔案指標wfp
		if(0!=err)
			printf("File could not be opened!\n");
		else
		{
			 writeDataToSingleFile(data,size,wfp);
			 fclose(wfp);
		}
	}
}

//將結構陣列的內容寫入檔案中
//輸入參數 obj  儲存物體的結構陣列
//         int  陣列大小
//         fp   欲寫入之檔案對應的檔案指標
void writeDataToSingleFile(O_ST* obj,int size,FILE* fp)
{
	int i;

	fprintf(fp,"%4s %10s %10s %9s %9s %9s %9s\n","ID","ObjType","Material","PARA1","PARA2","Volume","Weight");
	for (i=0;i<size;i++)
	{
		fprintf(fp,"%4d %10s %10s %9.3f %9.3f %9.3f %9.3f\n",(obj+i)->id,objType[(obj+i)->otype],materialType[(obj+i)->mtype],(obj+i)->para1,(obj+i)->para2,volume(obj+i),weight(obj+i));
	}
}


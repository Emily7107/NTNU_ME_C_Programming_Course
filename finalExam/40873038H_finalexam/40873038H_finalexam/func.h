#define ORIGINAL_FILE "data/107finalexam.txt"
#define FILE_TXT1 "output/SorID.txt"
#define FILE_TXT2 "output/SorObject.txt"
#define FILE_TXT3 "output/SorMaterial.txt"
#define FILE_TXT4 "output/SorVolume.txt"
#define FILE_TXT5 "output/SorWeight.txt"

#define NO_OF_OBJECT 4
#define NO_OF_MATERIAL 3
#define NO_OF_ERRTYPE 5
#define PI 3.1415926
#define MAXSIZE 100

enum object_type{O_UNKNOWN,BALL,CUBE,PYRAMID,CYLINDER};
enum material_type{M_UNKNOWN,IRON,ALUMINUM,LEAD};
enum err_type {NORMAL,ERR_OBJECT,ERR_MATERIAL,ERR_PARA1,ERR_PARA2};//刪掉ERR_ID
enum dataoperation {EXIT,SHOW,APPEND,UPDATE,DELETE};
enum soroperation{NONE,SOR_BY_ID,SOR_BY_OBJECT,SOR_BY_MATERIAL,SOR_BY_VOLUME,SOR_BY_WEIGHT};//把NONE加回去

typedef enum object_type O_TYPE;
typedef enum material_type M_TYPE;
typedef enum err_type E_TYPE;
typedef enum dataoperation DATA_OP;
typedef enum soroperation S_METHOD;

struct dataobject
{
	int id;
	O_TYPE otype;
	M_TYPE mtype;
	float para1;
	float para2;
	E_TYPE etype;
};

typedef dataobject O_ST;

void Mainmenu();
void sormanu();
void operationmenu();

void opendfileandshowdata();
void dataoperation();
void sortoperation();
void writedata();

int readdata(O_ST* obj, FILE* fp);
O_TYPE strtoObject(char str[]);
M_TYPE MaterialtoObject(char str[]);
double volume(O_ST* obj);
double weight(O_ST* obj);
void printdata(O_ST* data, int size);
void checkdata(O_ST* obj);

void appendData(O_ST* obj,int* size);
void updatedata(O_ST* obj, int size, int id);
void deletedata(O_ST* obj, int* size, int id);

void sortdata(O_ST* , int size, S_METHOD method);//把obj刪掉
void swap(O_ST* obj1, O_ST* obj2);

void savedatatosinglefile(O_ST* obj, int size, FILE* fp);
#define FILE_ORIGIN "data/106_Quiz11.txt"
#define FILE_TXT1 "output/sortID.txt"
#define FILE_TXT2 "output/sortObjType.txt"
#define FILE_TXT3 "output/sortMaterial.txt"
#define FILE_TXT4 "output/sortVolume.txt"
#define FILE_TXT5 "output/sortWeight.txt"

#define NO_OF_OBJECT 4
#define NO_OF_MATERIAL 3
#define NO_OF_ERRTYPE 5
#define PI 3.1415926
#define MAXSIZE 100

enum objtype {O_UNKNOWN,BALL,CUBE,PYRAMID,CYLINDER};
enum materialtype {M_UNKNOWN,IRON,ALUMINUM,LEAD};
enum sortmethod {NOUN,SOR_BY_ID,SOR_BY_OBJECT,SOR_BY_MATERIAL,SOR_BY_VOLUME,SOR_BY_WEIGHT };
enum dataopration {EXIT,SHOW,APPEND,UPDATE,DELET};
enum errtype {NORMAL,ERR_OBJ,ERR_MAT,ERR_PARAL1,ERR_PARAL2};

typedef enum objtype O_TYPE;
typedef enum materialtype M_TYPE;
typedef enum sortmethod S_METHOD;
typedef enum dataopration DATA_OP;
typedef enum errtype E_TYPE;

struct objectdata
{
	int id;
	O_TYPE otype;
	M_TYPE mtype;
	float para1;
	float para2;
	E_TYPE etype;
};
typedef struct objectdata O_ST;

void mainmanu();
void operationmanu();
void sortmanu();

void openfileandshowdata();
void dataoperation();
void sortoperation();
void writedata();

int readData(O_ST obj[], FILE* fp);
O_TYPE strtobjtype(char str[]);
M_TYPE strtomaterialtype(char str[]);
double volume(O_ST obj);
double weight(O_ST obj);
void printdata(O_ST data[], int size);
void checkdata(O_ST &obj);

void appenddata(O_ST obj[], int &size);
void updatedata(O_ST obj[],int size,int id);
void deletdata(O_ST obj[], int& size, int id);

void sortdata(O_ST[], int size, S_METHOD method);
void swap(O_ST& obj1, O_ST& obj2);

void writeDataToSingleFile(O_ST obj[],int& size, FILE* fp);
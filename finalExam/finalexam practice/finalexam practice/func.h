#define ORIGINAL_FILE "data/105finalexam.txt"
#define TXT_FILE1 "output/SortID.txt"
#define TXT_FILE2 "output/SortObjectType.txt"
#define TXT_FILE3 "output/SortMaterial.txt"
#define TXT_FILE4 "output/SortVolume.txt"
#define TXT_FILE5 "output/SortWeight.txt"

#define NO_OF_OBJECT 4
#define NO_OF_MATERIAL 3
#define NO_OF_ERRTYPE 5
#define MAXSIZE 100
#define PI 3.1415926

enum object_type {O_UNKNOWN,BALL,CUBE,PYRAMID,CYLINDER};
enum material {M_UNKNOWN,IRON,ALUMINUM,LEAD};
enum err_type {NORMAL,ERR_OBJ,ERR_MATERIAL,ERR_PARA1,ERR_PARA2};
enum dtatOperation{EXIT,SHOW,APPEND,UPDATE,DELETE};
enum sort_method{NONE,SOR_BY_ID,SOR_BY_OBJECT,SOR_BY_MATERIAL,SOR_BY_VOLUME,SOR_BY_WEIGHT};

typedef enum object_type O_TYPE;
typedef enum material M_TYPE;
typedef enum err_type E_TYPE;
typedef enum dtatOperation DATA_OP;
typedef enum sort_method S_MATHOD;

struct datainformation
{
	int id;
	O_TYPE otype;
	M_TYPE mtype;
	float para1;
	float para2;
	E_TYPE etype;
};
typedef struct datainformation O_ST;

void mainMenu();
void operationMenu();
void sorMenu();

void openfileandshowdata();
void dataoperation();
void sortoperation();
void writedata();

int readData(O_ST* obj, FILE* fp);
O_TYPE strtoObject(char str[]);
M_TYPE strtoMaterial(char str[]);
void printdata(const O_ST* data, int size);
void chectdata(O_ST* obj);
double volume(const O_ST* obj);
double weight(const O_ST* obj);

void appendata(O_ST* obj,int *size);
void updatadata(O_ST* obj, int size, int id);
void deletedata(O_ST* obj, int* size, int id);

void sortdata(O_ST* obj, int sizt, S_MATHOD method);
void swap(O_ST* obj1, O_ST* obj2);

void savedatatosinglefile(O_ST* obj, int* size, FILE* fp);
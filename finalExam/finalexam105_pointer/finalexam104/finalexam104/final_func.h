//檔案路徑
#define FILE_ORIGIN "data/105finalexam.txt"
#define FILE_TXT1 "output/sortID.txt"
#define FILE_TXT2 "output/sortObjectType.txt"
#define FILE_TXT3 "output/sortMaterial.txt"
#define FILE_TXT4 "output/sortVolume.txt"
#define FILE_TXT5 "output/sortWeight.txt"

//常數定義
#define NO_OF_OBJECT_TYPE 4           //物體形狀的種類數
#define NO_OF_MATERIAL_TYPE 3         //物體材質的種類數
#define NO_OF_ERROR_TYPE 5
#define PI 3.1415926                  //圓周率
#define MAXSIZE 100                   //最大的物體個數

//列舉型態定義
enum object_tpye {O_UNKNOWN, BALL, CUBE, PYRAMID, CYLINDER};     //物體形狀的種類
enum material_type {M_UNKNOWN, IRON,ALUMINUM, LEAD};           //物體材質的種類
enum sort_method {NONE, SORT_BY_ID, SORT_BY_OBJTYPE, SORT_BY_MATERIAL, SORT_BY_VOLUME, SORT_BY_WEIGHT}; //排序法的種類
enum data_operation {EXIT, SHOW, APPEND, UPDATE, DELETE};          //資料的操作

// #2015 物件參數錯誤的類型: 正常, 物件種類錯誤, 材質錯誤, 參數1錯誤, 參數2錯誤
// To avoid name collision, using an enum class is recommended.
// Ex: enum class ERR_TYPE {NONE, ERROR_OBJECT, ERR_MATERIAL, ERR_PARA1, ERR_PARA2};
enum error_type {NORMAL, ERR_OBJECT, ERR_MATERIAL, ERR_PARA1, ERR_PARA2};

// 利用 typedef 重新命名 enum 的型別名稱
typedef enum object_tpye O_TYPE;
typedef enum material_type M_TYPE;
typedef enum data_operation DATA_OP;
typedef enum sort_method S_METHOD;
typedef enum error_type ERR_TYPE;	// #2015

//資料結構定義
struct objectData
{
	int id;           //編號
	O_TYPE otype;     //形狀
	M_TYPE mtype;     //材質
	float para1;      //物體的形狀參數1
	float para2;      //物體的形狀參數1
	ERR_TYPE etype;	  // #2015 s錯誤類型
};

// 利用 typedef 重新命名 struct 的型別名稱
typedef struct objectData O_ST;

//選單函式
void mainMenu();
void operationMenu();
void sortMenu();

//主選單流程
void openFileAndShowData();   //選項1 的函式進入點
void dataOperation();         //選項2 的函式進入點
void sortOperation();         //選項3 的函式進入點
void writeFiles();            //選項4 的函式進入點

//選項1 所使用的函式
int readData(O_ST* obj,FILE* fp);       //將檔案讀入結構陣列中
O_TYPE strToObjType(char str[]);         //將物體形狀的表示方式 由字串轉換成 enum
M_TYPE strToMaterialType(char str[]);    //將物體材質的表示方式 由字串轉換成 enum
double volume(const O_ST* obj);                 //計算物體的體積
double weight(const O_ST* obj);                 //計算物體的重量
void printData(const O_ST* data,int size);    //將結構陣列的資料列印至 Console
void checkdata(O_ST* obj);		

//選項2 所使用的函式
void appendData(O_ST* obj,int* size);           //增加一筆資料
void updateData(O_ST* obj,int size, int id);    //更新資料
void deleteData(O_ST* obj,int* size, int id);   //刪除一筆資料
				 // #2015 檢查輸入參數

//選項3 所使用的函式
void sortData(O_ST* ,int size, S_METHOD method);
void swap(O_ST* obj1,O_ST* obj2);

//選項4 所使用的函式
void writeDataToSingleFile(O_ST* obj,int size,FILE* fp);


















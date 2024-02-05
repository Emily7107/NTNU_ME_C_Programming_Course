//�ɮ׸��|
#define FILE_ORIGIN "data/105finalexam.txt"
#define FILE_TXT1 "output/sortID.txt"
#define FILE_TXT2 "output/sortObjectType.txt"
#define FILE_TXT3 "output/sortMaterial.txt"
#define FILE_TXT4 "output/sortVolume.txt"
#define FILE_TXT5 "output/sortWeight.txt"

//�`�Ʃw�q
#define NO_OF_OBJECT_TYPE 4           //����Ϊ���������
#define NO_OF_MATERIAL_TYPE 3         //������誺������
#define NO_OF_ERROR_TYPE 5
#define PI 3.1415926                  //��P�v
#define MAXSIZE 100                   //�̤j������Ӽ�

//�C�|���A�w�q
enum object_tpye {O_UNKNOWN, BALL, CUBE, PYRAMID, CYLINDER};     //����Ϊ�������
enum material_type {M_UNKNOWN, IRON,ALUMINUM, LEAD};           //������誺����
enum sort_method {NONE, SORT_BY_ID, SORT_BY_OBJTYPE, SORT_BY_MATERIAL, SORT_BY_VOLUME, SORT_BY_WEIGHT}; //�ƧǪk������
enum data_operation {EXIT, SHOW, APPEND, UPDATE, DELETE};          //��ƪ��ާ@

// #2015 ����Ѽƿ��~������: ���`, ����������~, ������~, �Ѽ�1���~, �Ѽ�2���~
// To avoid name collision, using an enum class is recommended.
// Ex: enum class ERR_TYPE {NONE, ERROR_OBJECT, ERR_MATERIAL, ERR_PARA1, ERR_PARA2};
enum error_type {NORMAL, ERR_OBJECT, ERR_MATERIAL, ERR_PARA1, ERR_PARA2};

// �Q�� typedef ���s�R�W enum �����O�W��
typedef enum object_tpye O_TYPE;
typedef enum material_type M_TYPE;
typedef enum data_operation DATA_OP;
typedef enum sort_method S_METHOD;
typedef enum error_type ERR_TYPE;	// #2015

//��Ƶ��c�w�q
struct objectData
{
	int id;           //�s��
	O_TYPE otype;     //�Ϊ�
	M_TYPE mtype;     //����
	float para1;      //���骺�Ϊ��Ѽ�1
	float para2;      //���骺�Ϊ��Ѽ�1
	ERR_TYPE etype;	  // #2015 s���~����
};

// �Q�� typedef ���s�R�W struct �����O�W��
typedef struct objectData O_ST;

//���禡
void mainMenu();
void operationMenu();
void sortMenu();

//�D���y�{
void openFileAndShowData();   //�ﶵ1 ���禡�i�J�I
void dataOperation();         //�ﶵ2 ���禡�i�J�I
void sortOperation();         //�ﶵ3 ���禡�i�J�I
void writeFiles();            //�ﶵ4 ���禡�i�J�I

//�ﶵ1 �ҨϥΪ��禡
int readData(O_ST* obj,FILE* fp);       //�N�ɮ�Ū�J���c�}�C��
O_TYPE strToObjType(char str[]);         //�N����Ϊ�����ܤ覡 �Ѧr���ഫ�� enum
M_TYPE strToMaterialType(char str[]);    //�N������誺��ܤ覡 �Ѧr���ഫ�� enum
double volume(const O_ST* obj);                 //�p�⪫�骺��n
double weight(const O_ST* obj);                 //�p�⪫�骺���q
void printData(const O_ST* data,int size);    //�N���c�}�C����ƦC�L�� Console
void checkdata(O_ST* obj);		

//�ﶵ2 �ҨϥΪ��禡
void appendData(O_ST* obj,int* size);           //�W�[�@�����
void updateData(O_ST* obj,int size, int id);    //��s���
void deleteData(O_ST* obj,int* size, int id);   //�R���@�����
				 // #2015 �ˬd��J�Ѽ�

//�ﶵ3 �ҨϥΪ��禡
void sortData(O_ST* ,int size, S_METHOD method);
void swap(O_ST* obj1,O_ST* obj2);

//�ﶵ4 �ҨϥΪ��禡
void writeDataToSingleFile(O_ST* obj,int size,FILE* fp);


















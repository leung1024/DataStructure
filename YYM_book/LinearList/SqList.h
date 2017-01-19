

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

struct SqList {
    ElemType    *elem; // 存储空间基地址
    int         length;
    int         listsize;
}SqList;

// 静态分配顺序存储结构
typedef struct {
	ElemType elem[MAXSIZE];
	int length;
}sqlist_static;

Status IinitList_Sq(struct SqList &L);
Status ListInsert_Sq(struct SqList &L, int i, ElemType &e);
Status ListDelete_Sq(struct SqList &L, int i, ElemType &e);
int LocateElem_Sq(
        struct SqList L,
        ElemType e,
        Status (*compare)(ElemType, ElemType));
void MergeList_Sq(
        struct SqList La,
        struct SqList Lb,
        struct SqList Lc);
int compare_num(ElemType a, ElemType b);
// 对比两个数的大小


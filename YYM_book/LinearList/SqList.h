

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef int Status;
typedef int ElemType;

struct SqList {
    ElemType    *elem;
    int         length;
    int         listsize;
}SqList;

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

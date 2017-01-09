// 静态单链表
#define MAXSIZE 1000 // 链表的最大长度


typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e);
void InitSpace_SL(SLinkList &space);

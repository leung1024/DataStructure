
#define MAXSIZE 1000 // 链表的最大长度

typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

typedef struct {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;



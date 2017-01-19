
#define MAXSIZE 1000 // 链表的最大长度

typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE]; 

typedef struct {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList; // 链表头指针

Status CreateList_L(struct LinkList &L, int n);
// 创建节点
Status GetElem_L(struct LNode L, int i, ElemType &e);
// 获取节点数据
Status ListInsert_L(struct LinkList &L, int i, ElemType e);
// 链表插入操作
Status LinkDelete_L(struct LinkList &L, int i, ElemType &e);
// 链表删除操作
Status MergeList_L(
        struct LinkList &La,
        struct LinkList &Lb,
        struct LinkList &Lc);
// 归并操作
Status ClearList_L(LinkList &L);
// 清空链表



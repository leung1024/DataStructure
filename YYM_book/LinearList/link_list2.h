

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}*Link, *Position;

typedef struct {
    Link head, tail;
    int len;
}LinkList;

Status InitList(LinkList &L);
// 构造一个空的线性链表
Status LocateElem(LinkList L, int i, Link &p);
// p 指向第i 个元素的位置
Status MakeNode(Link &p, ElemType e);
// 分配p指向以e为值的节点
Status InsFirst(Link h, Link s);
// 已知线性链表的头节点，将s所指的节点插入在第一个节点之前



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
Status FreeNode(Link &p);
// 释放p所指的节点
Status InsFirst(Link h, Link s);
// 已知线性链表的头节点，将s所指的节点插入在第一个节点之前
Status GetHead(LinkList L);
// 获取头指针
Status NextPos(LinkList L, Link p);
// 获取下一个节点的指针
ElemType GetCurElem(Link p);
// 获取当前p节点的值
Status SetCurElem(Link &p, ElemType e);
// 设置当前p节点的值
Status Append(LinkList &L, Link s);
// 添加
Status DelFirst(Link h, Link &q);
// 删除h所指向的线性链表的头节点，删除链表中的第一个节点
// 以q返回
Status LinstInsert_L(LinkList &L, int i, ElemType e);
// 插入e到第i个位置
Status MergeList_L(
        LinkList &La,
        LinkList &Lb,
        LinkList &Lc,
        int (*compare)(ElemType, ElemType));
// 合并两个线性链表 
Status LinkListTraverse(LinkList L);
// 线性链表遍历

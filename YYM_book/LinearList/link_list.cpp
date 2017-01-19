


Status CreateList_L(struct LinkList &L, int n) {
    // 输入n个元素，创建单链表L
    L = (LNode)malloc(sizeof(LNode));
    L->next = NULL;
    for (i = 1; i <= n; i++) {
        p = (LinkList)malloc(sizeof(LNode));
        scanf(&p->data);
        p->next = NULL;
        L->next = p;
    }
}

Status GetElem_L(struct LNode L, int i, ElemType &e) {
    // L为头指针
    // 顺序存取结构
    struct LNode *p = L->next; // L为头结点，指向第一个节点
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}


Status ListInsert_L(struct LinkList &L, int i, ElemType e) {
    // 在第i个节点插入e
    struct LNode p = L->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    } // 找出第i个节点
    if (!p || j > i) return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    // 修改指针为 O(1)
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status LinkDelete_L(struct LinkList &L, int i, ElemType &e) {
    struct LNode p = L;
    struct LNode del_node;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!(p->next || j > i - 1)) return ERROR;
    del_node = p->next;
    p->next = del_node->next;
    e = del_node->data; // e返回被删的数据
    free(del_node); // 释放q
}

// 清空链表
Status ClearList(LinkList &L) {
    LinkList p;
    while (L->next) {
        p = L->next;
        L->next = p->next;
        free(p);
    }
    return OK;
}

//  归并
Status MergeList_L(
        struct LinkList &La,
        struct LinkList &Lb,
        struct LinkList %Lc) {
    struct LNode pa, pb, pc;
    *pa = La->next;
    *pb = Lb->next;
    *pc = Lc = La;

    while (pa && pb) {
        if (pa->data <= pb->data){
            pc->next = pa;
            pc = pc->next; // 更新pc指向的位置
            pa = pa->next; // 更新pa指向的位置
        }
        else {
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa : pb; // 插入剩余
    free(Lb);
    free(La);
}




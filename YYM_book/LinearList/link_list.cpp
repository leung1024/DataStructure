


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
    struct LNode *p = L->next; // 指向第一个节点
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
    j = 0;
    while (p && j < i - 1) {p = p->next; ++j;} // 找出第i个节点
    if (!p || j > i) return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status LinkDelete_L(struct LinkList &L, int i, ElemType &e) {
    struct LNode p = L;
    struct LNode del_q;
    j = 0;
    while (p && j < i - 1) {p = p->next; ++j;}
    if (!(p->next || j > i - 1)) return ERROR;
    del_q = p->next;
    p->next = del_q->next;
    e = del_q->data; // e返回被删的数据
    free(del_q); // 释放q
}

// 合并
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




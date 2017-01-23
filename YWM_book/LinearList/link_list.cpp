


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

LinkList CreateList_L_2() {
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    LNode *s, *last_node;
    int x;
    scanf("%d", &x);
    L = NULL;
    while (x) {
        s = (*LNode)malloc(sizeof(LNode));
        s->data = x;
        if (L == NULL) L = s; // 第一个节点处理 
        else last_node->next = s; // 更新最后一个节点
        last_node = s;
        scanf("%d", &x);
    }
    if (last_node != NULL) last_node->next = NULL; // 非空链表 如果有头结点 这两个if 都可以省略
    return L
}

LinkList CreateList_L_3() {
    LinkList L = (*LNode)malloc(sizeof(LNode));
    LNode *s, *last_node;
    int x;
    scanf("%d", &x);
    L->next = NULL;
    last_node = L; // 头结点
    while (x) {
        s = (*LNode)malloc(sizeof(LNode));
        s->data = x;
        last_node->next = s; // 更新最后一个节点
        last_node = s;
        scanf("%d", &x);
    }
    last_node->next = NULL; // 非空链表 如果有头结点 这两个if 都可以省略
    return L
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
        struct LinkList &Lb) {
    struct LNode pa, pb, pc, q;
    LinkList Lc = (LinkList)malloc(sizeof(LinkList));
    *pa = La->next;
    *pb = Lb->next;
    *pc = Lc->next = NULL;


    while (pa || pb) {
        if (pa) data_a = pa->data;
        if (pb) data_b = pb->data;
        if (data_a <= data_b){
            q = pa->next;
            pa->next = pc->next; // 头插pa
            pc->next = pa;
            // pc = pc->next; // 更新pc指向的位置
            pa = q; // 更新pa指向的位置
        }
        else {
            q = pb->next;
            pb->next = pc->next;
            pc->next = pb;
            // pc = pc->next;
            pb = q;
        }
    }

    // q = pa ? pa : pb; // 插入剩余
    free(Lb);
    free(La);
}

int delete_elem(LinkList &L, int mink, int maxk) {
    LNode *p, *pre, *tail, *s, *tmp;
    p = L->next;
    while (p && p->data <= mink) {
        pre = p;
        p = p->next;
    }

    while (p && p->data < maxk) {
        tail = p;
        p = p->next;
    }
    tmp = pre->next;
    pre->next = tail;

    while (tmp != tail) { // 删除节点
        s = tmp->next;
        free(tmp);
        tmp = s;
    } // while

}

Status Reverse_L(LinkList &L) {
    LNode *p, *succ;
    p = L->next;
    L->next = NULL;
    while (p) { // p 为正准备前插的节点
        succ = p->next;
        p->next = L->next;
        L->next = p;
        p = succ;
    }
    return OK;
}

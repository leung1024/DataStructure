


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
        if (!pa) {
            q = pb;
            pb = pb->next;
        }
        else if (!pb) {
            q = pa;
            pa = pa->next;
        }
        else if (pa->data <= pb->data) {
            q = pa;
            pa = pa->next;
        }
        else {
            q = pb;
            pb = p->next;
        }
        q->next = Lc->next; // 需要前插的节点连接到头结点的next, 即头插法
        Lc->next = q;
    }

    // q = pa ? pa : pb; // 插入剩余
    free(Lb);
    free(La);
}

Status OneToThree(
        LinkList &L,
        LinkList &La,
        LinkList &Ld,
        LinkList &Lo) {
    La = (LinkList)malloc(sizeof(LNode)); // 字母链表
    Ld = (LinkList)malloc(sizeof(LNode)); // 数字链表
    Lo = (LinkList)malloc(sizeof(LNode)); // 其他字符串
    LNode *tmp;
    while (L) {
        if (isAlphabet(L->data)) {
            tmp = L->next;
            tmp->next = La->next; // 后插法
            La->next = tmp;
        }
        else if (isNumber(L->data)) {
            tmp = L->next;
            tmp->next = Ld->next;
            Ld->next = tmp;
        }
        else {
            tmp = L->next;
            tmp->next = Lo->next; // 后插法
            Lo->next = tmp;
        }
        L = L->next;
    }
    return OK;
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

int isAlphabet(char elem) {
    if (elem >= 'a' && elem <= 'z' ||
        elem >= 'A' && elem <= 'Z') {
        return 1;
    }
    else {
        return 0;
    }
}

int isNumber(char elem) {
    if (elem >= '0' && elem <= '9') {
        return 1;
    }
    else {
        return 0;
    }
}


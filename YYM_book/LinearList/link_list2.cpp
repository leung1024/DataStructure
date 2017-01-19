

Status InitList(LinkList &L) {
    Link p;
    p = (Link)malloc(sizeof(LNode));
    if (!p) return ERROR;
    p->next = NULL;
    L.head = L.tail = p;
    L.len = 0;
}

Status LocatePos(LinkList L, int i, Link &p) {

    if (i < 0 || i > L.len) return ERROR;
    p = L.head;
    while (j <= i) {
        p = p.next; ++j;
    }
    return OK;
}

Status MakeNode(Link &p, ElemType e) {
    p = (Link)malloc(sizeof(LNode));
    if (!p) return ERROR;
    p->data = e;
}

Status FreeNode(Link &p) {
    free(p);
    p = NULL;
    return OK
}

Status InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}

Status ListEmpty(LinkList L) {
    if (L.len == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

Status GetHead(LinkList L) {
    return L.head;
}

int ListLength(LinkList L) {
    return L.len;
}

Position NextPos(LinkList L, Link p) {
    if (L.tail == p) return NULL; // 如果p是最后一个节点 返回NULL
    return p->next;
}

ElemType GetCurElem(Link p) {
    return p->data;
}

ElemType GetElem(LinkList L, int i) {
    Link cur_node;
    cur_node = L.head->next;
    int j = 1;
    if (L.len < i) return ERROR;
    while(cur_node->next && i > j) {
        cur_node = cur_node->next;
        ++j;
    }

    return cur_node->data;
}

Status SetCurElem(Link &p, ElemType e) {
    p->data = e;
    return OK;
}

Status Append(LinkList &L, Link s) {
    int i = 1;
    L.tail->next = s;
    while (s->next != NULL) {
        s = s-next;
        ++i;
    }
    L.tail = s;
    L.len = i;
    return OK;
}

Status DelFirst(Link h, Link &q) {
    if (h->next == NULL) return ERROR;
    q = h->next; // 把头节点所指向的第一个节点赋值给q
    h->next = q->next; // 去掉第一个节点
    q->next = NULL;
    return OK;
}

Status LinstInsert_L(LinkList &L, int i, ElemType e) {
    Link h, s;
    if (!LocatePos(L, i - 1, h)) return ERROR;
    if (!MakeNode(s, e)) return ERROR;
    InsFirst(h, s); // 插入s新节点到h的位置
    return OK;
}

Status MergeList_L(
        LinkList &La,
        LinkList &Lb,
        LinkList &Lc,
        int (*compare)(ElemType, ElemType)) {
    Link pa, ha, pb, hb;

    if (!InitList(Lc)) return ERROR;
    ha = GetHead(La);
    pa = NextPos(La, ha);
    hb = GetHead(Lb);
    pb = NextPos(Lb, hb);
    while (pa && pb) {
        a = GetCurElem(pa);
        b = GetCurElem(pb);
        if ((*compare)(a, b) <= 0) { // a <= b
            DelFirst(ha, q);
            Append(Lc, q);
            pa = NextPos(La, ha);
        }
        else {
            DelFirst(hb, q);
            Append(Lc, q);
            pb = NextPos(Lb, hb);
        }
    } // while
    if (pa) Append(Lc, pa);
    else Append(Lc, pb);
    FreeNode(ha);
    FreeNode(hb);
    return OK;
}

Status LinkListTraverse(LinkList s, Status (*visit)(Link)) {
    Link cur_node;
    cur_node = s.head->next;
    while (cur_node->next) {
        visit(cur_node);
        cur_node = cur_node->next;
    }
    return OK;
}

Status visit_display(Link p) {
    printf("%d ", p->data);
    return TRUE;
}

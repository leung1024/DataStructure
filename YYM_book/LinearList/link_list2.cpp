

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
        p = p.next;
        ++j;
    }
    return OK;
}

Status MakeNode(Link &p, ElemType e) {
    p = (Link)malloc(sizeof(LNode));
    if (!p) return ERROR;
    p->data = e;
}

Status InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}

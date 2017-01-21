


DuLinkList GetElemP_DuL(DuLinkList &L, int i) {
    // 当第i个元素存在时返回指针
    DuLinkList p;
    p = L->next; 
    int j = 1; // 计数器
    if (!L->next) return ERROR;
    while (p != L && j < i) {
        p = p->next;
        ++j;
    }
    if (p == L & j < i)
        return NULL; // 第i个元素不存在
    else
        return p;
}


Status LinkInsert_DuL(DuLinkList &L, int i, ElemType e) {
    DuLinkList s, p;
    if (!p = GetElemP_DuL(L, i))
        return ERROR;
    if (!s = (DuLinkList)malloc(sizeof(DuLNode)))
        return ERROR;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

Status LinkDelete_DuL(DuLinkList &L, int i, ElemType &e) {
    // 删除第i个元素
    DuLinkList p;
    if (!(p = GetElemP_DuL(L, i)))
        return ERROR;
    e = p->data;
    p->prior->next = p->next; // 重新设定下一个元素的指针
    p->next->prior = p->prior; // 重新设定上一个元素的指针
    free(p);
    return OK;
}




int cmp(term a, term b) {
    if (a.expn == b.expn) {
        return 0;
    }
    else if (a.expn < b.expn) {
        return -1;
    }
    else return 1;

int compare(ElemType a, ElemType b) {
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

Status LocateElem(
        LinkList L,
        term e,
        position &q,
        int (*cmp)(term, term)) {
    int i = 1;
    q = L.tail;
    while (q->next && cmp(e, q->data) > 0) {
        q = q->next; 
    }
    return OK;
}

Status CreatePolyn(polynomail &p, int m) {
    int i;
    InitList(p);
    h = GetHead(p);
    e.coef = 0.0;
    e.empn = -1;
    SetCurElem(h, e);
    for (i = 1; i <= m; ++i) {
        scanf(e.coef, e.expn);
        if (!LocateElem(p, e, q, (*cmp)())) { // 如果没找到e则把q插入进链表中
            if (MakeNode(s, e)) {
                InsFirst(q, s);
            }
        }
    }
    return OK;
}

Status AddPolyn(polynomail &Pa, polynomail &Pb) {
    Link pa, pb;
    LinkList ha, hb;
    term a, b;
    ElemType new_term;
    int sum;
    ha = GetHead(Pa);
    pa = NextPos(Pa, ha);
    hb = GetHead(Pb);
    pb = NextPos(Pb, hb);
    while (pa && pb) {
        a = GetCurElem(pa);
        b = GetCurElem(qb);
        switch (*cmp(a, b)) {
            case -1:
                qa = NextPos(Pa, pa);
                break;
            case 0:
                sum = a.coef + b.coef;
                if (sum != 0.0) {
                    new_term.coef = sum;
                    new_term.expn = a.expn;
                    SetCurElem(pa, new_term);
                }
                else {
                    DelFirst(ha, pa);
                    FreeNode(pa);
                }
                DelFirst(hb, pb);
                FreeNode(pb);
                pb = NextPos(Pb, hb);
                pa = NextPos(Pa, ha);
        } // switch
    } // while
    if (!ListEmpty(Pb)) Append(Pa, pb);
    FreeNode(hb);
}


#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"

Status InitList_Sq(struct SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (! L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//插入
Status ListInsert_Sq(struct SqList &L, int i, ElemType e) {
    ElemType * newbase;
    int *q, *p;
    if(i < 1||i > L.length + 1) return ERROR;
    if(L.length >= L.listsize) {
        newbase = (ElemType *)realloc(L.elem,
                        (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    q = &(L.elem[i - 1]);
    for(p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;

    *q = e;
    ++L.length;
    return OK;
}

//删除
Status ListDelete_Sq(struct SqList &L, int i, ElemType e) {
    int *p, *q;
    if(i < 1|| i > L.length + 1) return ERROR;
    p = &(L.elem[i - 1]);
    e = *p;
    q = &(L.elem[L.length - 1]);
    for(++p; p <= q ; ++p) *(p - 1) = *p;
    --L.length;
    return OK;

}

//查找
int LocateElem_Sq(struct SqList L, ElemType e,
                    Status (*compare)(ElemType, ElemType)) {
    int i = 1;          //i的初值为第一个元素
    int *p;
    p = L.elem;
    while(i <= L.length && !(*compare)(*p++, e)) ++i;
    if(i <= L.length) return i;
    else return 0;
}

//顺序合并
void MergeList_Sq(struct SqList La, struct SqList Lb, struct SqList &Lc) {
    int *pa_last, *pb_last;
    int *pa, *pb, *pc;
    InitList_Sq(Lc);
    pa = La.elem; pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem) exit(OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while (pa <= pa_last) *pc++ = *pa++;
    while (pb <= pb_last) *pc++ = *pb++;
}

















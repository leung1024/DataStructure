#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"

Status InitList_Sq(struct SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (! L.elem) exit(OVERFLOW);
    L.length = 0; // 表中当前元素个数
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

// 插入
Status ListInsert_Sq(struct SqList &L, int i, ElemType e) {
    // 时间复杂度为O(n)
    ElemType *newbase; // 新基地址 重新分配
    int *q, *p;
    if(i < 1||i > L.length + 1) return ERROR;
    if(L.length >= L.listsize) {
        newbase = (ElemType *)realloc(L.elem,
                        (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    q = &(L.elem[i - 1]); // 第i个元素的位置节点
    for(cur_node = &(L.elem[L.length - 1]); cur_node >= q; --cur_node) { // 从最后一个元素开始
        *(cur_node + 1) = *cur_node;
    }

    *q = e; // 对第i个节点赋值
    ++L.length;
    return OK;
}

// 删除
Status ListDelete_Sq(struct SqList &L, int i, ElemType e) {
    int *p, *q;
    if(i < 1|| i > L.length + 1) return ERROR;
    p = &(L.elem[i - 1]); // 第i个位置
    e = *p; // 可能需要用到被删元素的值
    q = &(L.elem[L.length - 1]); // 最后一个位置
    for(++p; p <= q ; ++p) {
        *(p - 1) = *p; // 覆盖掉前面的节点
    }
    --L.length;
    return OK;

}

// 按值查找
int LocateElem_Sq(struct SqList L, ElemType e,
                    Status (*compare)(ElemType, ElemType)) {
    int i = 1;          //i的初值为第一个元素
    int *p;
    p = L.elem;
    while (i <= L.length && (*compare)) {
        (*p++, e)) ++i;
    }
    if (i <= L.length) return i;
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

Status Reverse_Sq(SqList &L) {
    int mid_position = L.length / 2 - 1; // 到中间停止
    int tmp, i = 0, last_index = L.length - 1;
    while (i <= mid_position) {
        if (i == last_index - i) break; // 长度为奇数时中间的元素不用操作
        tmp = L.elem[i];
        L.elem[i] = L.elem[last_index - i];
        L.elem[last_index - i] = tmp;
        ++i;
    }
    return OK;
}

int compare_num(ElemType a, ElemType b) {
    if (a < b) {
        return 1;
    }
    else if (a == b) {
        return 0;
    }
    else return -1
}

int compare_list(SqList La, SqList Lb) {
    int i = 0;
    while (i < La.length && i < Lb.length) {
        if (La.elem[i] == Lb.elem[i])
            i++;
        else if (La.elem[i] < Lb.elem[i])
            return -1;
        else
            return 1;
    }
    if (i > La.length && i > Lb.length) return 0; // 两表相等
    else if (i > Lb.length) return 1;
    else return -1;
}














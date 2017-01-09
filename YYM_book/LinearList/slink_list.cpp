


int LocateElem_SL(SLinkList S, ElemType e) {
    int i = S[0].cur;
    while (i && s[i].cur != e) i = S[i].cur; // 找出要查询的e的游标
    return i;
}

void InitSpce_SL(SLinkList &space) {
    // 将一位数组space链成一个链表
    // space[i].cur 是指针
    for (i = 0; i < MAXSIZE - 1; ++i) space[i].cur = i + 1;
    // 位置0 为尾部空指针
    space[MAXSIZE - 1] = 0;
}

int Malloc_SL(SLinkList &space) {
    // 备用链表即存放空闲的位置
    // 若备用链表非空，则返回分配的节点下标,并将后一个可用节点提前
    i = space[0].cur;
    if (space[0].cur) space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList &space, int k) {
    // 将下标为k的空间节点回收到备用链表,类似于插入
    // 将第k个space连接到首位
    // space[0].cur -> space[k].cur -> 原space[0].cur 
    space[k].cur = space[0].cur;
    // 将首位space连接到k
    space[0].cur = k;
}

// (A-B)U(B-A)
void differece(SLiknList &space, int &S) {
    int m, n, j, i;
    // 创建备用链表
    InitSpce_SL(space);
    // 获取可用空间(空闲下标)
    S = Malloc_SL(space);
    int r = S; // r指向备用空的当前可用节点
    scanf(m, n); // AB集合的元素个数
    for (j = 1; j <= m, ++j) {
        i = Malloc_SL(space);
        scanf(space[i].data);
        space[r].cur = i; // 将上一个节点或第一个节点连接到下标i
        r = i;
    }
    space[r].cur = 0; // 结尾指针为0
    for (j = 1; j <= n; ++j) {
        scanf(b); // 输入B的元素
        p = S; // p指向首个地址下标
        k = space[p].cur; // k指向第一个元素 
        while (k != 0 && space[k].data != b) { // 看看输入的b在当前表中是否存在
            p = k;
            k = space[k].cur; // k 指向下一个元素
        }
        if (k == space[r].cur) { // 找到最后一个都没找到相同的,则在结尾插入
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur; // 结尾指针置零
            space[r].cur = i; // 更新前结尾指针
        }
        else {
            space[p].cur = space[k].cur; // 下标p是与b相等的元素的前一个下标
            Free_SL(space, k);
            if (r == k) r = p;
        }
    }

}


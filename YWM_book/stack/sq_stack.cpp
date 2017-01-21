
Status InitStack(SqStack &s) {
    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s.base) exit(OVERFLLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack s, SElemType &e) {
    if (s.top == s.base) return ERROR;
    e = *(s.top - 1); // 栈顶减以指向顶部元素
    return OK;
}

Status TraverseStack(SqStack s, Status (*vist)(SElemType)) {
    SElemType *p;
    p = s.base;
    while (p != s.top) {
        visit(*p);
        p++:
    }
    return OK;
}

Status StackEmpty(SqStack &s) {
    if (s.base == s.top) {
        return TRUE;
    }
    else {
        return FLASE;
    }
}

Status Push(SqStack &s, SElemType e) {
    if (s.top - s.base >= s.stacksize) {
        s.base = (SElemType *)realloc(
                s.base,
                (s.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!s.base) exit(OVERFLOW);
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status Pop(SqStack &s, SElemType &e) {
    if (s.top == s.base) return ERROR;
    e = *(s.top - 1);
    s.top--;
    return OK;
}

Status CleanStack(SqStack &s) {
    s.top = s.base;
    return OK;
}

Status DestoryStack(SqStack &s) {
    free(s.base);
    s.base = NULL;
    return OK;
}

Status visit_display(SElemType e) {
    printf('%c', e);
    return OK;
}




Status InitStack(LinkStack top) {
    top->next = NULL;
    return OK;
}

Status LinkStackEmpty(LinkStack &s) {
    if top->next == NULL
        return TRUE;
    else
        return FALSE;
}

Status Push(LinkStack &top, SElemType e) {
    StackNode new_top;
    new_top = (*StackNode)malloc(sizeof(StackNode));
    if (!new_top) return ERROR;
    new_top.data = e;
    new_top.next = top->next;
    top->next = new_top;
    return OK;
}

Status Pop(LinkStack &top, SElemType &e) {
    if (LinkStackEmpty) return ERROR;
    StackNode del_node;
    del_node = top->next;
    e = del_node->data;
    top->next = del_node->next;
    free(del_node)
    return OK; 
}


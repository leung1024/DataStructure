


Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) {
		exit(OVERFLOW);
	}
	Q.front->next = NULL;
	return	OK;
}

Status DestroyQueue(LinkQueue &Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
	QueuePtr new_node;
	new_node = (QueuePtr)malloc(sizeof(QNode));
	if (!new_node) {
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
	QueuePtr p;
	if (Q.front == Q.rear) {
		return ERROR;
	}
	p = Q.fornt->next; // 第一个节点
	e = p->data;
	Q.fornt->next = p->next;
	if (Q.rear == p) { // 出队时最后一个节点时比较特殊
		Q.rear = Q.front;
	}
	free(p);
	return OK;
}


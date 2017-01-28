Status InitQueue(SqQueue &Q) {
	Q.base = (SqQueue*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) {
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue &Q, QElemType e) {
	if ((Q.rear + 1) % Q.queuesize == front) { // 判断是否满了 2 % 3 = 2
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
}

Status DeQueue(SqQueue &Q, QElemType &e) {
	if (Q.rear == Q.front) {
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
}

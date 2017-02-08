

Status CreateBiTree(BiTree &T) {
	char ch;
	scanf(&ch);
	if (ch == '') {
		T = NULL;
	}
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) {
			exit(OVERFLOW);
		}
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	if (T) {
		visit(T->data);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	if (T) {
		PreOrderTraverse(T->lchild, visit);
		visit(T->data);
		PreOrderTraverse(T->rchild, visit);
	}
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	if (T) {
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
		visit(T->data);
	}
}

Status InOrderTraverse2(BiTree T, Status (*visit)(TElemType e)) {
	InitStack(s);
	p = T;
	while(p != NULL || !StackEmpty(s)) {
		if (p != NULL) {
			Push(s, p);
			p = p->lchild;
		}
		else {
			p = Pop(s); // 空节点返回到双亲
			visit(p->data);
			p = p->rchild;
		}
	}
}

Status display(TElemType e) {
	printf('%s', e);
	return OK;
}
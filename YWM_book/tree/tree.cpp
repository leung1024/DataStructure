

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
	BiTree p = T;
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

Status PostOrderTraverse2(BiTree T, Status (*visit)(TElemType e)) {
	InitStack(s);
	BiTree p = T, tmp;
	while(p != NULL || !StackEmpty(s)) {
		if (p != NULL) {
			Push(s, p);
			p = p->lchild;
		}
		else {
			p = Pop(s); // 空节点返回到双亲
			if (p != NULL) {
				tmp = p;
			}
			p = p->rchild;
			if (p == NULL) {
				visit(tmp->data);
			}
		}
	}
}

Status display(TElemType e) {
	printf('%s', e);
	return OK;
}

int CountLeaf(BiTree T, int &count) {
	if (T) {
		if (T->lchild == T->rchild == NULL) {
			count++;
		}
		CountLeaf(T->lchild, count);
		CountLeaf(T->rchild, count);
	}
}

int Depth(BiTree T) {
	int depthLeft = depthRight = depthval = 0;
	if (!T) {
		depthval = 0;
	}
	else {
		depthLeft = Depth(T->lchild); // 根节点数左子树最大值（即深度最大值）
		depthRight = Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}
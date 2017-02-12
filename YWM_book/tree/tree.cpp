

Status CreateBiTree(BiTree &T) {
	char ch;
	scanf(&ch);
	if (ch == '') {
		T = NULL;
	} else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) {
			exit(OVERFLOW);
		}
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status CreateBiTree2(BiTree &T) {
	scanf(&ch);
	if (ch == ' ') {
		T = NULL;
	} else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) {
			exit(OVERFLOW);
		}
		T->data = ch;
		CreateBiTree2(T->lchild);
		CreateBiTree2(T->rchild);
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

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	BiTree Queue[MAX_TREE_TREE];
	int front, rear;
	if (T == NULL) return ERROR;
	front = -1;
	rear = 0;
	Queue[rear] = T;
	while(front != rear) {
		++front;
		visit(Queue[front]->data);
		if (Queue[front]->lchild != NULL) {
			Queue[++rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild != NULL) {
			Queue[++rear] = Queue[front]->rchild;
		}
	} 
}

Status InOrderTraverse2(BiTree T, Status (*visit)(TElemType e)) {
	InitStack(s);
	BiTree p = T;
	while(p != NULL || !StackEmpty(s)) {
		if (p != NULL) {
			Push(s, p);
			p = p->lchild;
		} else {
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
		} else {
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
	} else {
		depthLeft = Depth(T->lchild); // 根节点数左子树最大值（即深度最大值）
		depthRight = Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}

BiTree CreateTreeNode(TElemType item, BiTree *lptr, BiTree *rptr) {
	if (!(T = (*BiTNode)malloc(sizeof(BiTNode)))) {
		return exit(ERROR);
	} else {
		T->data = item;
		T->lchild = lptr;
		T->rchild = rptr;
		return T;
	}
}

BiTree CopyTree(BiTree T) {
	BiTree *newlptr, *newrptr, newT;
	if (!T) return NULL;
	if (T->lchild) {
		newlptr = CopyTree(T->lchild);
	} else {
		newlptr = NULL;
	}
	if (T->rchild) {
		newrptr = CopyTree(T->rchild);
	} else {
		newrptr = NULL;
	}
	newT = CreateTreeNode(T->data, newlptr, newrptr);
	return newT;
}
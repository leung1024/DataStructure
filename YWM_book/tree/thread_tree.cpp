Status InOrderTraverse_Thr(BiThrTree T, Status (*visit)(TElemType e)) {
	BiThrNode *p;
	p = T->lchild; // p指向根节点
	while(p != T) {
		while(p->LTag == Link) {
			p = p->lchild;
		}
		if (!visit(p->data)) {
			return ERROR;
		}
		while(p->RTag == Thread && p->rchild != T) { // 找后继，p->rchild 指向后继
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

Status InorderThreading(BiThrTree &Thrt, BiThrTree T) {
	BiThrTree pre;
	if (!Thrt = (BiThrTree)malloc(sizeof(BiThrNode))) {
		exit(OVERFLOW);
	}
	Thrt->LTag = Link; // 头结点
	Thrt->RTag = Thread; // 头结点
	Thrt->rchild = Thrt; // 右指针回指
	if (!T) {
		Thrt->lchild = Thrt;
	} else {
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T); // 中序遍历进行线索化
		pre->rchild = Thrt; // 最后一个节点的线索化
		pre->RTag = Thread;
		Thrt->rchild = pre;
	}
	return OK;
}

Status Inthreading(BiThrTree &p) {
	BiThrTree pre = p;
	if (p) {
		Inthreading(p->lchild);
		if (!p->lchild) { // 前驱线索
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild) { // 后继线索
			p->RTag = Thread;
			pre->rchild = p;
		}
		pre = p; // p为pre的后继 p为当前节点
		InThreading(p->rchild); // 右子树线索化
	}
	return OK;
}
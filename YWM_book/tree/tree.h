
// typedef TElemType SqBiTree[MAX_TREE_TREE]; // 0 号放根节点
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree; // root就是节点指针结构BiTree类型

typedef struct TriTNode {
	TElemType data;
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;

}TriTNode, *TriTree; // 三叉链表

Status CreateBiTree(BiTree &T);
// 构造二叉树
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
// 先根遍历(递归描述)
// visit是对节点操作的函数
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
// 中根遍历(递归描述)
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));
// 后根遍历(递归描述)
Status PreOrderTraverse2(BiTree T, Status (*visit)(TElemType e));
// 先根遍历(非递归描述)
// visit是对节点操作的函数
Status InOrderTraverse2(BiTree T, Status (*visit)(TElemType e));
// 中根遍历(非递归描述)
Status PostOrderTraverse2(BiTree T, Status (*visit)(TElemType e));
// 后根遍历(非递归描述)
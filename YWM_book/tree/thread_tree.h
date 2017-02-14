typedef enum {Link, Thread} PointerThr;
// Link == 0 指针；Tread == 1 线索
typedef struct  BiThrNode {
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerThr LTag, RTag;
}BiThrNode, *BiThrTree;

Status CreateBiThrTree(BiThrTree &T);
// 构造二叉树
Status InOrderTraverse_Thr(BiThrTree T, Status (*visit)(TElemType e));
// 中序线索化链表的遍历
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

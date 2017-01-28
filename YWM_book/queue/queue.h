
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear; // 队尾指针
}LinkQueue

Status InitQueue(LinkQueue &Q);
// 链队列初始化
Status DestroyQueue(LinkQueue &Q);
// 销毁队列
Status EnQueue(LinkQueue &Q, QElemType e);
// 入队操作
Status DeQueue(LinkQueue &Q, QElemType &e);
// 出队操作
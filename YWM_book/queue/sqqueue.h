#define MAXQSIZE 100


typedef struct {
	QElemType *base; // 初始化动态分配内存空间
	int	front;
	int rear; // 尾指针，指向队列尾元素的下一个位置
	int queuesize;
}SqQueue;

Status InitQueue(SqQueue &Q);
// 循环队列初始化
Status EnQueue(SqQueue &Q, QElemType e);
// 入队
Status DeQueue(SqQueue &Q, QElemType &e);
// 出队
Status GetHead(SqQueue Q, QElemType &e);
// 获取队头元素
int QueueLength(SqQueue Q);
// 计算队列长度
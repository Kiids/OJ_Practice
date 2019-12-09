/*
������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ��������� 
ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ�
���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
���ʵ��Ӧ��֧�����²�����
MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������
ʾ����
MyCircularQueue circularQueue = new MycircularQueue(3); // ���ó���Ϊ 3
circularQueue.enQueue(1);  // ���� true
circularQueue.enQueue(2);  // ���� true
circularQueue.enQueue(3);  // ���� true
circularQueue.enQueue(4);  // ���� false����������
circularQueue.Rear();  // ���� 3
circularQueue.isFull();  // ���� true
circularQueue.deQueue();  // ���� true
circularQueue.enQueue(4);  // ���� true
circularQueue.Rear();  // ���� 4
��ʾ��
���е�ֵ���� 0 �� 1000 �ķ�Χ�ڣ�
���������� 1 �� 1000 �ķ�Χ�ڣ�
�벻Ҫʹ�����õĶ��п⡣
*/

typedef struct {
    int* queue;
    int front;
    int rear;
    int len;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->queue = (int*)malloc(sizeof(int)*(k+1));
    q->front = 0;
    q->rear = 0;
    q->len = k+1;
    return q;
}

bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->queue[obj->rear] = value;
    obj->rear++;
    if (obj->rear == obj->len)
        obj->rear = 0;
    return true;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->front++;
    if (obj->front == obj->len)
        obj->front = 0;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    if (obj->rear == 0)
        return obj->queue[obj->len-1];
    else
        return obj->queue[obj->rear-1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == (obj->rear+1) % obj->len;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    obj->queue = NULL;
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/


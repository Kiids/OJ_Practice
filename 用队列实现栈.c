// 使用队列实现栈的下列操作：
// push(x) -- 元素 x 入栈
// pop() -- 移除栈顶元素
// top() -- 获取栈顶元素
// empty() -- 返回栈是否为空
// 注意:
// 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
// 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
// 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;  // 队头
	QueueNode* _rear;   // 队尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* node = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_rear = node;
	}
	else
	{
		pq->_rear->_next = node;
		pq->_rear = node;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&(s->q1));
    QueueInit(&(s->q2));
    
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (QueueEmpty(&(obj->q1)))
        QueuePush(&(obj->q2), x);
    else
        QueuePush(&(obj->q1),x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue* empty = &(obj->q1);
    Queue* nonempty = &(obj->q2);
    if (QueueEmpty(&(obj->q2)))
    {
        empty = &(obj->q2);
        nonempty = &(obj->q1);
    }
    while (QueueSize(nonempty) > 1)
    {
        QueuePush(empty, QueueFront(nonempty));
        QueuePop(nonempty);
    }
    int top = QueueFront(nonempty);
    QueuePop(nonempty);
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    Queue* empty = &(obj->q1);
    Queue* nonempty = &(obj->q2);
    if (QueueEmpty(&(obj->q2)))
    {
        empty = &(obj->q2);
        nonempty = &(obj->q1);
    }
    int top = 0;
    while (QueueSize(nonempty) > 0)
    {
        if (QueueSize(nonempty) == 1)
            top = QueueFront(nonempty);
        QueuePush(empty, QueueFront(nonempty));
        QueuePop(nonempty);
    }
    return top;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj) {
    QueueDestory(&(obj->q1));
    QueueDestory(&(obj->q2));
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/


// ʹ��ջʵ�ֶ��е����в�����
// push(x) -- ��һ��Ԫ�ط�����е�β����
// pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
// peek() -- ���ض����ײ���Ԫ�ء�
// empty() -- ���ض����Ƿ�Ϊ�ա�
// ʾ��:
// MyQueue queue = new MyQueue();
// queue.push(1);
// queue.push(2);  
// queue.peek();  // ���� 1
// queue.pop();   // ���� 1
// queue.empty(); // ���� false
// ˵��:
// ��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
// ����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
// �������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* s);
void StackDestory(Stack* s);

void StackPush(Stack* s, STDataType x);
void StackPop(Stack* s);
STDataType StackTop(Stack* s);
bool StackEmpty(Stack* s);
int StackSize(Stack* s);

void TestStack();

void StackInit(Stack* s)
{
	assert(s);
	s->_a = NULL;
	s->_top = s->_capacity = 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	if (s->_a != NULL)
	{
		free(s->_a);
		s->_a = NULL;
		s->_top = s->_capacity = 0;
	}
}

void StackPush(Stack* s, STDataType x)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		s->_capacity = (s->_capacity == 0) ? 2 : 2 * s->_capacity;
		s->_a = (STDataType*)realloc(s->_a, sizeof(STDataType)*s->_capacity);
	}
	s->_a[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s && s->_top > 0);
	s->_top--;
}

STDataType StackTop(Stack* s)
{
	assert(s && s->_top > 0);
	return s->_a[s->_top - 1];
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

typedef struct {
    Stack pushst;
    Stack popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->pushst);
    StackInit(&q->popst);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&(obj->pushst), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (StackEmpty(&(obj->popst)))
    {
        while (!StackEmpty(&(obj->pushst)))
        {
            StackPush(&(obj->popst), StackTop(&(obj->pushst)));
            StackPop(&(obj->pushst));
        }
    }
    int top = StackTop(&(obj->popst));
    StackPop(&(obj->popst));
    return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&(obj->popst)))
    {
        while (!StackEmpty(&(obj->pushst)))
        {
            StackPush(&(obj->popst), StackTop(&(obj->pushst)));
            StackPop(&(obj->pushst));
        }
    }
    int top = StackTop(&(obj->popst));
    return top;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&(obj->pushst)) && StackEmpty(&(obj->popst));
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&(obj->pushst));
    StackDestory(&(obj->popst));
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/


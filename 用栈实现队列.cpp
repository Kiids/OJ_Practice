// ʹ��ջʵ�ֶ��е����в�����
// push(x) -- ��һ��Ԫ�ط�����е�β����
// pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
// peek() -- ���ض����ײ���Ԫ�ء�
// empty() -- ���ض����Ƿ�Ϊ�ա�

#include <stack>

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	if (s2.empty())
        {
            if (s1.empty())
                return -1;
            
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty())
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        int top = s2.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// 使用队列实现栈的下列操作：
// push(x) -- 元素 x 入栈
// pop() -- 移除栈顶元素
// top() -- 获取栈顶元素
// empty() -- 返回栈是否为空

#include <queue>

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        /*queue<int> empty = q1;
        queue<int> nonempty = q2;
        if (q2.empty())
        {
            empty = q2;
            nonempty = q1;
        }
        
        while (nonempty.size() > 1)
        {
            empty.push(nonempty.front());
            nonempty.pop();
        }
        
        int top = nonempty.front();
        nonempty.pop();
        return top;*/  // 并没有实际更改q1和q2
        
        if (q1.empty())
        {
            int len = q2.size();
            for(int i = 0; i < len - 1; i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int ret = q2.front();
            q2.pop();
            return ret;
            
        }
        else
        {
            int len = q1.size();
            for(int i = 0; i < len - 1; i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ret = q1.front();
            q1.pop();
            return ret;
        }
    }
    
    /** Get the top element. */
    int top() {
        queue<int> empty = q1;
        queue<int> nonempty = q2;
        if (q2.empty())
        {
            empty = q2;
            nonempty = q1;
        }
        
        int top = 0;
        while (nonempty.size() > 0)
        {
            if (nonempty.size() == 1)
                top = nonempty.front();
            empty.push(nonempty.front());
            nonempty.pop();
        }
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

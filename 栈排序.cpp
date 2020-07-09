/*
ջ���� ��д���򣬶�ջ��������ʹ��СԪ��λ��ջ�������ֻ��ʹ��һ����������ʱջ������ݣ������ý�Ԫ�ظ��Ƶ�������ݽṹ�������飩�С���ջ֧�����²�����push��pop��peek �� isEmpty����ջΪ��ʱ��peek?���� -1��
ʾ��1:
 ���룺
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
 �����
[null,null,null,1,null,2]
ʾ��2:
 ���룺 
["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
[[], [], [], [1], [], []]
 �����
[null,null,null,null,null,true]
˵��:
ջ�е�Ԫ����Ŀ��[0, 5000]��Χ�ڡ�
*/

class SortedStack {
public:
    stack<int> s1, s2;
    SortedStack()
	{
        
    }
    
    void push(int val)
	{
        while (!s1.empty() && s1.top() < val)
		{
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty())
		{
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop()
	{
        if(!s1.empty())
            s1.pop();
    }
    
    int peek()
	{
        if(!s1.empty())
            return s1.top();
        return -1;
    }
    
    bool isEmpty()
	{
        return s1.empty();
    }

};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

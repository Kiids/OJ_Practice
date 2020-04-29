/*
�붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��Ҫ����max_value��push_back �� pop_front �ľ�̯ʱ�临�Ӷȶ���O(1)��
������Ϊ�գ�pop_front �� max_value?��Ҫ���� -1
ʾ�� 1��
����: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
���: [null,null,null,2,1,2]
ʾ�� 2��
����: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
���: [null,-1,-1]
���ƣ�
1 <= push_back,pop_front,max_value���ܲ�����?<= 10000
1 <= value <= 10^5
*/

class MaxQueue {
    queue<int> q;
    deque<int> max;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (max.empty())
            return -1;
        return max.front();
    }
    
    void push_back(int value) {
        while (!max.empty() && max.back() < value)
            max.pop_back();
        max.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ret = q.front();
        if (ret == max.front())
            max.pop_front();
        q.pop();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

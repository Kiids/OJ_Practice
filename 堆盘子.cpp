/*
�����ӡ�������һ�����ӣ���̫�߿��ܻᵹ��������ˣ�����ʵ�����У����Ӷѵ�һ���߶�ʱ�����Ǿͻ������һ�����ӡ���ʵ�����ݽṹSetOfStacks��ģ��������Ϊ��SetOfStacksӦ���ɶ��ջ��ɣ�������ǰһ��ջ����ʱ�½�һ��ջ�����⣬SetOfStacks.push()��SetOfStacks.pop()Ӧ������ͨջ�Ĳ���������ͬ��Ҳ����˵��pop()���ص�ֵ��Ӧ�ø�ֻ��һ��ջʱ�����һ������ ���ף�ʵ��һ��popAt(int index)����������ָ������ջ��ִ��pop������
��ĳ��ջΪ��ʱ��Ӧ��ɾ����ջ����ջ��û��Ԫ�ػ򲻴��ڸ�ջʱ��pop��popAt?Ӧ���� -1.
ʾ��1:
 ���룺
["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
[[1], [1], [2], [1], [], []]
 �����
[null, null, null, 2, 1, -1]
ʾ��2:
 ���룺
["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
[[2], [1], [2], [3], [0], [0], [0]]
 �����
[null, null, null, null, 2, 1, 3]
*/

class StackOfPlates {
    int size;
    vector<stack<int> > stack_sets;
public:
    StackOfPlates(int cap) {
        size=cap;
    }
    
    void push(int val) {
        if (size == 0)
            return;
        if (stack_sets.size() == 0 || stack_sets[stack_sets.size() - 1].size() == size)
        {
            stack<int> tmp;
            tmp.push(val);
            stack_sets.push_back(tmp);
        }
        else
            stack_sets[stack_sets.size()-1].push(val);
    }
    
    int pop() {
        if (stack_sets.size() == 0)
            return -1;
        int ret = stack_sets[stack_sets.size() - 1].top();
        stack_sets[stack_sets.size() - 1].pop();
        if (stack_sets[stack_sets.size() - 1].empty())
        {
            auto it = stack_sets.end();
            it--;
            stack_sets.erase(it);
        }
        return ret;
    }
    
    int popAt(int index) {
        if (stack_sets.size() == 0 || index < 0 || index >= stack_sets.size())
            return -1;
        int ret = stack_sets[index].top();
        stack_sets[index].pop();
        if (stack_sets[index].empty())
            stack_sets.erase(stack_sets.begin() + index);
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

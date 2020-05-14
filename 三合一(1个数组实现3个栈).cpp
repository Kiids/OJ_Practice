/*
����һ���������ֻ��һ��������ʵ������ջ��
��Ӧ��ʵ��push(stackNum, value)��pop(stackNum)��isEmpty(stackNum)��peek(stackNum)������stackNum��ʾջ�±꣬value��ʾѹ���ֵ��
���캯���ᴫ��һ��stackSize����������ÿ��ջ�Ĵ�С��
ʾ��1:
 ���룺
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 �����
[null, null, null, 1, -1, -1, true]
˵������ջΪ��ʱ`pop, peek`����-1����ջ��ʱ`push`��ѹ��Ԫ�ء�
ʾ��2:
 ���룺
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 �����
[null, null, null, null, 2, 1, -1, -1]
*/

class TripleInOne {
    int *stack;
    int top[3];
    int size;
public:
    TripleInOne(int stackSize)
        : size(stackSize)
    {
        stack = new int[stackSize * 3];
        top[0] = top[1] = top[2] = 0;
    }
    
    void push(int stackNum, int value) {
        if (top[stackNum] < size)
            stack[size * stackNum + top[stackNum]++] = value;
    }
    
    int pop(int stackNum) {
        if (top[stackNum] == 0)
            return -1;
        else
            return stack[size * stackNum + (--top[stackNum])];
    }
    
    int peek(int stackNum) {
        if (top[stackNum] == 0)
            return -1;
        else
            return stack[size * stackNum + (top[stackNum] - 1)];
    }
    
    bool isEmpty(int stackNum) {
        return top[stackNum] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

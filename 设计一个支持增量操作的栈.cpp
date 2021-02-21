/*
�������һ��֧������������ջ��
ʵ���Զ���ջ�� CustomStack ��
CustomStack(int maxSize)���� maxSize ��ʼ������maxSize ��ջ����������ɵ�Ԫ��������ջ�������� maxSize ֮����֧�� push ������
void push(int x)�����ջ��δ������ maxSize ���ͽ� x ��ӵ�ջ����
int pop()������ջ��Ԫ�أ�������ջ����ֵ����ջΪ��ʱ���� -1 ��
void inc(int k, int val)��ջ�׵� k ��Ԫ�ص�ֵ������ val �����ջ��Ԫ������С�� k ����ջ�е�����Ԫ�ض����� val ��
ʾ����
���룺
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
�����
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
���ͣ�
CustomStack customStack = new CustomStack(3); // ջ�ǿյ� []
customStack.push(1);                          // ջ��Ϊ [1]
customStack.push(2);                          // ջ��Ϊ [1, 2]
customStack.pop();                            // ���� 2 --> ����ջ��ֵ 2��ջ��Ϊ [1]
customStack.push(2);                          // ջ��Ϊ [1, 2]
customStack.push(3);                          // ջ��Ϊ [1, 2, 3]
customStack.push(4);                          // ջ��Ȼ�� [1, 2, 3]�������������Ԫ��ʹջ��С��Ϊ 4
customStack.increment(5, 100);                // ջ��Ϊ [101, 102, 103]
customStack.increment(2, 100);                // ջ��Ϊ [201, 202, 103]
customStack.pop();                            // ���� 103 --> ����ջ��ֵ 103��ջ��Ϊ [201, 202]
customStack.pop();                            // ���� 202 --> ����ջ��ֵ 202��ջ��Ϊ [201]
customStack.pop();                            // ���� 201 --> ����ջ��ֵ 201��ջ��Ϊ []
customStack.pop();                            // ���� -1 --> ջΪ�գ����� -1
��ʾ��
1 <= maxSize <= 1000
1 <= x <= 1000
1 <= k <= 1000
0 <= val <= 100
ÿ�ַ��� increment��push �Լ� pop �ֱ������� 1000 ��
*/

class CustomStack {
public:
    vector<int> v;
    int top;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if (top != v.size() - 1)
        {
            top++;
            v[top] = x;
        }
    }
    
    int pop() {
        if (top == -1)
            return -1;

        top--;
        return v[top + 1];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++) 
            v[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

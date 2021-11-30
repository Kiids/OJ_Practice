/*
���� pushed �� popped �������У�ÿ�������е� ֵ�����ظ���ֻ�е����ǿ������������ջ�Ͻ��е����� push �͵��� pop �������еĽ��ʱ������ true�����򣬷��� false ��
ʾ�� 1��
���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
�����true
���ͣ����ǿ��԰�����˳��ִ�У�
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
ʾ�� 2��
���룺pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
�����false
���ͣ�1 ������ 2 ֮ǰ������
��ʾ��
1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
pushed ������Ԫ�� ������ͬ
popped.length == pushed.length
popped �� pushed ��һ������
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        for (int i = 0, j = 0; j < n;)
        {
            while (i < n && (s.empty() || s.top() != popped[j]))
                s.emplace(pushed[i++]);
            if (i == n && s.top() != popped[j])
                return false;
            while (j < n && !s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }
        return true;
    }
};

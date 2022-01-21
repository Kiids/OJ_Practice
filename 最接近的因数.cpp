/*
����һ������ num�������ҳ�ͬʱ��������ȫ��Ҫ�������������
�����˻�����  num + 1 �� num + 2
�Ծ��Բ���ж�����������С��ӽ�
����԰�����˳�򷵻�������������
ʾ�� 1��
���룺num = 8
�����[3,3]
���ͣ����� num + 1 = 9����ӽ������������� 3 & 3������ num + 2 = 10, ��ӽ������������� 2 & 5����˷��� 3 & 3 ��
ʾ�� 2��
���룺num = 123
�����[5,25]
ʾ�� 3��
���룺num = 999
�����[40,25]
��ʾ��
1 <= num <= 10^9
*/

class Solution {
    void Fun(int num, vector<int>& v)
    {
        for (int i = int(sqrt(num)); i > 0; i--)
        {
            if (num % i == 0)
            {
                if (abs(num / i - i) < abs(v[0] - v[1]))
                {
                    v[0] = num / i;
                    v[1] = i;
                }
            }
        }
    }
public:
    vector<int> closestDivisors(int num) {
        vector<int> v(2, 0);
        v[1] = 1e9;
        Fun(num + 1, v);
        Fun(num + 2, v);
        return v;
    }
};

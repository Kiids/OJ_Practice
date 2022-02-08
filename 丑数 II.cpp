/*
����һ������ n �������ҳ������ص� n �� ���� ��
���� ����ֻ���������� 2��3 ��/�� 5 ����������
ʾ�� 1��
���룺n = 10
�����12
���ͣ�[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] ����ǰ 10 ��������ɵ����С�
ʾ�� 2��
���룺n = 1
�����1
���ͣ�1 ͨ������Ϊ������
��ʾ��
1 <= n <= 1690
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        long ret = 1;
        priority_queue<long, vector<long>, greater<long>> q;
        for (int i = 1; i < n; i++)
        {
            q.push(ret * 2);
            q.push(ret * 3);
            q.push(ret * 5);

            ret = q.top();
            q.pop();

            while (q.top() == ret)
                q.pop();
        }
        return ret;
    }
};

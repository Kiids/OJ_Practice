/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n ����̨���ܹ��ж�����������
����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��
ʾ�� 1��
���룺n = 2
�����2
ʾ�� 2��
���룺n = 7
�����21
��ʾ��
0 <= n <= 100
*/

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum = 1;
        for (int i = 1; i < n; i++)
        {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};

// ���·��� ����ʱ������ ���ִ�е����룺43 
class Solution {
public:
    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;
        return numWays(n - 1) + numWays(n - 2);
    }
};

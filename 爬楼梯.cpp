/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������
ʾ�� 1��
���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
ʾ�� 2��
���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 3);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// dp״̬ѹ��
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int a = 1, b = 2, c = 0;
        for(int i = 3; i <= n; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

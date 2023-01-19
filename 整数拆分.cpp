/*
����һ�������� n��������Ϊ���������������ĺͣ���ʹ��Щ�����ĳ˻���󻯡� ��������Ի�õ����˻���
ʾ�� 1:
����: 2
���: 1
����: 2 = 1 + 1, 1 �� 1 = 1��
ʾ�� 2:
����: 10
���: 36
����: 10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36��
˵��: ����Լ��� n ��С�� 2 �Ҳ����� 58��
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        vector<int> dp(n + 1, 0);
        for (int i = 5; i <= n; i++)
            for (int j = 1; j < i - 1; j++)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        return dp[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++)
            for(int j = 1; j < i - 1; j++)
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        return dp[n];
    }
};

// ��dp[i]Ϊ�ֽ�i�ܵõ�������
// ����ÿһ�ַֽⷽʽ��ͨ��ѭ��������зֽⷽʽ�����ֵ
// dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
// i��3��nѭ��һ�Σ�һ������ϵõ�dp[n]
// �ڲ�ѭ��������Ϊj < i-1������Ϊj = i-1ʱ��dp[1]�ֽ��������
// ��ĿҪ��k >= 2��1�޷��ֽ�Ϊ�������������


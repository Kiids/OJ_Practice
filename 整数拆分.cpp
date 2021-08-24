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

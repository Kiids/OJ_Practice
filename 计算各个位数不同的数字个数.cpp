/*
����һ���Ǹ����� n�������λ���ֶ���ͬ������ x �ĸ��������� 0 �� x < 10^n ��
ʾ��:
����: 2
���: 91 
����: ��ӦΪ��ȥ 11,22,33,44,55,66,77,88,99 �⣬�� [0,100) �����ڵ��������֡�
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1);
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] * 10 + (9 * pow(10, i - 2) - dp[i - 1]) * (i - 1);
        int sum = 0;
        for (auto& x : dp)
            sum += x;
        return pow(10, n) - sum;
    }
};

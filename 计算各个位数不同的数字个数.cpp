/*
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
示例:
输入: 2
输出: 91 
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
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

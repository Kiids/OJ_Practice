/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
示例 1:
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
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

// 设dp[i]为分解i能得到的最大积
// 遍历每一种分解方式，通过循环获得所有分解方式的最大值
// dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
// i从3到n循环一次，一层层往上得到dp[n]
// 内层循环，条件为j < i-1，是因为j = i-1时对dp[1]分解毫无意义
// 题目要求k >= 2，1无法分解为两个正整数相加


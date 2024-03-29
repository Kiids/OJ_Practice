/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 0 - prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

// 股票买卖3个状态，
// dp[i][0] 第i天持有股票，昨天就持有且不卖出 or 今天买入 
// dp[i][1] 第i天卖出股票 
// dp[i][2] 第i天不持有股票
// 由状态机得状态转移方程
// dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
// dp[i][1]=dp[i-1][0]+prices[i];
// dp[i][2]=max(dp[i-1][1],dp[i-1][2]);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);  // 拥有股票的状态
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);  // 没有买入时，没有股票的状态
            dp[i][2] = dp[i - 1][0] + prices[i];  // 买入后，当天卖后没有股票的状态
            dp[i][3] = dp[i - 1][2];  // 卖后进入冻结期
        }
        return max(dp[n - 1][3], max(dp[n - 1][2], dp[n - 1][1]));  // 最后比较三个没有股票状态的最大值
    }
};

/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 
题目数据保证结果符合 32 位带符号整数。
示例 1：
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2：
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：
输入：amount = 10, coins = [10] 
输出：1
提示：
1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin : coins)
            for(int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        return dp[amount];
    }
};

//计算可能的组合数。用 dp[x] 表示金额之和等于 x 的硬币组合数，目标是求 dp[amount]。
//边界 dp[0]=1。当不选取任何硬币时，金额之和为 0，只有 1 种硬币组合。
//面额 coin 的硬币，当 coin≤i≤amount 时，如果存在一种硬币组合的金额之和等于 i - coin，
//则在该硬币组合中增加一个面额为 coin 的硬币，即可得到一种金额之和等于 i 的硬币组合。
//需要遍历 coins，对于每一种面额的硬币，更新数组 dp 中的每个大于或等于该面额的元素的值。


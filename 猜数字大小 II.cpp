/*
我们正在玩一个猜数游戏，游戏规则如下：
我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。
每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。
然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。
示例:
n = 10, 我选择了8.
第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。
游戏结束。8 就是我选的数字。
你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int l = 2; l <= n; l++)              // 区间长度
        {
            for (int i = 1; i <= n - l + 1; i++)  // 区间起点
            {
                int j = i + l - 1;
                int x = INT_MAX;
                for (int k = i; k < j; k++)
                    x = min(x, k + max(dp[i][k - 1], dp[k + 1][j]));
                dp[i][j] = x;
            }
        }
        return dp[1][n];
    }
};

// dp[i][j] 为选择的数字在区间[i,j]的所需的最小现金数。
// 考虑 dp[i][j] 可以选择的的数字 k∈[i,j]，
// 转移方程：
// dp[i][j] = min{i≤k≤j} {k + max(dp[i][k-1],dp[k+1][j])
// 区间长度大的状态需要利用区间长度小的状态转移而来，
// 第一层for枚举区间的长度，第二层for枚举区间的起点(左端点)，
// 有了区间的长度和起点(左端点)，计算区间的终点(右端点)，第三次 for 枚举猜的数字，即分界点。
// 初始化边界
// 时间复杂度：O(n^3)
// 空间复杂度：O(n^2)


class Solution {
    int v[201][201];
    int DFS(int left, int right)
    {
        if (left >= right)
            return 0; 
        if (v[left][right] != 0)
            return v[left][right];

        int ret = INT_MAX;
        for (int val = left; val <= right; val++)
        {
            int sub_left = DFS(left, val - 1);
            int sub_right = DFS(val + 1, right);
            int max_sub = max(sub_left, sub_right) + val;
            ret = min(ret, max_sub);
        }
        v[left][right] = ret;
        return ret;
    }
public:
    int getMoneyAmount(int n) {
        return DFS(1, n);
    }
};

//递归函数 int dfs(int left, int right) 入参在范围 [left, right] 内进行猜数，返回值在 [left, right] 内猜中数字至少需要多少钱。
//可决策的部分为「选择猜哪个数 x」，不可决策的是「选择某个数 x 之后（假设没有猜中），真实值会落在哪边」。
//确保你获胜 的最小现金数，不管我选择那个数字：
//「确保+不管」，是要选择当前节点下左右分支的「最大值」，才能「确保+不管」那些小的值都能取到，因此分支比较用 max
//「最小」，是要选择所有可能的结点值下，有一个结果即可，因此用 min


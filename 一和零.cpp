/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
提示：
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < strs.size(); i++)
        {
            int v1 = count(strs[i].begin(), strs[i].end(), '0'), v2 = strs[i].size() - v1;
            for (int j = m; j >= v1; j--)
                for (int k = n; k >= v2; k--)
                    dp[j][k] = max(dp[j][k], dp[j - v1][k - v2] + 1);
        }
        return dp[m][n];
    }
};

// 多花费01背包，共2个一个是1的个数，一个是0的个数
// 每个字符串可以看作一个物品，有2个花费，1的个数和0的个数，价值为1，子序列增加1
// d[j][k]: 代表前i个物品中0的个数最多为j,1的个数最多为k时的子集个数最大值


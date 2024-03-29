/*
给你一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
示例 1：
输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。
示例?2：
输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
提示：
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn = 1e5 + 50, ret;
        int v[maxn], dp[maxn];
        memset(v, 0, sizeof v);
        memset(dp, 0, sizeof dp);
        for (auto x : nums)
            v[x]++;
        dp[1] = 1 * v[1];
        for (int i = 2; i <= 10000; i++)
        {
            dp[i] = max(dp[i - 2] + i * v[i], dp[i - 1]);
            ret = max(ret, dp[i]); 
        }
        return ret;
    }
};

//dp[i] 表示删除元素i所能获得的最大点数
//v[i] 表示元素i的个数
//元素i的选择有删除和不删除两种状态：
//如果删除i，获得的点数是 dp[i] = dp[i - 2] + i * v[i]
//如果不删i，获得的点数是 dp[i - 1]
//转移方程：
//dp[i] = max(dp[i - 1],dp[i - 2] + i * v[i])


/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得?nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。?这里的 i - 1 和 i + 1 代表和?i?相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
求所能获得硬币的最大数量。
示例 1：
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
示例 2：
输入：nums = [1,5]
输出：10
提示：
n == nums.length
1 <= n <= 500
0 <= nums[i] <= 100
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int> > dp(nums.size(), vector<int> (nums.size(), 0));
        for (int l = 2; l < nums.size(); l++)
            for (int i = 0; i < nums.size() - l; i++)
                for (int k = i + 1; k < i + l; k++)
                    dp[i][i + l] = max(dp[i][i + l], dp[i][k] + dp[k][i + l] + nums[i] * nums[k] * nums[i + l]);
        return dp.front().back();
    }
};

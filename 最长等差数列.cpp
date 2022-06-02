/*
给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。
示例 1：
输入：nums = [3,6,9,12]
输出：4
解释： 
整个数组是公差为 3 的等差数列。
示例 2：
输入：nums = [9,4,7,2,10]
输出：3
解释：
最长的等差子序列是 [4,7,10]。
示例 3：
输入：nums = [20,1,15,3,10,5,8]
输出：4
解释：
最长的等差子序列是 [20,15,10,5]。
提示：
2 <= nums.length <= 1000
0 <= nums[i] <= 500
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
            
        vector<vector<int>> dp(n, vector<int>(1001));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ret = max(ret, dp[i][diff]);
            }
        }
        return ret + 1;
    }
};

//从公差下手，arr[i] arr[j] 公差 d
//所给数据 0 - 500 ，所以公差 d 的范围 -500 ~ 500，为了表示方便，计算时将公差加500。
//dp[n][1001]，dp[i][j] 表示以 nums[i] 结尾的公差为 j 的等差数列的最长值。
//状态转移方程
//j from 0 to i - 1, dp[i][d] = max(dp[i][d], dp[j][d] + 1)
//从中穷举找出最大值


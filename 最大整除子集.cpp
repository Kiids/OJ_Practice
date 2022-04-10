/*
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。
示例 1：
输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
示例 2：
输入：nums = [1,2,4,8]
输出：[1,2,4,8]
提示：
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
nums 中的所有整数 互不相同
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        pair<int, int> dp[n];
        for(int i = 0; i < n; i++)
        {
            pair<int, int> p = {1, i};
            for (int j = 0; j < i; j++)
            	if (nums[i] % nums[j] == 0 && dp[j].first + 1 > p.first)
                    p = {dp[j].first + 1, j};
            dp[i] = p;
        }

        int idx = max_element(dp, dp + n) - dp;
        int val = dp[idx].first;
        vector<int> v;
        while (val--)
        {
        	v.push_back(nums[idx]);
        	idx = dp[idx].second;
        }
        return v;
    }
};

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
        pair<int, int> dp[n];  // <nums[i] 为结尾的最大的整除子集的大小, 遍历至满足条件的下标>
        for(int i = 0; i < n; i++)
        {
            pair<int, int> p = {1, i};
            for (int j = 0; j < i; j++)
            	if (nums[i] % nums[j] == 0 && dp[j].first + 1 > p.first)
                    p = {dp[j].first + 1, j};
            dp[i] = p;
        }

        int idx = max_element(dp, dp + n) - dp;  // dp.first 最大的那个下标 
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

// dp[i] 表示以nums[i]为结尾的最大的整除子集的大小 （这里nums已排序）
// 转移方程 类似LIS（最大上升子序列）
// 对于nums[i]，需要检查[0, i-1]位上的nums[j]，使得nums[i] % nums[j] == 0，即nums[j]是nums[i]的一个因数。
// 得到 
// dp[i] = max{j∈[0,i-1]} (dp[j]+1), if nums[i]%nums[j] == 0
// 时间复杂度：O(nlogn+n^2)=O(n^2) 排序+逐位检查其前面的所有元素
// 空间复杂度：O(n)


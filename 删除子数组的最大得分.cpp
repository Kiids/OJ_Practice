/*
给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。
返回 只删除一个 子数组可获得的 最大得分 。
如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。
示例 1：
输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]
示例 2：
输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]
提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> v(10001);         // 元素是否被访问过
        int ret = 0, sum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            while (v[nums[r]])         // 窗口收缩
            {
                sum -= nums[l];   
                v[nums[l++]] = false;  // 设置未访问
            }
            v[nums[r]] = true;         // 设置已访问
            sum += nums[r];
            ret = max(ret, sum);
        }
        return ret;
    }
};

/*
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
子数组 是数组的一段连续部分。
示例 1：
输入：nums = [1,0,1,0,1], goal = 2
输出：4
解释：
有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
示例 2：
输入：nums = [0,0,0,0,0], goal = 0
输出：15
提示：
1 <= nums.length <= 3 * 10^4
nums[i] 不是 0 就是 1
0 <= goal <= nums.length
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        m[0]++;
        int ret = 0, n = 0;
        for (auto e : nums)
        {
            n += e;
            if (m[n - goal])
                ret += m[n - goal];  // 假设我们枚举到nums[i]，我们只需要查询哈希表中元素 sum[i]-goal 的数量即可
            m[n]++;
        }
        return ret;
    }
};
// 哈希存储前缀和
// 遇到合适的就累加

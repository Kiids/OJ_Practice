/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
示例 1：
输入：nums = [1,1,1], k = 2
输出：2
示例 2：
输入：nums = [1,2,3], k = 3
输出：2
提示：
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int ret = 0, pre = 0;
        for (int y : nums)
        {
            pre += y;
            int x = pre - k;
            ret += m[x];
            m[pre] ++;
        }
        return ret;
    }
};

// 哈希表存储每个前缀和的个数
// 遍历nums时，判断是否存在 当前位置前缀和-k 的前缀和， res+其前缀和个数

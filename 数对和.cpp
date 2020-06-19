/*
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。
示例 1:
输入: nums = [5,6,5], target = 11
输出: [[5,6]]
示例 2:
输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]
提示：
nums.length <= 100000
*/

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        for (auto n : nums)
            if (--mp[n] >= 0 && --mp[target - n] >= 0)
                ans.push_back({n, target - n});
        return ans;
    }
};

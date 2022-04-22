/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
示例 1：
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：
输入：nums = [4,4,3,2,1]
输出：[[4,4]]
提示：
1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/

class Solution {
    vector<int> path;
    vector<vector<int>> v;
    void Fun(vector<int>& nums, int index)
    {
        if (path.size() >= 2)
            v.push_back(path);
        unordered_set<int> s;
        for (int i = index; i < nums.size(); ++i)
        {
            if (!path.empty() && nums[i] < path.back() || s.count(nums[i]) == 1)
                continue;

            s.insert(nums[i]);
            path.push_back(nums[i]);
            Fun(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        Fun(nums, 0);  // 数组 回溯层数
        return v;
    }
};

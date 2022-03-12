/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：
输入：nums = [0]
输出：[[],[0]]
提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
    vector<vector<int>> v;
    vector<int> t;
    void DFS(bool flag, int cur, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            v.push_back(t);
            return ;
        }
        DFS(false, cur + 1, nums);
        if (!flag && cur > 0 && nums[cur] == nums[cur - 1])
            return;
        t.push_back(nums[cur]);
        DFS(true, cur + 1, nums);
        t.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        DFS(false, 0, nums);
        return v;
    }
};

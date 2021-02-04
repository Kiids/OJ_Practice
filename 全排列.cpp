/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    vector<int> used;
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            used.push_back(0);
        diguihelper(nums);
        return ret;
    }

    vector<int> diguihelper(vector<int>& nums)
    {
        if (v.size() == nums.size())
        {
            ret.push_back(v);
            return v;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1)
                continue;
            else
            {
                used[i] = 1;
                v.push_back(nums[i]);
                diguihelper(nums);
                v.pop_back();
                used[i]=0;
            }
        }
        return v;
    }
};

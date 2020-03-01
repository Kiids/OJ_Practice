/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int size = 1 << nums.size();  // 2^n个子集
        for (int i = 0; i < size; i++)
        {
            vector<int> v;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << (j%32)))  // %32为了解决Line 11: Char 28: runtime error: shift exponent 32 is too large for 32-bit type 'int' (solution.cpp)
                    v.push_back(nums[j]);
                
            }
            ret.push_back(v);
        }
        return ret;
    }
};

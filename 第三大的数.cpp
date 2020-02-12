/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
示例 1:
输入: [3, 2, 1]
输出: 1
解释: 第三大的数是 1.
示例 2:
输入: [1, 2]
输出: 2
解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:
输入: [2, 2, 3, 1]
输出: 1
解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = nums[0], second = INT_MIN, third = second;
        if (nums.size() == 3)  // 特殊处理[1,1,2] [1,2,INT_MIN]情况
        {
            sort(nums.begin(), nums.end());
            if (nums[0] != nums[1] && nums[1] != nums[2])
                return nums[0];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n == first || n == second || n == third)
                continue;
            if (n > first)
            {
                third = second;
                second = first;
                first = n;
            }
            else if (n > second)
            {
                third = second;
                second = n;
            }
            else if (n > third)
                third = n;
        }
        return third == INT_MIN ? first : third;
    }
};

/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
提示：
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int max;
        for (int i = 0, j = k - 1; j >= 0 && j < nums.size(); j++)
        {
            if (i == 0 || max == nums[i - 1])
            {
                max = nums[i];
                for (int t = j; t > i; t--)
                {
                    if (max < nums[t])
                        max = nums[t];
                }
            }
            else
            {
                if (nums[j] > max)
                    max = nums[j];
            }
            ret.push_back(max);
            i++;
        }
        return ret;
    }
};

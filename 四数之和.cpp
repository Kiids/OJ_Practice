/*
给你一个由 n 个整数组成的数组?nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组?[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
提示：
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target && nums[k] >= 0)  // 剪枝
            	break;
            if (k > 0 && nums[k] == nums[k - 1])  // 对nums[k]去重
                continue;
            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)  // 剪枝
                    break;
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target)
                        left++;
                    else
                    {
                        v.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1])  // 对nums[right]去重
                            right--;
                        while (right > left && nums[left] == nums[left + 1])    // 对nums[left]去重
                            left++;
                        // 找到答案时，双指针收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return v;
    }
};

// 四数之和，和三数之和都使用双指针法, 基本解法在三数之和的基础上再套一层for循环

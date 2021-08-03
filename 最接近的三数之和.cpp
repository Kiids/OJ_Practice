/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
提示：
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int temp = abs(nums[0] + nums[1] + nums[2] - target), ret = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (temp > abs(nums[i] + nums[left] + nums[right] - target))
                {
                    temp = abs(nums[i] + nums[left] + nums[right] - target);
                    ret = nums[i] + nums[left] + nums[right];
                }
                if (nums[i] + nums[left] + nums[right] > target)
                {
                    right--;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] < target)
                {
                    left++;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] == target)
                    return nums[i] + nums[left] + nums[right];
            }
        }
        return ret;
    }
};

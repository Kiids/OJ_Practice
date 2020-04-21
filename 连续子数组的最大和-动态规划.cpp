/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
示例1:
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组?[4,-1,2,1] 的和最大，为?6。
提示：
1 <=?arr.length <= 10^5
-100 <= arr[i] <= 100
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划 时间O(n) 空间O(1) 
        int max = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum > 0)  // 当前sum大于0则继续加
                sum += nums[i];
            else  // 否则将其替换为新元素的值
                sum = nums[i];

            max = max > sum ? max : sum;
        }
        return max;
    }
};

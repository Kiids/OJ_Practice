/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
示例 1:
输入: [1,2,3]
输出: 6
示例 2:
输入: [1,2,3,4]
输出: 24
注意:
给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;
        if (nums[1] < 0)
            max1 = nums[0] * nums[1] * nums[size - 1];
        max2 = nums[size - 1] * nums[size - 2] * nums[size - 3];        
        return max(max1, max2);
    }
};

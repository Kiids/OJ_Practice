/*
给定一个二进制数组， 计算其中最大连续1的个数。
示例 1:
输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：
输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, num = 0;
        for (auto i : nums)
        {
            if (i == 1)
                num++;
            else
                num = 0;
            max = max > num ? max : num;
        }
        return max;
    }
};

/*
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和 。
示例 1：
输入：nums = [4,14,2]
输出：6
解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
示例 2：
输入：nums = [4,14,4]
输出：4
提示：
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^9
给定输入的对应答案符合 32-bit 整数范围
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, n[32];
        memset(n, 0, sizeof(n));
        for (auto& num : nums)
            for (int i = 0; i < 32; i++)
                n[i] += (num & (1 << i)) > 0;
        for (int i = 0 ; i < 32; i++)
            ret += n[i] * (nums.size() - n[i]);
        return ret;
    }
};

//用数组记录所有num在二进制表示下的32位中，出现1的个数。
//举个例子：
//nums = [4,14,2]
//4:  0100
//14: 1110
//2:  0010
//则得到数组 n[0] = 0, n[1] = 2, n[2] = 2, n[3] = 1
//总共n个数字，因此第 i 位上为1的数有n[i]个，为0的数有nums.size()-n[i]个，
//此时就会产生 n[i] * (nums.size()-n[i])个汉明距离
//遍历32位得到答案


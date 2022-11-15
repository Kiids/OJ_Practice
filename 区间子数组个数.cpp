/*
给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。
求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。
例如 :
输入: 
A = [2, 1, 4, 3]
L = 2
R = 3
输出: 3
解释: 满足条件的子数组: [2], [2, 1], [3].
注意:
L, R  和 A[i] 都是整数，范围在 [0, 10^9]。
数组 A 的长度范围在[1, 50000]。
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastR = -1, lastD = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > right)      // 不满足条件重新计数 
            {
                lastR = i;
                lastD = 0;
            }
            else if (nums[i] < left)  // 计算 ret 个数 
                ret += lastD;
            else
            {
                lastD = i - lastR;    // 长度即包含 i 的子数组个数
                ret += lastD;
            }
        }
        return ret;
    }
};

// 动态规划
// d[i]表示包含i的情况下满足条件的子数组的个数
// 初始化d[i]都是0
// nums[i] > right: 不满足，那么d[i]=0,并且记录lastR为上一个大于R的的序号
// nums[i] < left，它不能成为单独满足，所以它等于 d[i-1]
// nums[i] 在范围内，它的长度就是 i- lastR，也就是包含i的子数组的个数
// 结果sum_overi (d[i])
// 优化
// 只依赖于 lastR，LastD 和 累计的数组个数


/*
给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
示例 1：
输入：[1, 2, 2, 3, 1]
输出：2
解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2：
输入：[1,2,2,3,1,4,2]
输出：6
提示：
nums.length 在1到 50,000 区间范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> n(50010), first(50010, -1);
        pair<int, int> ret = {0, 0};
        for (int i = 0; i < nums.size(); i++)
        {
            n[nums[i]]++;
            if (first[nums[i]] == -1)   // 第一次出现，做标记
                first[nums[i]] = i;
                
            // 当出现更大的度 或者 度相同但长度更短 则更新答案 
            if (n[nums[i]] > ret.first || (n[nums[i]] == ret.first && i - first[nums[i]] + 1 < ret.second))
                ret = {n[nums[i]], i - first[nums[i]] + 1};
        }
        return ret.second;
    }
};

// n[i]表示当前i出现的次数，first[i]表示i第一次出现的下标
// 对于ret，first表示遍历至当前的最大度，second表示最大度对应数组的最短长度
// 一轮遍历更新答案


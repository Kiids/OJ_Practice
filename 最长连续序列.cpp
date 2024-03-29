/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
提示：
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto e : nums)
            s.insert(e);
        int ret = 0;
        for (auto e : s)
        {
            if(!s.count(e - 1))
            {
                int t = e;
                while (s.count(t + 1))
                    t++;
                ret = max(ret, t - e + 1);
            }
        }
        return ret;
    }
};

//定义一个哈希表，将数组中的数放入哈希表中。
//遍历哈希表，如果当前数x的前驱x-1不存在，就以当前数x为起点向后枚举。
//假设最长枚举到了数y，那么连续序列长度即为y-x+1。
//枚举更新答案。


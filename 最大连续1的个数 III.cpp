/*
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
返回仅包含 1 的最长（连续）子数组的长度。
示例 1：
输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：
输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
提示：
1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0, zero = 0, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                zero++;
            while (zero > k)
                if (nums[left++] == 0)
                    zero--;
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

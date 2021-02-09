/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
示例：
输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
提示：
1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int ret = sum;
        for (int i = 1; i + k - 1 < n; i++)
        {
            sum += nums[i + k - 1] - nums[i - 1];
            ret = max(ret, sum);
        }
        return (double)ret / k;
    }
};
// 滑动窗口 

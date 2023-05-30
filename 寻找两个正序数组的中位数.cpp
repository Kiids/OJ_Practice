/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组?nums1 和?nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        const int k = len / 2;
        int i = 0, j = 0;
        double ret1 = 0, ret2 = 0;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        while (i + j <= k)
        {
            ret1 = ret2;
            ret2 = nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++];
        }
        return len % 2 == 1 ? ret2 : (ret1 + ret2) / 2;
    }
};

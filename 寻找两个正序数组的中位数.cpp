/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
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
        const int k = len / 2;   // 无论奇偶数，返回的index都是(len - 1) / 2 和 len / 2, 如果是奇数两个index相等，偶数就是一前一后
        int i = 0, j = 0;
        double ret1 = 0, ret2 = 0;  // 记录一前一后
        // push_back(INT_MAX)可以不用判断nums1或者nums2溢出的情况
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


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), k = 0, i = 0, j = 0;
        vector<int> v(m + n, 0);
        while (i < m && j < n)
            v[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while (i < m)
            v[k++] = nums1[i++];
        while (j < n)
            v[k++] = nums2[j++];
        return k % 2 ? v[k / 2] : (v[k / 2] + v[k / 2 - 1]) / 2.0;  // 判断奇偶
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, l = 0, r = 0;
        for (int x = 0; x <= (m + n) / 2; x++)
        {
            l = r;
            if (i < m && (j >= n || nums1[i] < nums2[j]))
                r = nums1[i++];
            else
                r = nums2[j++];
        }
        return (m + n) & 1 ? r : (l + r) / 2.0;
    }
};
// 2个指针，分别指向2个数组的头
// 每次比较大小来移动 2个指针
// 当指针移动的次数与 (m + n) / 2 相同时，得到中位数


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), l = 0, r = m;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        while (l < r)
        {
            int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
            nums1[i] < nums2[j - 1] ? l = ++i : r = i;
        }
        r = (m + n + 1) / 2 - l;
        int subL = max(l <= 0 ? INT_MIN : nums1[l - 1], r <= 0 ? INT_MIN : nums2[r - 1]);
        if ((m + n) & 1)
            return subL;
        int subR = min(l >= m ? INT_MAX : nums1[l], r >= n ? INT_MAX : nums2[r]);
        return (subL + subR) / 2.0;
    }
};
// 二分查找

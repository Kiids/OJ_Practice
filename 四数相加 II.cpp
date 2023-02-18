/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
例如:
输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:
2
解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;   // key:nums1+nums2的数值，value:nums1+nums2数值出现的次数
        for (int a : nums1)          // 遍历nums1和nums2数组，统计两个数组元素之和，和出现的次数，放到map中
            for (int b : nums2)
                m[a + b]++;
        int count = 0;               // 统计nums1+nums2+nums3+nums4=0 出现的次数
        for (int c : nums3)          // 在遍历nums3和nums4数组，找到如果 0-(nums3+nums4) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
            for (int d : nums4)
                if (m.find(0 - (c + d)) != m.end())
                    count += m[0 - (c + d)];
        return count;
    }
};

// 定义一个unordered_map，key放nums1和nums2两数之和，value 放nums1和nums2两数之和出现的次数。
// 遍历nums1和nums2数组，统计两个数组元素之和，和出现的次数，放到map中。
// count用来统计nums1+nums2+nums3+nums4=0出现的次数。
// 遍历nums3和nums4数组，找到如果 0-(nums3+nums4) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
// 最后返回统计值count


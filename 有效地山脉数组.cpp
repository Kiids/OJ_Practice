/*
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
示例 1：
输入：[2,1]
输出：false
示例 2：
输入：[3,5,5]
输出：false
示例 3：
输入：[0,3,2,1]
输出：true
提示：
0 <= A.length <= 10000
0 <= A[i] <= 10000 
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 || is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend()))
            return false;
		int i = 0;
		for ( ; i < A.size() - 1 && A[i] < A[i + 1]; i++);
		for ( ; i < A.size() - 1 && A[i] > A[i + 1]; i++);
		return i == A.size() - 1;
    }
};
//如果此数组中元素个数少于三个或者单调递增或递减，直接返回false即可。
//用一个i指针从前往后遍历，第一个循环退出时，说明找到山顶或者两个相邻的数相等。
//第二个循环看后面是否为递减，一直递减就会遍历到了结尾返回true，否则中途退出返回false。

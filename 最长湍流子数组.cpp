/*
给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。
如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。
更正式地来说，当 arr 的子数组 A[i], A[i+1], ..., A[j] 满足仅满足下列条件时，我们称其为湍流子数组：
若 i <= k < j ：
当 k 为奇数时， A[k] > A[k+1]，且
当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j ：
当 k 为偶数时，A[k] > A[k+1] ，且
当 k 为奇数时， A[k] < A[k+1]。
示例 1：
输入：arr = [9,4,2,10,7,8,8,1,9]
输出：5
解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
示例 2：
输入：arr = [4,8,12,16]
输出：2
示例 3：
输入：arr = [100]
输出：1
提示：
1 <= arr.length <= 4 * 10^4
0 <= arr[i] <= 10^9
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 1));
        int ret = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
                dp[i][0] = dp[i - 1][1] + 1;
            else if (arr[i] < arr[i - 1])
                dp[i][1] = dp[i - 1][0] + 1;
            else
                continue;
            ret = max(ret, max(dp[i][1], dp[i][0]));
        }
        return ret;
    }
};

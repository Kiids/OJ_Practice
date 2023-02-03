/*
给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
示例 1：
输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
输出：13
解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
示例 2：
输入：matrix = [[-5]], k = 1
输出：-5
提示：
n == matrix.length
n == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
1 <= k <= n^2
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int cnt = fun(matrix, m);
            if (cnt < k)
                l = m + 1;
            else r = m;
        }
        return l;
    }

    int fun(vector<vector<int>>& v, int x)
    {
        int n = v.size(), i = n - 1, j = 0, ret = 0;
        while (i >= 0 && j < n)
        {
            if (v[i][j] <= x)
            {
                ret += i + 1;
                j++;
            }
            else
                i--;
        }
        return ret;
    }
};

// 矩阵最左上角为最小值，最右下角为最大值，在此范围内进行二分搜索，取中间数mid，然后在每行中查找mid，
// 考虑到每行每列有序，不需要对每行做二分查找，从数组左下标进行查找，如果比目标值小，则右移一位，
// 并且当前位置上面所有数字都小于目标值，那么cnt += i + 1，反之则向上移一位。
// 遍历完所有行可以确定mid是第几小的数，然后与k进行比较，二分查找，left和right最终相等，会变为数组中第k小的数。


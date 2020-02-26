/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
示例 1：
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
提示：
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            ret[i] = A[i] * A[i];
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

/*
思路是先找到正负数的分界线，通过双指针从内往外排序。然而总是有各种不同情况的越界
最后参考leedcode上题解的代码
    int length = A.size();
    vector<int> ans(length);
    int i = 0, j = length - 1, k = length - 1;
    while (k >= 0) {
        int a = A[i] * A[i];
        int b = A[j] * A[j];
        if (a > b) {
            ans[k] = a;
            i++;
        }
        else {
            ans[k] = b;
            j--;
        }
        k--;
    }
    return ans;
*/

/*
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
初始化 A 和 B 的元素数量分别为 m 和 n。
示例:
输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
说明:
A.length == n + m
*/

// 逆向双指针 原地修改 时间复杂度：O(m+n)O(m+n) 空间复杂度：O(1)O(1)
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a = m - 1, b = n - 1, last = m + n - 1, cur;
        while (a >= 0 || b >= 0)
        {
            if (a == -1)
                cur = B[b--];
            else if (b == -1)
                cur = A[a--];
            else if (A[a] > B[b])
                cur = A[a--];
            else
                cur = B[b--];
            A[last--] = cur;
        }
    }
};

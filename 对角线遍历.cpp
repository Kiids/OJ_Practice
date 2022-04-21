/*
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
示例 1：
输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]
示例 2：
输入：mat = [[1,2],[3,4]]
输出：[1,2,3,4]
提示：
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
-10^5 <= mat[i][j] <= 10^5
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> v;
        for (int i = 0, j = 0; i < m && j < n; )
        {
            v.push_back(mat[i][j]);
            if ((i + j) % 2 == 0)
            {
                if (j + 1 >= n)
                    i++;
                else if (i - 1 < 0)
                    j++;
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if (i + 1 >= m)
                    j++;
                else if (j - 1 < 0)
                    i++;
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};

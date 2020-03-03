/*
给定一个整数矩阵，找出最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
示例 1
输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为?[1, 2, 6, 9]。
示例 2:
输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
*/

class Solution {
public:
    /*int row, col;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        row = matrix.size();
        if (row == 0)
            return 0;
        col = matrix[0].size();
        vector<vector<int>> v(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                ret = max(ret, DFS(matrix, v, i, j, INT_MIN));
        return ret;
    }
    int DFS(vector<vector<int>>& m, vector<vector<int>>& v, int i, int j, int x)
    {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return 0;
        
        int y = m[i][j];
        if (y <= x)
            return 0;
        int u, d, l, r;  // 上下左右
        if (v[i][j] == 0)
        {
            u = DFS(m, v, i - 1, j, y);
            d = DFS(m, v, i + 1, j, y);
            l = DFS(m, v, i, j - 1, y);
            r = DFS(m, v, i, j + 1, y);
            v[i][j] = 1 + max(max(u, d), max(l, d));
        }
        return v[i][j];
    }*/
    vector<vector<int>> v;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int DP(int x, int y, vector<vector<int>>& m)
    {
        if (v[x][y] != -1)
            return v[x][y];
        v[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m.size() && b >= 0 && b < m[a].size() && m[a][b] > m[x][y])
                v[x][y] = max(v[x][y], DP(a, b, m) + 1);
        }
        return v[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        if(matrix.size() == 0)
            return 0;
        v = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                ret = max(ret, DP(i, j, matrix));
        return ret;
    }
};

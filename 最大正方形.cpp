/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4
示例 2：
输入：matrix = [["0","1"],["1","0"]]
输出：1
示例 3：
输入：matrix = [["0"]]
输出：0
提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] 为 '0' 或 '1'
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), x = 0;
        vector<vector<int>> dp(n, (vector<int>(m, 0)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                    x = max(dp[i][j], x);
                }
                else
                {
                    if (matrix[i][j] == '0')
                        dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j - 1] , min(dp[i - 1][j], dp[i][j - 1])) + 1;
                        x = max(dp[i][j], x);
                    }
                }
            }
        }
        return x * x;
    }
};

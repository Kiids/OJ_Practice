/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的?'O' 用 'X' 填充。
示例 1：
输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的?'O'?都不会被填充为?'X'。 任何不在边界上，或不与边界上的?'O'?相连的?'O'?最终都会被填充为?'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：
输入：board = [["X"]]
输出：[["X"]]
提示：
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
*/

class Solution {
    int a[4] = {1, -1, 0, 0}, b[4] = {0, 0, 1, -1};
    void BFS(vector<vector<char>>& v, int x, int y)
    {
        if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size() || v[x][y] != 'O')
            return;
        v[x][y] = '1';
        for (int i = 0; i < 4; i++) BFS(v, x + a[i], y + b[i]);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int y = 0; y < n; y++)
        {
            BFS(board, 0, y);
            BFS(board, m - 1, y);
        }
        for (int x = 1; x < m - 1; x++)
        {
            BFS(board, x, 0);
            BFS(board, x, n - 1);
        }

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (board[x][y] == 'O')
                    board[x][y] = 'X';
                else if (board[x][y] == '1')
                    board[x][y] = 'O';
            }
        }
    }
};


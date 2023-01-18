/*
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。
给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 10^9 + 7 取余 后的结果。
示例 1：
输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
输出：6
示例 2：
输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
输出：12
提示：
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/
class Solution {
    int x  = 1e9 + 7, m, n;
    int dp[51][51][51];
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return DFS(startRow, startColumn, maxMove);
    }

    long DFS(int i, int j, int d)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;            // 出界
        if (d == 0)
            return 0;            // 没有步数
        if (dp[i][j][d] != -1)
            return dp[i][j][d];  // 之前来过
        return dp[i][j][d] = (DFS(i + 1, j, d - 1) + DFS(i - 1, j, d - 1) + DFS(i, j + 1, d - 1) + DFS(i, j - 1, d - 1)) % x;
    }
};

// 深度搜索，且在DFS搜索过程中多次遇到之前来过的坐标、步数相同的状态
// 避免重复运算：用记忆数组记录每个状态最终的路径数量，如果下次重复来到这个状态，直接取出路径数量，不继续搜索。


/*
在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。
象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。
每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。
骑士继续移动，直到它走了 k 步或离开了棋盘。
返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
示例 1：
输入: n = 3, k = 2, row = 0, column = 0
输出: 0.0625
解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
在每一个位置上，也有两种移动可以让骑士留在棋盘上。
骑士留在棋盘上的总概率是0.0625。
示例 2：
输入: n = 1, k = 0, row = 0, column = 0
输出: 1.00000
提示:
1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n
*/

class Solution {
    int x[8] = {-2,-2,-1,-1,1,1,2,2};
    int y[8] = {1,-1,2,-2,2,-2,1,-1};
    unordered_map<int, unordered_map<int, double>> mem;
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0)
            return 1;
        if (mem[row * n + column].find(k) != mem[row * n + column].end())
            return mem[row * n + column][k];

        double ret = 0;
        for (int i = 0; i < 8; i++)
        {
            int r = row + x[i];
            int c = column + y[i];
            if (r >= n || c >= n || r < 0 || c < 0)
                continue;
            ret += knightProbability(n, k - 1, r, c) / 8;
        }

        mem[row * n + column][k] = ret;
        return ret;
    }
};

// 记忆化搜索，空间换时间；记录中间状态，避免重复计算；适用于状态确定则记录值确定的条件，即无后效性条件。
// 考虑骑士走k步是否不会出局，考虑其进行到8个方向每个方向之后走k-1步是否会出局，将不会出局的概率/8进行累计。
// 递归终点是k为0，就是在棋盘上且无需继续移动的情况；此时不会出局的概率是100%。
// 搜索的过程中，会重复搜索到同一个位置，在步数位置确定的时候，其概率也是确定的，记录下来避免重复计算。

constexpr int dirs[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
class Solution {
    double dp[26][26][101];
public:
    double knightProbability(int n, int k, int row, int column) {
        for (int x = 0; x <= k; x++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (x == 0)
                    {
                        dp[i][j][x] = 1.0;
                        continue;
                    }
                    for (auto d : dirs)
                    {
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                            dp[i][j][x] += dp[nx][ny][x - 1] / 8;
                    }
                }
            }
        }
        return dp[row][column][k];
    }
};

// 动态规划 - 自底向上
// 直接 dp ，每一步产生的概率都来源于上一步产生的概率，从 0 步开始对所有的棋盘上点更新概率。
// 用 dp[i][j][x]，记录棋盘上可能的马跳了 x 步到点 (i,j) 的概率，概率来自于上一步跳到点 (i, j) 周围八个格子的概率。
// 当存在该状态时直接返回结果，最终答案就是 dp[row][column]][k]。


/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。
示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
提示：
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[i][0] == 0)
                v[i][0] = 1; 
            else
                break;
        }
        for (int i = 0; i < m; i++) 
        {
            if (obstacleGrid[0][i] == 0)
                v[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (obstacleGrid[i][j] == 0)
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                    
        return v[n - 1][m - 1];
    }
};

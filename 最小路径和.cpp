/*
����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����
ʾ�� 1��
���룺grid = [[1,3,1],[1,5,1],[4,2,1]]
�����7
���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��
ʾ�� 2��
���룺grid = [[1,2,3],[4,5,6]]
�����12
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i - 1 < 0)
                   dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j - 1 < 0)
                   dp[i][j] = dp[i - 1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
            }
        }
        return dp[row - 1][col - 1];
    }
};

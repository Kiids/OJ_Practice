/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������
���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
ʾ�� 1��
���룺obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
�����2
���ͣ�3x3 ��������м���һ���ϰ��
�����Ͻǵ����½�һ���� 2 ����ͬ��·����
1. ���� -> ���� -> ���� -> ����
2. ���� -> ���� -> ���� -> ����
ʾ�� 2��
���룺obstacleGrid = [[0,1],[0,0]]
�����1
��ʾ��
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] Ϊ 0 �� 1
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

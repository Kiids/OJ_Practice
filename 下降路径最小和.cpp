/*
����һ�� n x n �� ���� �������� matrix �������ҳ�������ͨ�� matrix ���½�·�� �� ��С�� ��
�½�·�� ���Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ�У���λ�����·������ضԽ�������������ҵĵ�һ��Ԫ�أ���������˵��λ�� (row, col) ����һ��Ԫ��Ӧ���� (row + 1, col - 1)��(row + 1, col) ���� (row + 1, col + 1) ��
ʾ�� 1��
���룺matrix = [[2,1,3],[6,5,4],[7,8,9]]
�����13
���ͣ���������������С���½�·�����üӴ�+б���ע��
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
ʾ�� 2��
���룺matrix = [[-19,57],[-40,-5]]
�����-59
���ͣ�������һ������С���½�·�����üӴ�+б���ע��
[[-19,57],
 [-40,-5]]
ʾ�� 3��
���룺matrix = [[-48]]
�����-48
��ʾ��
n == matrix.length
n == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
            
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = matrix[i][j] + dp[i - 1][j];
                if (j > 0)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]);
                if (j < m - 1)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

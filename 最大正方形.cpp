/*
��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������
ʾ�� 1��
���룺matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
�����4
ʾ�� 2��
���룺matrix = [["0","1"],["1","0"]]
�����1
ʾ�� 3��
���룺matrix = [["0"]]
�����0
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] Ϊ '0' �� '1'
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

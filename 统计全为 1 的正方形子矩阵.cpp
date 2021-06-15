/*
����һ�� m * n �ľ��󣬾����е�Ԫ�ز��� 0 ���� 1������ͳ�Ʋ�����������ȫ�� 1 ��ɵ� ������ �Ӿ���ĸ�����
ʾ�� 1��
���룺matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
�����15
���ͣ� 
�߳�Ϊ 1 ���������� 10 ����
�߳�Ϊ 2 ���������� 4 ����
�߳�Ϊ 3 ���������� 1 ����
�����ε����� = 10 + 4 + 1 = 15.
ʾ�� 2��
���룺matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
�����7
���ͣ�
�߳�Ϊ 1 ���������� 6 ���� 
�߳�Ϊ 2 ���������� 1 ����
�����ε����� = 6 + 1 = 7.
��ʾ��
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                    
                else if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                    
                else if (matrix[i][j] == 1)
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    
                ret += dp[i][j];
            }
        }
        return ret;
    }
};

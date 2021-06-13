/*
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
ʾ�� 1��
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[[7,4,1],[8,5,2],[9,6,3]]
ʾ�� 2��
���룺matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
�����[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
ʾ�� 3��
���룺matrix = [[1]]
�����[[1]]
ʾ�� 4��
���룺matrix = [[1,2],[3,4]]
�����[[3,1],[4,2]]
��ʾ��
matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2;i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }
};

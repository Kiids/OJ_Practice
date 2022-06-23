/*
��һ����СΪ n x n �ľ�����ԣ������ÿһ�к�ÿһ�ж������� 1 �� n �� ȫ�� �������� 1 �� n��������Ϊ�þ�����һ�� ��Ч ����
����һ����СΪ n x n ���������� matrix �������жϾ����Ƿ�Ϊһ����Ч��������ǣ����� true �����򣬷��� false ��
ʾ�� 1��
���룺matrix = [[1,2,3],[3,1,2],[2,3,1]]
�����true
���ͣ��ڴ����У�n = 3 ��ÿһ�к�ÿһ�ж��������� 1��2��3 ��
��ˣ����� true ��
ʾ�� 2��
���룺matrix = [[1,1,1],[1,2,3],[1,2,3]]
�����false
���ͣ��ڴ����У�n = 3 ������һ�к͵�һ�в��������� 2 �� 3 ��
��ˣ����� false ��
��ʾ��
n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n
*/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> countRow(n + 1,0), countCol(n + 1,0);
            for (int j = 0; j < n; j++)
            {
                countRow[matrix[i][j]]++;
                countCol[matrix[j][i]]++;
                if (countRow[matrix[i][j]] == 2 || countCol[matrix[j][i]] == 2)
                    return false;
            }
        }
        return true;
    }
};

//��������ɨ����󣬲�ʹ�ù�ϣ���¼�����ֳ��ֵĴ��������ĳ���ֳ��ֳ���һ�Σ����ؼ١�

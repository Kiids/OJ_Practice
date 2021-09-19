/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
���ף�
һ��ֱ�۵Ľ��������ʹ��  O(mn) �Ķ���ռ䣬���Ⲣ����һ���õĽ��������
һ���򵥵ĸĽ�������ʹ�� O(m + n) �Ķ���ռ䣬������Ȼ������õĽ��������
�������һ����ʹ�ó����ռ�Ľ��������
ʾ�� 1��
���룺matrix = [[1,1,1],[1,0,1],[1,1,1]]
�����[[1,0,1],[0,0,0],[1,0,1]]
ʾ�� 2��
���룺matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
�����[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
��ʾ��
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		vector<int> row, col;
		for (int i = 0; i < matrix.size(); i++)
        {
			for (int j = 0; j < matrix[0].size(); j++)
            {
				if (matrix[i][j] == 0)
                {
					row.push_back(i);
					col.push_back(j);
				}
			}
		}

		for (int i = 0; i < row.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				matrix[row[i]][j] = 0;

		for (int i = 0; i < col.size(); i++)
			for (int j = 0; j < matrix.size(); j++)
				matrix[j][col[i]] = 0;
    }
};

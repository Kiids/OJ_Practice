/*
��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣
ʾ�� 1��
���룺
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
�����
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
ʾ�� 2��
���룺
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
�����
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix);
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j ]== 0)
                {
                    for (int k = 0; k < matrix.size(); k++)
                        v[k][j] = 0;
                    for (int m = 0; m < matrix[i].size(); m++)
                        v[i][m] = 0;
                }
        matrix = v;
    }
};

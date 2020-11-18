/*
����һ����СΪ rows x cols �ľ��� mat������ mat[i][j] �� 0 �� 1���뷵�� ���� mat ������λ�õ���Ŀ ��
����λ�� ���壺��� mat[i][j] == 1 ���ҵ� i �к͵� j ���е���������Ԫ�ؾ�Ϊ 0���к��е��±�� �� 0 ��ʼ ������λ�� (i, j) ����Ϊ����λ�á�
ʾ�� 1��
���룺mat = [[1,0,0],
            [0,0,1],
            [1,0,0]]
�����1
���ͣ�(1,2) ��һ������λ�ã���Ϊ mat[1][2] == 1 ���������к�������������Ԫ�ض��� 0
ʾ�� 2��
���룺mat = [[1,0,0],
            [0,1,0],
            [0,0,1]]
�����3
���ͣ�(0,0), (1,1) �� (2,2) ��������λ��
ʾ�� 3��
���룺mat = [[0,0,0,1],
            [1,0,0,0],
            [0,1,1,0],
            [0,0,0,0]]
�����2
ʾ�� 4��
���룺mat = [[0,0,0,0,0],
            [1,0,0,0,0],
            [0,1,0,0,0],
            [0,0,1,0,0],
            [0,0,0,1,1]]
�����3
��ʾ��
rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] �� 0 �� 1
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ret = 0;
        vector<int> rows(mat.size(), 0), cols(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                    ret ++;   
        return ret;
    }
};

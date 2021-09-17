/*
����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
ʾ�� 1��
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,3,6,9,8,7,4,5]
ʾ�� 2��
���룺matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
�����[1,2,3,4,8,12,11,10,9,5,6,7]
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> v;
        if (matrix.empty())
            return v;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; i++)
                v.push_back(matrix[u][i]);
            if (++u > d)
                break;
            for (int i = u; i <= d; i++)
                v.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
                v.push_back(matrix[d][i]);
            if (--d < u)
                break;
            for (int i = d; i >= u; i--)
                v.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return v;
    }
};

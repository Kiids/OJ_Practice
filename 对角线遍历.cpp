/*
����һ����СΪ m x n �ľ��� mat �����ԶԽ��߱�����˳����һ�����鷵����������е�����Ԫ�ء�
ʾ�� 1��
���룺mat = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,4,7,5,3,6,8,9]
ʾ�� 2��
���룺mat = [[1,2],[3,4]]
�����[1,2,3,4]
��ʾ��
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
-10^5 <= mat[i][j] <= 10^5
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> v;
        for (int i = 0, j = 0; i < m && j < n; )
        {
            v.push_back(mat[i][j]);
            if ((i + j) % 2 == 0)
            {
                if (j + 1 >= n)
                    i++;
                else if (i - 1 < 0)
                    j++;
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if (i + 1 >= m)
                    j++;
                else if (j - 1 < 0)
                    i++;
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};

/*
����һ�� m * n ���������� mat �����㽫ͬһ���Խ����ϵ�Ԫ�أ������ϵ����£�����������󣬷����ź���ľ���
ʾ�� 1��
���룺mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
�����[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
��ʾ��
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                map[i - j].emplace_back(mat[i][j]);
        
        for (auto& v : map)
            sort(v.second.rbegin(), v.second.rend());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = map[i - j].back();
                map[i - j].pop_back();
            }
        }
        return mat;
    }
};

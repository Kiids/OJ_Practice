/*
����һ�� m �� n �еĶ�ά���� grid ��һ������ k������Ҫ�� grid Ǩ�� k �Ρ�
ÿ�Ρ�Ǩ�ơ��������������������
λ�� grid[i][j] ��Ԫ�ؽ����ƶ��� grid[i][j + 1]��
λ�� grid[i][n - 1] ��Ԫ�ؽ����ƶ��� grid[i + 1][0]��
λ�� grid[m - 1][n - 1] ��Ԫ�ؽ����ƶ��� grid[0][0]��
���㷵�� k ��Ǩ�Ʋ��������յõ��� ��ά����
ʾ�� 1��
���룺grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
�����[[9,1,2],[3,4,5],[6,7,8]]
ʾ�� 2��
���룺grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
�����[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
ʾ�� 3��
���룺grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
�����[[1,2,3],[4,5,6],[7,8,9]]
��ʾ��
1 <= grid.length <= 50
1 <= grid[i].length <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() * grid[0].size(), v[n], index = 0;
        k = k % n;
        int next = (n - k) % n;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                v[index++] = grid[i][j];
                
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                grid[i][j] = v[next];
                next = (next + 1) % n;
            }
        }
        return grid;
    }
};

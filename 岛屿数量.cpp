/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��
ʾ�� 1��
���룺grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
�����1
ʾ�� 2��
���룺grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
�����3
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] ��ֵΪ '0' �� '1'
*/

class Solution {
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    int m, n;
    void DFS(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + dx[i], y2 = y + dy[i];
            if (0 <= x2 && x2 < m && 0 <= y2 && y2 < n && grid[x2][y2] == '1')
                DFS(x2, y2, grid);
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                    ret += 1, DFS(i, j, grid);
        return ret;
    }
};

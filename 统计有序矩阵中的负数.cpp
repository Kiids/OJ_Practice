/*
����һ�� m * n �ľ��� grid�������е�Ԫ�������ǰ��л��ǰ��У����Էǵ���˳�����С� 
����ͳ�Ʋ����� grid �� ���� ����Ŀ��
ʾ�� 1��
���룺grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
�����8
���ͣ������й��� 8 ��������
ʾ�� 2��
���룺grid = [[3,2],[1,0]]
�����0
ʾ�� 3��
���룺grid = [[1,-1],[-1,-1]]
�����3
ʾ�� 4��
���룺grid = [[-1]]
�����1
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int x = grid[0].size(), r = 0, b = 0, ret = 0;
        while (r < grid.size())
        {
            b = 0;
            while (b < x)
            {
                if (grid[r][b] < 0)
                {
                    ret += (grid.size() - r ) * (x - b);
                    x = b;
                }
                b++;
            }
            r++;
        }
        return ret;
    }
};

/*
�ڶ�ά����grid�У�grid[i][j]����λ��ĳ���Ľ�����ĸ߶ȡ� ���Ǳ����������κ���������ͬ��������������ܲ�ͬ���Ľ�����ĸ߶ȡ� �߶� 0 Ҳ����Ϊ�ǽ����
��󣬴�������������ĸ����򣨼��������ײ��������Ҳࣩ�ۿ��ġ�����ߡ�������ԭʼ������������ͬ�� ���е�������Ǵ�Զ���ۿ�ʱ�������н������γɵľ��ε��ⲿ������ �뿴��������ӡ�
������߶ȿ������ӵ�����ܺ��Ƕ��٣�
���ӣ�
���룺 grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
����� 35
���ͣ� 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]
��������ֱ���򣨼��������ײ�����������ߡ��ǣ�[9, 4, 8, 7]
��ˮƽˮƽ���򣨼���࣬�Ҳࣩ��������ߡ��ǣ�[8, 7, 9, 3]
�ڲ�Ӱ������ߵ�����¶Խ�����������ߺ����������£�
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
˵��:
1 < grid.length = grid[0].length <= 50��
 grid[i][j] �ĸ߶ȷ�Χ�ǣ� [0, 100]��
һ��������ռ��һ��grid[i][j]������֮�������� 1 x 1 x grid[i][j] �ĳ����塣
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
            
        vector<int> row_max(grid.size(), 0);
        vector<int> col_max(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }

        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                ret += min(row_max[i], col_max[j]) - grid[i][j];
        return ret;
    }
};

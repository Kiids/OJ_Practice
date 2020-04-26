/*
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����
ʾ�� 1:
����: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 12
����: ·�� 1��3��5��2��1 �����õ�����ֵ������
��ʾ��
0 < grid.length <= 200
0 < grid[0].length <= 200
*/

// ��̬�滮 
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<vector<int>> v(grid);
        for (int i = 1; i < v[0].size(); i++)
            v[0][i] += v[0][i - 1];
        for (int i = 1; i < v.size(); i++)
            v[i][0] += v[i - 1][0];
        for (int i = 1; i < v.size(); i++)
        {
            for (int j = 1; j < v[0].size(); j++)
            {
                v[i][j] += max(v[i - 1][j], v[i][j - 1]);
            }
        }
        int x = v.size() - 1;
        int y = v[0].size() - 1;
        return v[x][y];
    }
};

/*
����һ���±�� 0 ��ʼ����СΪ n x n ���������� grid ���������� Ri �к� Cj ����ȵ����ж� (Ri, Cj) ����Ŀ��
����к�������ͬ��˳�������ͬ��Ԫ�أ�����ȵ����飩������Ϊ��������ȵġ�
ʾ�� 1��
���룺grid = [[3,2,1],[1,7,6],[2,7,7]]
�����1
���ͣ�����һ��������жԣ�
- (�� 2 �У��� 1 ��)��[2,7,7]
ʾ�� 2��
���룺grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
�����3
���ͣ���������������жԣ�
- (�� 0 �У��� 0 ��)��[3,1,2,2]
- (�� 2 ��, �� 2 ��)��[2,4,2,2]
- (�� 3 ��, �� 2 ��)��[2,4,2,2]
��ʾ��
n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 10^5
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        unordered_map<string, int> map;
        for (int i = 0; i < m; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s += to_string(grid[i][j]);
                s += ",";
            }
            s.pop_back();
            map[s]++;
        }
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < m; j++)
            {
                s += to_string(grid[j][i]);
                s += ",";
            }
            s.pop_back();
            if (map.count(s))
                ret += map[s];
        }
        return ret;
    }
};


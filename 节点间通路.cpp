/*
�ڵ��ͨ·����������ͼ�����һ���㷨���ҳ������ڵ�֮���Ƿ����һ��·����
ʾ��1:
 ���룺n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 �����true
ʾ��2:
 ���룺n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 ��� true
��ʾ��
�ڵ�����n��[0, 1e5]��Χ�ڡ�
�ڵ��Ŵ��ڵ��� 0 С�� n��
ͼ�п��ܴ����Ի���ƽ�бߡ�
*/

class Solution {
public:
        bool dfs(const vector<vector<int>>& table, vector<bool> &visited, int start, int target)
        {
        visited[start] = true;
        for (int i = 0; i < table[start].size(); i++)
        {
            if (!visited[table[start][i]])
            {
                // ���δ�����Ҹý�����target�򷵻�true. ���������ѯ
                if (table[start][i] == target)
                    return true;
                else if (dfs(table, visited, table[start][i], target))
                        return true;
            }
        }
        return false;
    }

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
    {
        if (start == target) return true;

        vector<bool> visited(n, false);
        vector<vector<int>> table(n);
        for (const auto &pair : graph)
        {
            int x1 = pair[0];
            int x2 = pair[1];
            if (x1 != x2)
                table[x1].emplace_back(x2);
        }
        return dfs(table, visited, start, target);
    }
};

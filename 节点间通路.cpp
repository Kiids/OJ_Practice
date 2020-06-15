/*
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。
示例1:
 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:
 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
提示：
节点数量n在[0, 1e5]范围内。
节点编号大于等于 0 小于 n。
图中可能存在自环和平行边。
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
                // 如果未访问且该结点就是target则返回true. 否则继续查询
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

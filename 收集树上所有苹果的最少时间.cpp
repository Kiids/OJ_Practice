/*
给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从 节点 0 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。
无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。
示例 1：
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
输出：8 
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 2：
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
输出：6
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 3：
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
输出：0
提示：
1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n
*/

class Solution {
    int DFS(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& hasApple, int node, int cost)
    {
        if (visited[node])
            return 0;
        visited[node] = true;

        // 计算子树的耗时并累加
        int nextCost = 0;
        for (int next : graph[node])
            // 一来一回增加2
            nextCost += DFS(graph, visited, hasApple, next, 2);
            
        // 如果子树都是0（表示没苹果）而且当前也没苹果，则返回0
        // 对于有苹果的根节点就是cost本身 返回的是2
        if (!hasApple[node] && nextCost == 0)
            return 0;
        return nextCost + cost;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : edges )
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return DFS(graph, visited, hasApple, 0, 0);
    }
};

/*
����һ���� n ���ڵ�����������ڵ���Ϊ 0 �� n-1 ����������һЩ�ڵ���ƻ����ͨ�����ϵ�һ���ߣ���Ҫ���� 1 ���ӡ���� �ڵ� 0 ���������㷵��������Ҫ�����룬�����ռ�������ƻ�������ص��ڵ� 0 ��
�������ı��� edges ���������� edges[i] = [fromi, toi] ����ʾ��һ�������� from �� toi ���������⣬����һ���������� hasApple ������ hasApple[i] = true ����ڵ� i ��һ��ƻ�������򣬽ڵ� i û��ƻ����
ʾ�� 1��
���룺n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
�����8 
���ͣ���ͼչʾ�˸������������к�ɫ�ڵ��ʾ��ƻ����һ�����ռ�������ƻ�������ŷ�������ɫ��ͷ��ʾ��
ʾ�� 2��
���룺n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
�����6
���ͣ���ͼչʾ�˸������������к�ɫ�ڵ��ʾ��ƻ����һ�����ռ�������ƻ�������ŷ�������ɫ��ͷ��ʾ��
ʾ�� 3��
���룺n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
�����0
��ʾ��
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

        // ���������ĺ�ʱ���ۼ�
        int nextCost = 0;
        for (int next : graph[node])
            // һ��һ������2
            nextCost += DFS(graph, visited, hasApple, next, 2);
            
        // �����������0����ʾûƻ�������ҵ�ǰҲûƻ�����򷵻�0
        // ������ƻ���ĸ��ڵ����cost���� ���ص���2
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

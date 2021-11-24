/*
在有向图中，以某个节点为起始节点，从该点出发，每一步沿着图中的一条有向边行走。如果到达的节点是终点（即它没有连出的有向边），则停止。
对于一个起始节点，如果从该节点出发，无论每一步选择沿哪条有向边行走，最后必然在有限步内到达终点，则将该起始节点称作是 安全 的。
返回一个由图中所有安全的起始节点组成的数组作为答案。答案数组中的元素应当按 升序 排列。
该有向图有 n 个节点，按 0 到 n - 1 编号，其中 n 是 graph 的节点数。图以下述形式给出：graph[i] 是编号 j 节点的一个列表，满足 (i, j) 是图的一条有向边。
示例 1：
输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
输出：[2,4,5,6]
解释：示意图如上。
示例 2：
输入：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
输出：[4]
提示：
n == graph.length
1 <= n <= 10^4
0 <= graph[i].length <= n
graph[i] 按严格递增顺序排列。
图中可能包含自环。
图中边的数目在范围 [1, 4 * 10^4] 内。
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> dev(n);              //记录出度
        vector<int> ret;                 //记录走死的点
        vector<vector<int>> from(n);     //记录所有的点从何而来
        for (int i = 0; i < n; i++)
        {
            dev[i] = graph[i].size();
            for (int num: graph[i])
                from[num].push_back(i);  //num点可以来自于i点
        }
        queue<int> que;                  //存储当前走死的点
        for (int i = 0; i < n; i++)
            if (dev[i] == 0)
                que.push(i);             //存入走死的点
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            ret.push_back(v);            //将走死的点放入答案,将入度为0的点放入队列
            for (int num: from[v])
                if(--dev[num] == 0)
                    que.push(num);       //所有到达此点的入度-1
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

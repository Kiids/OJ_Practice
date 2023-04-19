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
        vector<int> dev(n);              // 记录出度
        vector<int> ret;                 // 记录走死的点
        vector<vector<int>> from(n);     // 记录所有的点从何而来
        for(int i = 0; i < n; i++)
        {
            dev[i] = graph[i].size();
            for(int num: graph[i])
                from[num].push_back(i);  // num点可以来自于i点
        }
        queue<int> que;                  // 存储当前走死的点
        for(int i = 0; i < n; i++)
            if(dev[i] == 0)
                que.push(i);             // 存入走死的点
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            ret.push_back(v);            // 将走死的点放入答案,将入度为0的点放入队列
            for(int num: from[v])
                if(--dev[num] == 0)
                    que.push(num);       // 所有到达此点的入度-1
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
// 拓扑排序
// 一个点是否走死和它的出度有关，即如果一个点的出度为零，它无路可走，则它一定走死。
// 如果一个点所到达的都是出度为0的点，则这个点也一定会走死。
// 如果一个点到达的所有点都是走死的点，则这个点一定走死。
// 以上，则找出所有出度为0的点，并让所有到达此点的点出度-1，循坏往复，直至找出所有会走死的点


class Solution {
     vector<int> mark;
     bool DFS(int x, vector<vector<int>>& graph)
     {
        if (mark[x] > 0)        // 有标记，观察是走过还是安全点
            return mark[x] == 2;
        mark[x] = 1;            // 先标记为走过
        for (int& i: graph[x])  // 遍历下一个节点，观察是否会走过
            if (!DFS(i, graph))
                return false;
        mark[x] = 2;            // 下一节点不是走过状态，即是安全的
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        mark.resize(n);
        vector<int> v;
        for(int i = 0; i < n; i++)
            if(DFS(i, graph))
                v.push_back(i);
        return v;
    }
};
// DFS 三色标记法
// 三色标记法，代表每个点都有三种状态，第一个是未访问0，第二个是已访问1，第三个是安全状态2，
// 一开始每个点都是未访问，在访问过程中，如果遇到了访问过的点，那就代表着死循环，直接返回 false，
// 如果访问完成都到达终点（即没有遇到访问过的点），那么标记安全状态，返回 true


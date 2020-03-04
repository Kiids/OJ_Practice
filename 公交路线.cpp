/*
我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。
假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。
示例:
输入: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
输出: 2
解释: 
最优策略是先乘坐第一辆公交车到达车站 7, 然后换乘第二辆公交车到车站 6。
说明:
1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.
*/

class Solution {
public:
    unordered_set<int> haveVisitedCar, haveVisitedStop;
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        /*if (S == T)
            return 0;

        unordered_map<int, set<int>> m;
        queue<list<int>> que;
        vector<int> index(routes.size(), 0);
        int level = 1;
        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                int p = routes[i][j];
                m[p].insert(i);
                if (p == T)
                    index[i] = 1; 
            }
        }
        for (int i : m[S])
        {
            list<int> l{i};
            que.push(l);
        }
        while(!que.empty())
        {
            list<int>t_l = que.front();
            que.pop();
            if (index[t_l.back()] == 1)
                return t_l.size();
            index[t_l.back()] = -1;
            for (int i = 0; i < routes[t_l.back()].size(); i++)
            {
                for (int j : m[routes[t_l.back()][i]])
                {
                    if (index[j] != -1)
                    {
                        list<int> t = t_l;
                        t.push_back(j);
                        que.push(t);
                    }
                }
            }
        }
        return -1;*///此方法也通过了

        if (S == T)  // 已经在终点的特殊情况
            return 0;
        
        // 将vector<vector<int>>二维容器转换为vector<unordered_set<int>>容器，方便查找线路中是否含有某个车站
        vector<unordered_set<int>> myRoutes;
        for (auto &route : routes)
            myRoutes.push_back(unordered_set<int>(route.begin(), route.end()));
        
        int minStep = 1;  // 最少需要乘坐公交车数
        queue<int> myQue;  // 广度优先搜索辅助队列
        myQue.push(S);
        haveVisitedStop.insert(S);  // 标记站点已经访问
        while (!myQue.empty())
        {
            // 将当前队列中所有元素都寻找一个公交站
            for (int i = (int)myQue.size(); i > 0; i--)
            {
                int front = myQue.front();
                myQue.pop();
                unordered_set<int> canToSet; // front能够到达的站点
                findCar(myRoutes, front, canToSet);
                if (canToSet.count(T))  // 如果能知道到达T，说明已经找到了结果
                    return minStep;
                
                // 将未访问过的站点放入队列
                for (auto cit = canToSet.cbegin(); cit != canToSet.cend(); ++cit)
                {
                    if (haveVisitedStop.count(*cit) == 0)
                    {
                        myQue.push(*cit);
                        haveVisitedStop.insert(*cit);
                    }
                }
            }
            minStep += 1;
        }
        return -1;
    }
    // 搜索S能够到达的站点放入canToSet
    void findCar(vector<unordered_set<int>>& myRoutes, int S, unordered_set<int> &canToSet)
    {
        for (int index = (int)myRoutes.size() - 1; index >= 0; index--)
        {
            // 这条线路需要包括S，并且这条线路之前没有访问过
            if (myRoutes[index].count(S) && haveVisitedCar.count(index) == 0)
            {
                haveVisitedCar.insert(index);  // 标记当前访问
                canToSet.insert(myRoutes[index].begin(), myRoutes[index].end());
            }
        }
    }
};

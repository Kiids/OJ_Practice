/*
������һϵ�й���·�ߡ�ÿһ��·�� routes[i] �϶���һ��������������ѭ����ʻ�����磬��һ��·�� routes[0] = [1, 5, 7]����ʾ��һ�� (�±�Ϊ0) ��������һֱ���� 1->5->7->1->5->7->1->... �ĳ�վ·����ʻ��
�������Ǵ� S ��վ��ʼ����ʼʱ���ڹ������ϣ���Ҫȥ�� T վ�� �ڼ���ɳ�����������������ٳ����Ĺ��������������� -1 ��ʾ�����ܵ����յ㳵վ��
ʾ��:
����: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
���: 2
����: 
���Ų������ȳ�����һ�����������ﳵվ 7, Ȼ�󻻳˵ڶ�������������վ 6��
˵��:
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
        return -1;*///�˷���Ҳͨ����

        if (S == T)  // �Ѿ����յ���������
            return 0;
        
        // ��vector<vector<int>>��ά����ת��Ϊvector<unordered_set<int>>���������������·���Ƿ���ĳ����վ
        vector<unordered_set<int>> myRoutes;
        for (auto &route : routes)
            myRoutes.push_back(unordered_set<int>(route.begin(), route.end()));
        
        int minStep = 1;  // ������Ҫ������������
        queue<int> myQue;  // �������������������
        myQue.push(S);
        haveVisitedStop.insert(S);  // ���վ���Ѿ�����
        while (!myQue.empty())
        {
            // ����ǰ����������Ԫ�ض�Ѱ��һ������վ
            for (int i = (int)myQue.size(); i > 0; i--)
            {
                int front = myQue.front();
                myQue.pop();
                unordered_set<int> canToSet; // front�ܹ������վ��
                findCar(myRoutes, front, canToSet);
                if (canToSet.count(T))  // �����֪������T��˵���Ѿ��ҵ��˽��
                    return minStep;
                
                // ��δ���ʹ���վ��������
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
    // ����S�ܹ������վ�����canToSet
    void findCar(vector<unordered_set<int>>& myRoutes, int S, unordered_set<int> &canToSet)
    {
        for (int index = (int)myRoutes.size() - 1; index >= 0; index--)
        {
            // ������·��Ҫ����S������������·֮ǰû�з��ʹ�
            if (myRoutes[index].count(S) && haveVisitedCar.count(index) == 0)
            {
                haveVisitedCar.insert(index);  // ��ǵ�ǰ����
                canToSet.insert(myRoutes[index].begin(), myRoutes[index].end());
            }
        }
    }
};

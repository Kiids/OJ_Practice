/*
��˾���� n ��Ա����ÿ��Ա���� ID ���Ƕ�һ�޶��ģ���Ŵ� 0 �� n - 1����˾���ܸ�����ͨ�� headID ���б�ʶ��
�� manager �����У�ÿ��Ա������һ��ֱ�������ˣ����� manager[i] �ǵ� i ��Ա����ֱ�������ˡ������ܸ����ˣ�manager[headID] = -1����Ŀ��֤������ϵ���������ṹ��ʾ��
��˾�ܸ�������Ҫ��˾����Ա��ͨ��һ��������Ϣ������������֪ͨ����ֱ�������ǣ�Ȼ������Щ����֪ͨ���ǵ�������ֱ�����е�Ա������֪����������Ϣ��
�� i ��Ա����Ҫ informTime[i] ������֪ͨ��������ֱ��������Ҳ����˵�� informTime[i] ���Ӻ���������ֱ�����������Կ�ʼ������һ��Ϣ����
����֪ͨ����Ա����һ������Ϣ����Ҫ�� ������ ��
ʾ�� 1��
���룺n = 1, headID = 0, manager = [-1], informTime = [0]
�����0
���ͣ���˾�ܸ������Ǹù�˾��Ψһһ��Ա����
ʾ�� 2��
���룺n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
�����1
���ͣ�id = 2 ��Ա���ǹ�˾���ܸ����ˣ�Ҳ����������Ա����ֱ�������ˣ�����Ҫ 1 ������֪ͨ����Ա����
��ͼ��ʾ�˹�˾Ա�������ṹ��
��ʾ��
1 <= n <= 10^5
0 <= headID < n
manager.length == n
0 <= manager[i] < n
manager[headID] == -1
informTime.length == n
0 <= informTime[i] <= 1000
���Ա�� i û��������informTime[i] == 0 ��
��Ŀ ��֤ ����Ա���������յ�֪ͨ��
*/

class Solution {
    int ret = 0;
    unordered_map<int, vector<int>> m;
    void DFS(vector<int>& manager, vector<int>& informTime, int u, int t)
    {
        if (informTime[u] == 0)
        {
            ret = max(ret, t);
            return;
        }
        for (auto& e: m[u])
            DFS(manager, informTime, e, t + informTime[u]);
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                m[manager[i]].emplace_back(i);
        DFS(manager, informTime, headID, 0);
        return ret;
    }
};

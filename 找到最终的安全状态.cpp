/*
������ͼ�У���ĳ���ڵ�Ϊ��ʼ�ڵ㣬�Ӹõ������ÿһ������ͼ�е�һ����������ߡ��������Ľڵ����յ㣨����û������������ߣ�����ֹͣ��
����һ����ʼ�ڵ㣬����Ӹýڵ����������ÿһ��ѡ����������������ߣ�����Ȼ�����޲��ڵ����յ㣬�򽫸���ʼ�ڵ������ ��ȫ �ġ�
����һ����ͼ�����а�ȫ����ʼ�ڵ���ɵ�������Ϊ�𰸡��������е�Ԫ��Ӧ���� ���� ���С�
������ͼ�� n ���ڵ㣬�� 0 �� n - 1 ��ţ����� n �� graph �Ľڵ�����ͼ��������ʽ������graph[i] �Ǳ�� j �ڵ��һ���б����� (i, j) ��ͼ��һ������ߡ�
ʾ�� 1��
���룺graph = [[1,2],[2,3],[5],[0],[5],[],[]]
�����[2,4,5,6]
���ͣ�ʾ��ͼ���ϡ�
ʾ�� 2��
���룺graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
�����[4]
��ʾ��
n == graph.length
1 <= n <= 10^4
0 <= graph[i].length <= n
graph[i] ���ϸ����˳�����С�
ͼ�п��ܰ����Ի���
ͼ�бߵ���Ŀ�ڷ�Χ [1, 4 * 10^4] �ڡ�
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> dev(n);              // ��¼����
        vector<int> ret;                 // ��¼�����ĵ�
        vector<vector<int>> from(n);     // ��¼���еĵ�Ӻζ���
        for(int i = 0; i < n; i++)
        {
            dev[i] = graph[i].size();
            for(int num: graph[i])
                from[num].push_back(i);  // num�����������i��
        }
        queue<int> que;                  // �洢��ǰ�����ĵ�
        for(int i = 0; i < n; i++)
            if(dev[i] == 0)
                que.push(i);             // ���������ĵ�
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            ret.push_back(v);            // �������ĵ�����,�����Ϊ0�ĵ�������
            for(int num: from[v])
                if(--dev[num] == 0)
                    que.push(num);       // ���е���˵�����-1
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
// ��������
// һ�����Ƿ����������ĳ����йأ������һ����ĳ���Ϊ�㣬����·���ߣ�����һ��������
// ���һ����������Ķ��ǳ���Ϊ0�ĵ㣬�������Ҳһ����������
// ���һ���㵽������е㶼�������ĵ㣬�������һ��������
// ���ϣ����ҳ����г���Ϊ0�ĵ㣬�������е���˵�ĵ����-1��ѭ��������ֱ���ҳ����л������ĵ�


class Solution {
     vector<int> mark;
     bool DFS(int x, vector<vector<int>>& graph)
     {
        if (mark[x] > 0)        // �б�ǣ��۲����߹����ǰ�ȫ��
            return mark[x] == 2;
        mark[x] = 1;            // �ȱ��Ϊ�߹�
        for (int& i: graph[x])  // ������һ���ڵ㣬�۲��Ƿ���߹�
            if (!DFS(i, graph))
                return false;
        mark[x] = 2;            // ��һ�ڵ㲻���߹�״̬�����ǰ�ȫ��
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
// DFS ��ɫ��Ƿ�
// ��ɫ��Ƿ�������ÿ���㶼������״̬����һ����δ����0���ڶ������ѷ���1���������ǰ�ȫ״̬2��
// һ��ʼÿ���㶼��δ���ʣ��ڷ��ʹ����У���������˷��ʹ��ĵ㣬�Ǿʹ�������ѭ����ֱ�ӷ��� false��
// ���������ɶ������յ㣨��û���������ʹ��ĵ㣩����ô��ǰ�ȫ״̬������ true


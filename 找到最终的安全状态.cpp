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
        vector<int> dev(n);              //��¼����
        vector<int> ret;                 //��¼�����ĵ�
        vector<vector<int>> from(n);     //��¼���еĵ�Ӻζ���
        for (int i = 0; i < n; i++)
        {
            dev[i] = graph[i].size();
            for (int num: graph[i])
                from[num].push_back(i);  //num�����������i��
        }
        queue<int> que;                  //�洢��ǰ�����ĵ�
        for (int i = 0; i < n; i++)
            if (dev[i] == 0)
                que.push(i);             //���������ĵ�
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            ret.push_back(v);            //�������ĵ�����,�����Ϊ0�ĵ�������
            for (int num: from[v])
                if(--dev[num] == 0)
                    que.push(num);       //���е���˵�����-1
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

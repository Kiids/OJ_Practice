/*
���� n �������� m �����ˡ������������飺 difficulty, profit �� worker ������:
difficulty[i] ��ʾ�� i ���������Ѷȣ�profit[i] ��ʾ�� i �����������档
worker[i] �ǵ� i �����˵����������ù���ֻ������Ѷ�С�ڵ��� worker[i] �Ĺ�����
ÿ������ ��� ֻ�ܰ��� һ�� ����������һ���������� ��ɶ�� ��
�ٸ����ӣ���� 3 �����˶��������һ�ݱ���Ϊ $1 ��ͬ����������ô������Ϊ $3 �����һ�����˲�������κι�������������Ϊ $0 ��
���� �ڰѹ��˷��䵽������λ���������ܻ�õ�������� ��
ʾ�� 1��
����: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
���: 100 
����: ���˱�����Ĺ����Ѷ��� [4,4,6,6] ���ֱ��� [20,20,30,30] �����档
ʾ�� 2:
����: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
���: 0
��ʾ:
n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 10^4
1 <= difficulty[i], profit[i], worker[i] <= 10^5
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int i = 0, ret = 0, x = 0;
        for (int j = 0; j < worker.size(); j++)
        {
            while (i < n && v[i].first <= worker[j])
            {
                x = max(x, v[i].second);
                i++;
            }
            ret += x;
        }
        return ret;
    }
};

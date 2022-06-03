/*
��˾�ƻ����� 2n �ˡ�����һ������ costs ������ costs[i] = [aCosti, bCosti] ���� i �˷��� a �еķ���Ϊ aCosti ������ b �еķ���Ϊ bCosti ��
���ؽ�ÿ���˶��ɵ� a ��b ��ĳ�����е���ͷ��ã�Ҫ��ÿ�����ж��� n �˵ִ
ʾ�� 1��
���룺costs = [[10,20],[30,200],[400,50],[30,20]]
�����110
���ͣ�
��һ����ȥ a �У�����Ϊ 10��
�ڶ�����ȥ a �У�����Ϊ 30��
��������ȥ b �У�����Ϊ 50��
���ĸ���ȥ b �У�����Ϊ 20��
����ܷ���Ϊ 10 + 30 + 50 + 20 = 110��ÿ�����ж���һ����������ԡ�
ʾ�� 2��
���룺costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
�����1859
ʾ�� 3��
���룺costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
�����3086
��ʾ��
2 * n == costs.length
2 <= costs.length <= 100
costs.length Ϊż��
1 <= aCosti, bCosti <= 1000
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)->bool
        {
            return a[1]-a[0] < b[1]-b[0];
        });
        int ret = 0, n = costs.size(), n2= n/2;

        for (int i = 0; i < n2; i++)
            ret += costs[i][1];
            
        for (int i = n2; i < n; i++)
            ret += costs[i][0];

        return ret;
    }
};

/*
����һ���������� matches ���� matches[i] = [winneri, loseri] ��ʾ��һ�������� winneri ������ loseri ��
����һ������Ϊ 2 ���б� answer ��
answer[0] ������ û�� ����κα���������б�
answer[1] ������ǡ����� һ�� ����������б�
�����б��е�ֵ��Ӧ�ð� ���� ˳�򷵻ء�
ע�⣺
ֻ������Щ���� ����һ�� ��������ҡ�
���ɵĲ���������֤ ������ ����������� ��ͬ ��
ʾ�� 1��
���룺matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
�����[[1,2,10],[4,5,7,8]]
���ͣ�
��� 1��2 �� 10 ��û������κα�����
��� 4��5��7 �� 8 ÿ�������һ��������
��� 3��6 �� 9 ÿ�����������������
��ˣ�answer[0] = [1,2,10] �� answer[1] = [4,5,7,8] ��
ʾ�� 2��
���룺matches = [[2,3],[1,3],[5,4],[6,4]]
�����[[1,2,5,6],[]]
���ͣ�
��� 1��2��5 �� 6 ��û������κα�����
��� 3 �� 4 ÿ�����������������
��ˣ�answer[0] = [1,2,5,6] �� answer[1] = [] ��
��ʾ��
1 <= matches.length <= 10^5
matches[i].length == 2
1 <= winneri, loseri <= 10^5
winneri != loseri
���� matches[i] ������ͬ
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for (auto& e : matches)  // ��¼��Ӯ����
        {
            m[e[0]] = m[e[0]];
            m[e[1]]++;
        }
        vector<int> x, y;
        for (auto& [id, times] : m)
        {
            if (times == 0)
                x.push_back(id);
            else if (times == 1)
                y.push_back(id);
        }
        return {x, y};
    }
};

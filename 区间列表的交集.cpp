/*
����������һЩ ������ ��ɵ��б�firstList �� secondList ������ firstList[i] = [starti, endi] �� secondList[j] = [startj, endj] ��ÿ�������б��ǳɶ� ���ཻ �ģ����� �Ѿ����� ��
������ ���������б�Ľ��� ��
��ʽ�ϣ������� [a, b]������ a <= b����ʾʵ�� x �ļ��ϣ��� a <= x <= b ��
����������� ���� ��һ��ʵ����ҪôΪ�ռ���ҪôΪ�����䡣���磬[1, 3] �� [2, 4] �Ľ���Ϊ [2, 3] ��
ʾ�� 1��
���룺firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
�����[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
ʾ�� 2��
���룺firstList = [[1,3],[5,9]], secondList = []
�����[]
ʾ�� 3��
���룺firstList = [], secondList = [[4,8],[10,12]]
�����[]
ʾ�� 4��
���룺firstList = [[1,7]], secondList = [[3,10]]
�����[[3,7]]
��ʾ��
0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 10^9
endi < starti+1
0 <= startj < endj <= 10^9
endj < startj+1
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> v;
        int n1 = firstList.size(), n2 = secondList.size();
        if (n1 ==0 || n2 == 0)
            return v;
        int i = 0, j = 0; 
        while (i < n1 && j < n2)
        {
            int start = max(firstList[i][0], secondList[j][0]), end = min(firstList[i][1], secondList[j][1]);
            if (start <= end)
                v.push_back({start, end});
            firstList[i][1] < secondList[j][1] ? i++ : j++;
        }
        return v;
    }
};

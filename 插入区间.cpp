/*
����һ�� ���ص��� ������������ʼ�˵�����������б�
���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
ʾ�� 1��
���룺intervals = [[1,3],[6,9]], newInterval = [2,5]
�����[[1,5],[6,9]]
ʾ�� 2��
���룺intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
�����[[1,2],[3,10],[12,16]]
���ͣ�������Ϊ�µ����� [4,8] �� [3,5],[6,7],[8,10] �ص���
ʾ�� 3��
���룺intervals = [], newInterval = [5,7]
�����[[5,7]]
ʾ�� 4��
���룺intervals = [[1,5]], newInterval = [2,3]
�����[[1,5]]
ʾ�� 5��
���룺intervals = [[1,5]], newInterval = [2,7]
�����[[1,7]]
��ʾ��
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 10^5
intervals ���� intervals[i][0] �� ���� ����
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 10^5
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v; 
        int k = 0;
        while (k < intervals.size() && intervals[k][1] < newInterval[0])
            v.push_back(intervals[k++]);
        if (k < intervals.size())
        {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            while (k < intervals.size() && intervals[k][0] <= newInterval[1])
            {
                newInterval[1] = max(newInterval[1], intervals[k][1]);
                k++;
            }
        }
        v.push_back(newInterval);
        while (k < intervals.size())
            v.push_back(intervals[k++]);
        return v;
    }
};

/*
����һ�������б�����ɾ���б��б��������������ǵ����䡣
ֻ�е� c <= a �� b <= d ʱ�����ǲ���Ϊ���� [a,b) ������ [c,d) ���ǡ�
���������ɾ�����������㷵���б���ʣ���������Ŀ��
ʾ����
���룺intervals = [[1,4],[3,6],[2,8]]
�����2
���ͣ����� [3,6] ������ [2,8] ���ǣ���������ɾ���ˡ�
��ʾ��      
1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
�������е� i != j��intervals[i] != intervals[j]
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& l, const vector<int>& r) {
            if (l[0] == r[0])
                return l[1] > r[1];
            return l[0] < r[0];
        });

        int begin = intervals[0][0], end = intervals[0][1], x = 0;
        for (int i = 1; i < n; i++)
        {
            begin = intervals[i][0];
            if (intervals[i][1] <= end)
                x++;
            else
                end = intervals[i][1];
        }
        return n - x;
    }
};

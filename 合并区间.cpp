/*
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ��?2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
��ʾ��
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        for (int i = 0; i < intervals.size(); )
        {
            int t = intervals[i][1], j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t)
            {
                t = max(t, intervals[j][1]);
                j++;
            }
            v.push_back({ intervals[i][0], t });
            i = j;
        }
        return v;
    }
};

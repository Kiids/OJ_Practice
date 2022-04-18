/*
����һ���������� intervals ������ intervals[i] = [starti, endi] ����ÿ�� starti �� ��ͬ ��
���� i �� �Ҳ����� ���Լ������� j �������� startj >= endi ���� startj ��С�� ��
����һ����ÿ������ i �� �Ҳ����� ����С��ʼλ����ɵ����顣���ĳ������ i �����ڶ�Ӧ�� �Ҳ����� �����±� i ����ֵ��Ϊ -1 ��
ʾ�� 1��
���룺intervals = [[1,2]]
�����[-1]
���ͣ�������ֻ��һ�����䣬�������-1��
ʾ�� 2��
���룺intervals = [[3,4],[2,3],[1,2]]
�����[-1,0,1]
���ͣ����� [3,4] ��û�����������ġ��Ҳࡱ���䡣
���� [2,3] ������[3,4]������С�ġ��ҡ����;
���� [1,2] ������[2,3]������С�ġ��ҡ���㡣
ʾ�� 3��
���룺intervals = [[1,4],[2,3],[3,4]]
�����[-1,2,-1]
���ͣ��������� [1,4] �� [3,4] ��û�����������ġ��Ҳࡱ���䡣
���� [2,3] ������ [3,4] ����С�ġ��ҡ���㡣
��ʾ��
1 <= intervals.length <= 2 * 10^4
intervals[i].length == 2
-10^6 <= starti <= endi <= 10^6
ÿ���������㶼 ����ͬ
*/

class Solution {
    int findFirstBig(vector<pair<int, int>>& v, int num) {
        int left = 0, right = v.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (v[mid].first >= num)
                right = mid;
            else
                left = mid + 1;
        }
        if (left == v.size())
            return -1;
        return v[left].second;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for (int i = 0; i < intervals.size(); i++)
            v.emplace_back(make_pair(intervals[i][0], i));
        sort(v.begin(), v.end());
        vector<int> ret;
        for (int i = 0; i < intervals.size(); i++)
            ret.push_back(findFirstBig(v, intervals[i][1]));
        return ret;
    }
};

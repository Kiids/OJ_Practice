/*
����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
ע��:
������Ϊ������յ����Ǵ���������㡣
���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
ʾ�� 1:
����: [ [1,2], [2,3], [3,4], [1,3] ]
���: 1
����: �Ƴ� [1,3] ��ʣ�µ�����û���ص���
ʾ�� 2:
����: [ [1,2], [1,2], [1,2] ]
���: 2
����: ����Ҫ�Ƴ����� [1,2] ��ʹʣ�µ�����û���ص���
ʾ�� 3:
����: [ [1,2], [2,3] ]
���: 0
����: �㲻��Ҫ�Ƴ��κ����䣬��Ϊ�����Ѿ������ص����ˡ�
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int ret = 0, pre = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= pre)
                pre = intervals[i][1];
            else
                ret += 1;
        }
        return ret;
    }
};

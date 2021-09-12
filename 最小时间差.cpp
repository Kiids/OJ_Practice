/*
����һ�� 24 Сʱ�ƣ�Сʱ:���� "HH:MM"����ʱ���б��ҳ��б�����������ʱ�����Сʱ���Է�������ʾ��
ʾ�� 1��
���룺timePoints = ["23:59","00:00"]
�����1
ʾ�� 2��
���룺timePoints = ["00:00","23:59","00:00"]
�����0
��ʾ��
2 <= timePoints <= 2 * 104
timePoints[i] ��ʽΪ "HH:MM"
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (string t : timePoints)
        {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            int x = h * 60 + m;
            v.push_back(x);
            v.push_back(x + 1440);
        }
        sort(v.begin(), v.end());
        int ret = INT_MAX;
        for (int i = 1; i < v.size(); i ++)
        {
            int x = v[i - 1];
            int y = v[i];
            ret = min(ret, y - x);
        }
        return ret;
    }
};

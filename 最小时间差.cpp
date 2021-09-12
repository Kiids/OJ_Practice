/*
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
示例 1：
输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：
输入：timePoints = ["00:00","23:59","00:00"]
输出：0
提示：
2 <= timePoints <= 2 * 104
timePoints[i] 格式为 "HH:MM"
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

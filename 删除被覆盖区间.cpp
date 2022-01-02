/*
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
在完成所有删除操作后，请你返回列表中剩余区间的数目。
示例：
输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
提示：      
1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j]
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

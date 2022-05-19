/*
给定在 xy 平面上的一组点，确定由这些点组成的矩形的最小面积，其中矩形的边平行于 x 轴和 y 轴。
如果没有任何矩形，就返回 0。
示例 1：
输入：[[1,1],[1,3],[3,1],[3,3],[2,2]]
输出：4
示例 2：
输入：[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
输出：2
提示：
1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
所有的点都是不同的。
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> s;
        for (vector<int>& point: points)
            s.emplace(40001 * point[0] + point[1]);

        int len = points.size(), ret = INT_MAX;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
                    if (s.count(points[i][0] * 40001 + points[j][1]) && s.count(points[j][0] * 40001 + points[i][1]))
                        ret = min(ret, abs(points[j][1] - points[i][1]) * abs(points[j][0] - points[i][0]));

        return ret < INT_MAX ? ret: 0;
    }
};

//先确定两个点作为对角线，然后去找另外两个点是否存在，存在则可以快速计算面积
//快速查找方式: 预先按照点去构建去存储到set里，考虑到范围，用一个数字就可以保存了


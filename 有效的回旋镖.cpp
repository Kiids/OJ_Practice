/*
回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。
示例 1：
输入：[[1,1],[2,3],[3,2]]
输出：true
示例 2：
输入：[[1,1],[2,2],[3,3]]
输出：false
提示：
points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //斜率公式变形 (x3-x2)(y2-y1) = (x2-x1)(y3-y2)
        return (points[2][0] - points[1][0]) * (points[1][1] - points[0][1]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};

/*
给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。
一个 有效的正方形 有四条等边和四个等角(90度角)。
示例 1:
输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
示例 2:
输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
输出：false
示例 3:
输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
输出：true
提示:
p1.length == p2.length == p3.length == p4.length == 2
-10^4 <= xi, yi <= 10^4
*/

class Solution {
    int getLen(vector<int>& x, vector<int>& y)
    {
        return pow(y[0] - x[0], 2) + pow(y[1] - x[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> lens;
        lens.resize(6, 0);
        lens[0] = getLen(p1, p2);
        lens[1] = getLen(p1, p3);
        lens[2] = getLen(p1, p4);
        lens[3] = getLen(p2, p4);
        lens[4] = getLen(p2, p3);
        lens[5] = getLen(p3, p4);
        set<int> s;
        for (int i = 0; i < 6; i++)
        {
            if (lens[i] == 0)
                return false;
            s.insert(lens[i]);
        }
        return s.size() == 2 ? true : false;
    }
};

//计算所有点到其他点的长度
//正方形四条边，两条对角线，边和边相等，对角线和对角线相等，这是充要条件
//放入set进行判断，如果是正方形，那么set只有两个有效数据


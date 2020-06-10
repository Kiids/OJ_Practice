/*
一只蚂蚁坐在由白色和黑色方格构成的无限网格上。开始时，网格全白，蚂蚁面向右侧。每行走一步，蚂蚁执行以下操作。
(1) 如果在白色方格上，则翻转方格的颜色，向右(顺时针)转 90 度，并向前移动一个单位。
(2) 如果在黑色方格上，则翻转方格的颜色，向左(逆时针方向)转 90 度，并向前移动一个单位。
编写程序来模拟蚂蚁执行的前 K 个动作，并返回最终的网格。
网格由数组表示，每个元素是一个字符串，代表网格中的一行，黑色方格由?'X'?表示，白色方格由?'_'?表示，蚂蚁所在的位置由?'L', 'U', 'R', 'D'?表示，分别表示蚂蚁?左、上、右、下 的朝向。只需要返回能够包含蚂蚁走过的所有方格的最小矩形。
示例 1:
输入: 0
输出: ["R"]
示例 2:
输入: 2
输出:
[
? "_X",
? "LX"
]
示例 3:
输入: 5
输出:
[
? "_U",
? "X_",
? "XX"
]
说明：
K <= 100000
*/

class Solution {
public:
    vector<string> printKMoves(int K) {
        // 数组模拟
        if (!K)
            return {"R"};
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 左上右下
        string directions = "LURD";
        deque<deque<char>> map;
        map.push_back(deque<char>(1, '_')); // 初始化

        int i = 0, j = 0, d = 2; // 0-4: 左上右下
        int col = 1;
        while (K --)
        {
            if (map[i][j] == '_')
            { // 翻转，改变方向
                map[i][j] = 'X';
                d = (d + 1) % 4;
            }
            else if (map[i][j] == 'X')
            { // 翻转，改变方向
                map[i][j] = '_';
                d = (d + 3) % 4;
            }

            i += dx[d], j += dy[d]; // 前进

            // 更新地图
            // 增加行
            if (i > (int)map.size() - 1)
                map.push_back(deque<char>(col, '_'));
            else if (i < 0)
                map.push_front(deque<char>(col, '_')), i ++;

            // 增加列
            if (j > col - 1)
            { // 后面增加一列
                for (auto& x: map) x.push_back('_');
                col ++;
            }
            else if (j < 0)
            { // 前面增加一列
                for (auto& x: map) x.push_front('_');
                j ++, col ++;
            }
        }
        map[i][j] = directions[d]; // 置最终到达单位

        // 收集数据
        vector<string> res;
        for (int i = 0; i < map.size(); i ++)
        {
            string ans = "";
            for (auto c: map[i])
                ans += c;
            res.push_back(ans);
        }
        return res;
    }
};

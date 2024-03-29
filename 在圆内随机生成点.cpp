/*
给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。
实现 Solution 类:
Solution(double radius, double x_center, double y_center) 用圆的半径 radius 和圆心的位置 (x_center, y_center) 初始化对象
randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。
示例 1：
输入: 
["Solution","randPoint","randPoint","randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
解释:
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint ();//返回[-0.02493，-0.38077]
solution.randPoint ();//返回[0.82314,0.38945]
solution.randPoint ();//返回[0.36572,0.17248]
提示：
0 < radius <= 10^8
-10^7 <= x_center, y_center <= 10^7
randPoint 最多被调用 3 * 10^4 次
*/

class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        while(true)
        {   //初始值为正方形的左下角 + 随机值，RAND_MAX 是 <stdlib.h> 中伪随机数生成函数 rand 所能返回的最大数值 
            double randx = x - r + (double(rand()) / RAND_MAX * r) * 2;
            double randy = y - r + (double(rand()) / RAND_MAX * r) * 2;
            double dis = sqrt((randx - x) * (randx - x) + (randy - y) * (randy - y));
            if (dis <= r)
                return {randx, randy};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

// randx,randy 为随机之后的点，初始位置是(x-r, y-r)，对应正方形的左下角，
// 随机值区间是(0, 2r),正方形的采样区间，然后进行距离判断，在圆内则返回，不在则继续随机

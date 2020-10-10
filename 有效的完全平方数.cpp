/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如? sqrt。
示例 1：
输入：16
输出：True
示例 2：
输入：14
输出：False
*/

// 从1开始n个奇数的和是一个完全平方数 
class Solution {
public:
    bool isPerfectSquare(int num) {
        int ret = 1;
        while (num > 0) 
        {
            num -= ret;
            ret += 2;
        }
        return num == 0;
    }
};

/*
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动将会使 n - 1 个元素增加 1。
示例:
输入:
[1,2,3]
输出:
3
解释:
只需要3次移动（注意每次移动会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        for (int n : nums)
            minNum = min(n, minNum);

        int ret = 0;
        for (int n : nums)
            ret += n - minNum;
        return ret;
    }
};
//题目要求每次选择N-1个数加一
//相当于 =〉所有数字加1 然后挑一个数字减1
//相当于 =〉数字不变（都加一等于大家相对而言都不变），挑一个数字减1
//相当于 =〉把所有数字变成最小数的次数 就是让所有数字相等的次数

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
示例 1：
输入：n = 2
输出：2
示例 2：
输入：n = 7
输出：21
提示：
0 <= n <= 100
*/

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum = 1;
        for (int i = 1; i < n; i++)
        {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};

// 以下方法 超出时间限制 最后执行的输入：43 
class Solution {
public:
    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;
        return numWays(n - 1) + numWays(n - 2);
    }
};

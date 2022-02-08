/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
示例 1：
输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：
输入：n = 1
输出：1
解释：1 通常被视为丑数。
提示：
1 <= n <= 1690
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        long ret = 1;
        priority_queue<long, vector<long>, greater<long>> q;
        for (int i = 1; i < n; i++)
        {
            q.push(ret * 2);
            q.push(ret * 3);
            q.push(ret * 5);

            ret = q.top();
            q.pop();

            while (q.top() == ret)
                q.pop();
        }
        return ret;
    }
};

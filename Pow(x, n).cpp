/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n ）。
示例 1：
输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：
输入：x = 2.10000, n = 3
输出：9.26100
示例 3：
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
提示：
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= xn <= 10^4
*/

class Solution {
    double fun(double x, long long n)
    {
        if(n == 0)
            return 1.0;
        double y = fun(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? fun(x, N) : 1.0 / fun(x, - N);
    }
};

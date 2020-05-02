/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
示例 1：
输入：n = 12
输出：5
示例 2：
输入：n = 13
输出：6
限制：
1 <= n < 2^31
*/

//从最低位开始遍历
//每一位1出现的次数分三种情况
class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        long i = 1;
        while (i <= n)
        {
            int t = (n / i) % 10;  // 取出当前位数字 
            if (t == 0)
                ret += n / (i *10) * i;
            else if (t == 1)
                ret += (n / (i * 10)) * i + n % i + 1;
            else
                ret += (n / (i * 10) + 1) * i;
            i *= 10;
        }
        return ret;
    }
};

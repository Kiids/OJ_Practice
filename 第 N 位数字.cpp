/*
给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。
示例 1：
输入：n = 3
输出：3
示例 2：
输入：n = 11
输出：0
解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
提示：
1 <= n <= 2^31 - 1
*/

class Solution {
public:
    int findNthDigit(int n) {
        long long N = n;
        int digits = 1; // 位数 
        long long border = 9; // digits位数一共产生多少位数字 

        while (N)
        {
            if (N <= border * digits)
                break; // 循环退出时即找到了当前数字的位数
            N -= border * digits; // N 为扣掉所有digits位数字（比如2位数）产生的数字之后还剩多少个数字
            digits++;
            border *= 10;
        }
        // 循环结束后 剩余的N都是由 digits位数 贡献的
        // 每个 digits位数 都产生了 digits个数字； 因而我们求除求余就可以知道n对应的是第几个digits位数
        int offset = (N - 1) / digits;
        int begin = 1; // 用于计算最小的 digits位数
        for (int i = 0; i < digits - 1; i++)
            begin *= 10;
        int mod = (N - 1) % digits;
        string target = to_string(offset + begin);
        return target[mod] - '0';
    }
};


class Solution {
public:
    int findNthDigit(long n) {
        int k = 1;
        while (k * pow(10, k) < n)
		{
            n += pow(10, k);
            k += 1;
        }
        return to_string(n / k)[n % k] - '0';
    }
};

// 通过补0每个数字字符宽度都补成当前位数k, 那么返回第 n/k 个数 的 第 n%k 位即可, 前面补0后n要右移对应的长度
// k为3时，数字序列为 000 001 002 003 004 005 006 007 008 009 010 011...
// 前面补多少位，要寻找的n向右移多少位，即n += 10 ** k



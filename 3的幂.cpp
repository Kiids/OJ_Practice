/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。
示例 1:
输入: 27
输出: true
示例 2:
输入: 0
输出: false
示例 3:
输入: 9
输出: true
示例 4:
输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) 
            return false;
        while (n % 3 == 0)
            n = n / 3;
        return n == 1;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;  //1162261467为int型范围内最大的3的幂
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
    if (n <= 0)
		return false;
    double a = log10(n) / log10(3);  //换底公式 
    return  a == floor(a);           //判断换底后的log3n是否为整数，即n是否为3的倍数
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        int a = 1;  //a不断乘3，看是否与n相等
        while (n >= a)
        {
            if (a == n)
				return true; 
            if (a >= INT_MAX / 3)
				return false;
            a *= 3;
        }
        return false;
    }
};

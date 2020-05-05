/*
编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。
示例：
输入： a = 1, b = 2
输出： 2
*/

class Solution {
public:
    int maximum(int a, int b) {
        return (((long)a + (long)b) + abs((long)a - (long)b)) / 2;
    }
};

// 二进制
class Solution {
public:
    int maximum(int a, int b) {
        long k = (((long)a - (long)b) >> 63) & 1;
        return b * k + a * (k ^ 1);
    }
};
//long或者是int类型符号位都是在第一位上的，long类型右移63位就可以拿到符号位。
//其中有一点，正数右移高位补0，但是负数右移高位补1。
//如果a-b<0，那么a-b符号位为1，k得到1.
//否则a-b>0，那么a-b符号位为0。此时k的值为0.

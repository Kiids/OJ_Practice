/*
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
示例 1:
输入: 16
输出: true
示例 2:
输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0)
            return false;
        int t = num & (-num);
        if (num - t != 0)
            return false;
        return num % 3 == 1;
    }
};
// 先判断是不是只有一位是1，然后看模3的结果。如果模3为1，则true，如果模3为2则false

// 循环
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num  && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};

// 位运算
// 4的次方数一定是2的次方数，但2的次方数不一定是4的次方数，通
// 过4的次方数二进制可以发现4的次方数二进制中1只出现在奇数位。
// 因此可以通过于奇数位都是1，偶数为都是0的数（1010101010101010101010101010101）进行与运算，结果仍为原来数。
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};

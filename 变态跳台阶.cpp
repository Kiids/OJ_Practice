// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << (number - 1);
    }
};

// 动态规划 
// 状态F(i)：跳上i级台阶的方法数
// 转移方程：F(i) = F(i - 1) + F(I - 2) + ... F(0)   式1
//                F(i - 1) = F(i - 2) + ..... F(0)  式2
//                F(i) = F(i - 1) + F(i - 1)  式2带入式1求得
// 初始状态：F(1) = 1
// 返回值：F(n)

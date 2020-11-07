/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
示例:
输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

class Solution {
public:
    int addDigits(int num) {
        while (num / 10 != 0)
        {
            int sum = 0;
            while (num != 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        //将余数范围扩充到0~9
        return (num-1) % 9 + 1;
    }
};

//    2位数
//    num = a * 10 + b
//    num1 = a + b
//    num - num1 = 9 * a;
//    缩小了a 个9
//    3位数
//    num = a * 100 + b * 10 + c
//    num1 = a + b + c
//    num - num1 = 99 * a + 9 * b
//    缩小了(11 * a + b) * 9
//    开始到结果相差9的倍数
//    所以开始数据对9取模剩下的就是我们想要的结果

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)    
            return 0;
        return num % 9 ? num % 9 : 9;   //到9的时候就不能再计算了 所以余数为0为9
    }
};

/*
设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
示例:
输入: a = 1, b = 1
输出: 2
提示：
a, b 均可能是负数或 0
结果不会溢出 32 位整数
*/

class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        if (a == 0)
            return b;
        
        int t1 = 0, t2 = 0, t3 = 0;
        while (b != 0)
        {
        	t1 = a ^ b;
	        t2 = a & b;
	        t3 = (unsigned int)t2 << 1;
	        a = t1;
	        b = t3;
		}
        return t1;
    }
};

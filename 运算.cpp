/*
请实现整数数字的乘法、减法和除法运算，运算结果均为整数数字，程序中只允许使用加法运算符和逻辑运算符，允许程序中出现正负常数，不允许使用位运算。
你的实现应该支持如下操作：
Operations() 构造函数
minus(a, b) 减法，返回a - b
multiply(a, b) 乘法，返回a * b
divide(a, b) 除法，返回a / b
示例：
Operations operations = new Operations();
operations.minus(1, 2); //返回-1
operations.multiply(3, 4); //返回12
operations.divide(5, -2); //返回-2
提示：
你可以假设函数输入一定是有效的，例如不会出现除法分母为0的情况
单个用例的函数调用次数不会超过1000次
*/

class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
        return a + (-b);
    }
    
    int multiply(int a, int b) {
        // -2^31, -1;
        if (a == 0 || b == 0)
            return 0;
        if (a == 1)
            return b;
        if (b == 1)
            return a;
        if (a == -1)
            return -b;
        if (b == -1) 
        return -a;

        int cnt = 0;
        if (a < 0)
            cnt = cnt + 1, a = -a;
        if (b < 0)
            cnt = cnt + 1, b = -b;
        if (a > b)
            swap(a, b);

        vector<int> tmp, count;
        long t = b;
        int k = 1;
        while (t <= INT_MAX) tmp.push_back(t), count.push_back(k), t = t + t, k = k + k;
        
        int res = 0;
        for (int i = tmp.size() - 1; i >= 0; i = minus(i, 1)) {
            while (a >= count[i]) a = minus(a, count[i]), res = res + tmp[i];
        }

        if (cnt == 1) return -res;
        return res;
    }
    
    int divide(int a, int b) {
        if (a == 0 || b == 0) return 0;
        if (b == INT_MAX || b == INT_MIN) return 0;
        if (b == 1) return a; 
        if (b == -1) return -a;

        // 符号位
        int cnt = 0;
        if (a < 0) cnt = cnt + 1, a = -a;
        if (b < 0) cnt = cnt + 1, b = -b;
        if (a < b) return 0;

        vector<int> tmp, count;
        long t = b;
        int k = 1;
        while (a >= t)
            tmp.push_back(t), count.push_back(k), t = t + t, k = k + k;
        
        int res = 0;
        for (int i = tmp.size() - 1; i >= 0; i = minus(i, 1))
            while (a >= tmp[i]) a = minus(a, tmp[i]), res = res + count[i];

        if (cnt == 1)
            return -res;
        return res;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */

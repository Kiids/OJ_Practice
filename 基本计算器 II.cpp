/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。
你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。
注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
示例 1：
输入：s = "3+2*2"
输出：7
示例 2：
输入：s = " 3/2 "
输出：1
示例 3：
输入：s = " 3+5 / 2 "
输出：5
提示：
1 <= s.length <= 3 * 10^5
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
题目数据保证答案是一个 32-bit 整数
*/

class Solution {
    stack<int> num;  //存数字
    stack<char> op;  //存操作
    void eval() 
    {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        char c = op.top();
        op.pop();
        int r;
        if (c == '+')
            r = a + b;
        else if (c == '-')
            r = a - b;
        else if (c == '*')
            r = a * b;
        else
            r = a / b;
        num.push(r);
    }
public:
    int calculate(string s) {
        s = '0' + s;  // 开头是负数的处理 
        unordered_map<char, int> m; 
        m['+'] = m['-'] = 1, m['*'] = m['/'] = 2;  //定义运算符的优先级
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i]; 
            if (c == ' ')
                continue;  //跳过空格
            if (isdigit(c))  //c是数字,读取一个连续的数字
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                num.push(x);    //加入数字栈中
                i = j - 1;        
            }
            else  //c是操作符 
            {     //op栈非空并且栈顶操作符优先级大于等于当前操作符c的优先级，进行eval()计算
                while (op.size() && m[op.top()] >= m[c])
                    eval(); 
                op.push(c);
            }
        }
        while (op.size())
            eval(); 
        return num.top();
    }
};

/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：
实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。
示例 1：
输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2：
输入：num1 = "1+-1i", num2 = "1+-1i"
输出："0+-2i"
解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
提示：
num1 和 num2 都是有效的复数表示。
*/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 = stoi(num1), b1 = stoi(num2), i = 0, j = 0;
        while (num1[i] != '+')
            i++;
        while (num2[j] != '+')
            j++;
        num1 = num1.substr(i + 1), num2 = num2.substr(j + 1);
        int a2 = stoi(num1), b2 = stoi(num2);
        string x = to_string(a1 * b1 - a2 * b2);
        string y = to_string(a1 * b2 + a2 * b1);
        return x + "+" + y + "i";
    }
};

// 将两个复数进行分割，分割完成之后按照复数运算法则进行计算

// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// 示例 1:
// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:
// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：
// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        
        for (int i = 0; i < n1; ++i) 
            for (int j = 0; j < n2; ++j)  // 按位相乘并保存
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
        
        for (int i = 0; i < n1 + n2; ++i)  // 进位处理
        {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        
        int i = n1 + n2 - 1;
        while (v[i] == 0) 
            --i;
        if (i < 0) 
            return "0";
        while (i >= 0) 
            res.push_back(v[i--] + '0');
        
        return res;
    }
};


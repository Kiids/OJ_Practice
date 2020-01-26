// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
// 注意：
// num1 和num2 的长度都小于 5100.
// num1 和num2 都只包含数字 0-9.
// num1 和num2 都不包含任何前导零。
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

class Solution {
public:
    string addStrings(string num1, string num2) {
        int L = num1.size();
        int R = num2.size();
        
        if (L < R)
        {
            num1.swap(num2);
            swap(L, R);
        }
        string ret;
        ret.reserve(L+1);
        char cRet = 0;
        char cstep = 0;
        for (size_t i = 0; i < L; ++i)
        {
            cRet = num1[L - i - 1] - '0' + cstep;
            cstep = 0;
            if(i < R)
            {
                cRet += num2[R - i - 1] - '0';
            }
            if(cRet >= 10)
            {
                cRet -= 10;
                cstep = 1;
            }
            ret += cRet + '0';
        }
        if(cstep)
            ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


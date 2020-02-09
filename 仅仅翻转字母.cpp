/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
示例 1：
输入："ab-cd"
输出："dc-ba"
示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
提示：
S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S == "" || S.size() <= 1)
            return S;

        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            while (i < j && !isLetters(S[i]))
                i++;
            while (i < j && !isLetters(S[j]))
                j--;
            if (i < j)
            {
                char t = S[i];
                S[i] = S[j];
                S[j] = t;
                i++;
                j--;
            }
        }
        return S;
    }
    bool isLetters(char c)
    {
        if (c >= 'a' && c <= 'z')
            return true;
        else if (c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    }
};

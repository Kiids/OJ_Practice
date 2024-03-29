/*
给定两个整数 a 和 b ，返回 任意 字符串 s ，要求满足：
s 的长度为 a + b，且正好包含a 个 'a' 字母与 b 个 'b' 字母；
子串 'aaa' 没有出现在 s 中；
子串 'bbb' 没有出现在 s 中。
示例 1：
输入：a = 1, b = 2
输出："abb"
解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：
输入：a = 4, b = 1
输出："aabaa"
提示：
0 <= a, b <= 100
对于给定的 a 和 b，保证存在满足要求的 s 
*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        while (a > 0 || b > 0)
        {
            bool isA = false;
            int len = s.size();
            if (len >= 2 && s[len - 1] == s[len - 2])
                isA = s[len - 1] == 'b';
            else
                isA = a >= b;
            s += isA ? "a" : "b";
            a -= isA;
            b -= !isA;
        }
        return s;
    }
};

//优先把字符串更长的填充
//连续出现两个一样的用另外一个

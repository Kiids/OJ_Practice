/*
给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"
提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        string ret;
        for (int i = 0; i < n - 1; i++)
        {
            if (i + 1 < n && s[i + 1] == s[i])  // 当回文串偶数长度
            {
                int l = i, r = i + 1;
                while (l >= 0 && r < n)
                {
                    if (s[l] != s[r])           // 回文终止
                        break;
                    r++;
					l--;
                }
                if (r - l - 1 > ret.size())
                    ret = s.substr(l + 1, r - l - 1);
            }
            if (i > 0 && s[i - 1] == s[i + 1])  // 当回文串奇数长度
            {
                int l = i - 1, r = i + 1;
                while (l >= 0 && r < n)
                {
                    if (s[l] != s[r])           // 回文终止
                        break;
                    r++;
                    l--;
                }
                if (r - l - 1 > ret.size())
                    ret = s.substr(l + 1, r - l - 1);
            }
        }
        return ret.size() == 0 ? ret + s[0] : ret;
    }
};

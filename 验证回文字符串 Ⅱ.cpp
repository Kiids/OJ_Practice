/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
输入: "aba"
输出: True
示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 0)
            return true;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
                l++, r--;
            else
                return isValid(s, l + 1, r) || isValid(s, l, r - 1);
        }
        return true;
    }

    bool isValid(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] == s[r])
                l++, r--;
            else
                return false;
        }
        return true;
    }
};

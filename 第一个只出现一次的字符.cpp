/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
示例:
s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
限制：
0 <= s 的长度 <= 50000
*/

class Solution {
public:
    char firstUniqChar(string s) {
        /*if (s.size() <= 1)
            return (char)s.c_str();*/

        int hash[256] = {0};
        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1)
            {
                return s[i];
            }
        }

        return ' ';
    }
};

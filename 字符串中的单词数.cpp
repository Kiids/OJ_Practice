/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。
示例:
输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
*/

class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int cnt = 0;
        if (len == 0)
            return 0;
        for (int i = 1; i < len; i++)
            if (s[i] == ' ' && s[i - 1] != ' ')
                cnt++;
        if (s[len - 1] != ' ')
            cnt++;
        return cnt;
    }
};
